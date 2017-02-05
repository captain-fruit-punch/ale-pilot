#include "Servo.h"
#include "TinyGPS++.h"

// servos and turning
Servo res; // servo right elevator
int srep = 10; // servo right elevator pin
double recp = 0; // right elevator current position

Servo les; // servo left elevator
int slep = 9; // servo left elevator pin
double lecp = 0;// left elevator current position

// sensor and status
double ch = 0; // current heading, taken from degree counts from north towards east
double te = 0; // target elevation, done in meters
double ce = 0; // current elevation, done in meters
double cs = 0; // current speed done in meters per second

// gps
TinyGPSPlus gps; // gps parser object
double rgx = 0; // raw gps x position
double rgy = 0; // raw gps x position

double ugx = 0; // updated gps x position
double ugy = 0; // updated gps y position

double lgx = 0; // last gps x position
double lgy = 0; // last gps y position

double tgx = 0; // target gps x position
double tgy = 0; // target gps y position

// constants
double mtd = 100; // mild turn degree
double mspd = 10; // miliseconds per degree
double td = 10; // turn time (degree)
double rd = 90; // rest degree
double mpd = 111319.9; // meters per degree
double gem = 1; // gps error margin in meters
double dtr = 0.0174533; // degrees to radians
double tsd = 10; // target stop distance (when the autopilot disengages)

void setup() {
	res.attach(srep);
	les.attach(slep);
	Serial.begin(9600);
}

void loop() {
	if (Serial.available()) {
		gps.encode(Serial.read());
		correctgps();
	}
	if (distancetot() > tsd) {
		double htt = atan2(abs(tgx - ugx), abs(tgy - ugy)) / dtr; // heading towards target
		double dh = ch - htt;
		if (dh > 0) {
			mildturn(true, dh);
		}
		else {
			mildturn(false, abs(dh));
		}
	}
}

void correctgps() {
	lgx = ugx; // set last gps location
	lgy = ugy;
	rgx = gps.location.lng();
	rgy = gps.location.lat();
	cs = gps.speed.mps();
	double rrmgx = rgx * mpd; // current relative raw x position in meters
	double rrmgy = rgy * mpd; // current relative raw y position in meters
	double rlmgx = lgx * mpd; // last relative x position in meters
	double rlmgy = lgy * mpd; // last relative y position in meters
	double dmgx = abs(rrmgx - rlmgx); // delta relative change x in meters
	double dmgy = abs(rrmgy - rlmgx); // delta relative change y in meters
	if (dmgx > cs + gem) { // if the delta change exceeds probable speed, assume
		if (ch < 90){ // if it's below 90˚, edit north and east (both positive)
			ugx += (sin(ch * dtr) * cs) / mpd;
			ugy += (cos(ch * dtr) * cs) / mpd;
		}
		else if (ch < 180) { // if it's above 90˚ but below 180˚ subtract from north and add to east
			ugx += (cos((ch - 90) * dtr) * cs) / mpd;
			ugy -= (sin((ch - 90) * dtr) * cs) / mpd;
		}
		else if (ch < 270) { // if it's above 180˚ but below 270˚ subtract from north and east
			ugy -= (sin((ch - 180) * dtr) * cs) / mpd;
			ugx -= (cos((ch - 180) * dtr) * cs) / mpd;
		}
		else { // if it's above 270˚ the add to north and subtract from east
			ugy += (sin((ch - 270) * dtr) * cs) / mpd;
			ugx -= (cos((ch - 270) * dtr) * cs) / mpd;
		}
	}
}

double distancetot() { // distance to target
	return sqrt(sq(abs(ugx - tgx)) + sq(abs(ugy - tgy)));
}

void mildturn(bool direction, float th) { // true is right, false as left; target heading
	double dh = ch - th;
	if (direction) { // begin turn with swiveling
		res.write(mtd);
		les.write(90-(mtd-90));
	}
	if (!direction) {
		res.write(90-(mtd-90));
		les.write(mtd);
	}
	delay(mspd * td); // wait for swivel
	res.write(mtd); // begin turn
	res.write(mtd);
	delay(dh * (th-ch)); // wait for turn
	if (direction) { // unswivel
		res.write(90-(mtd-90));
		les.write(mtd);
	}
	if (!direction) {
		res.write(mtd);
		les.write(90-(mtd-90));
	}
	delay(mspd * td); // wait for unswivel
	res.write(rd); // return to neutral
	les.write(rd);
}

void checkforcommands() {
	String sm = Serial.readString();
	if (sm = "mtd") {
		Serial.println("enter in a new value for mild turn degree");
		while(!Serial.available());
		mtd = Serial.parseFloat();
	}
	if (sm = "td") {
		Serial.println("enter in a new value for turn time per degree");
		while(!Serial.available());
		td = Serial.parseFloat();
	}
}

void sensorupdate() {
}
