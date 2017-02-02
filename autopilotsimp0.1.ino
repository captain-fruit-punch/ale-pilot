#include "Servo.h"
#include "TinyGPS++.h"

// servos and turning
Servo res; // servo right elevator
int srep = // servo right elevator pin
double recp = 0 // right elevator current position

Servo les; // servo left elevator
int slep = // servo left elevator pin
double lecp = 0 // left elevator current position

// sensor and status
double ch = 0 // current heading, taken from degree counts from north towards east
double te = 0 // target elevation, done in meters
double ce = 0 // current elevation, done in meters
double cs = 0 // current speed done in meters per second

// gps
TinyGPSPlus gps; // gps parser object
double rgx = 0 // raw gps x position
double rgy = 0 // raw gps x position

double ugx = 0 // updated gps x position
double ugy = 0 // updated gps y position

double lgx = 0 // last gps x position
double lgy = 0 // last gps y position

double tgx = 0 // target gps x position
double tgy = 0 // target gps y position

// constants
const double mtd = 100 // mild turn degree
const double mspd = 10 // miliseconds per degree
const double td = 10 // turn time (degree)
const double rd = 90 // rest degree
double mpd = 111319.9 // meters per degree
double adrpd

void setup() {
	res.attach(srep);
	les.attach(slep);
	Serial.begin(9600);
}

void loop() {
	if (Serial.available()) {
		gps.encode(Serial.read());
		lgx = ugx; // set last gps location
		lgy = ugy;
		rgx = gps.location.lng();
		rgy = gps.location.lat();
		cs = gps.speed.mps();
		correctgps();
	}
}

void correctgps() {
	double rrmgx = rgx * mpd; // current relative raw x position in meters
	double rrmgy = rgy * mpd; // current relative raw y position in meters
	double rlmgx = lgx * mpd; // last relative x position in meters
	double rlmgy = lgy * mpd; // last relative y position in meters
	double rdmgx = abs(rrmgx - rlmgx);
	double rdmgy = abs(rrmgy - rlmgx);
}

void distancetot() { // distance to target

}

void mildturn(direction, th) { // true is right, false as left; target heading
	double dh = ch - th;
	if (direction) { // begin turn with swiveling
		res.write(mtd);
		les.write(90-(mtd-90));
	}
	if (!direction) {
		res.write(90-(mtd-90);
		les.write(mtd));
	}
	delay(mspd * td); // wait for swivel
	res.write(mtd); // begin turn
	res.write(mtd);
	delay(dh * (th-ch)); // wait for turn
	if (direction) { // unswivel
		res.write(90-(mtd-90);
		les.write(mtd));
	}
	if (!direction) {
		res.write(mtd);
		les.write(90-(mtd-90));
	}
	delay(mspd * td); // wait for unswivel
	res.write(rd); // return to neutral
	les.write(rd);
}

// right
void updatere() {
	if (recp > reip) {
		recp = recp - (reg / reip);
	}
	else if (recp < reip) {
		recp = recp + (reg / reip);
	}
}

void powerres() {
	res.write(recp);
}

// left
void updatele() {
	if (lecp > leip) {
		lecp = lecp - (leg / leip);
	}
	else if (lecp < leip) {
		lecp = lecp + (leg / leip);
	}
}

void powerles() {
	les.write(lecp);
}
