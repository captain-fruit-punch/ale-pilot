#include <Servo.h>

float mpd = 111319.9 // meters per degree
float adrpd

// servos and turning
Servo res; // servo right elevator
int srep = // servo right elevator pin
float recp = 0 // right elevator current position

Servo les; // servo left elevator
int slep = // servo left elevator pin
float lecp = 0 // left elevator current position

// sensor and status
float ch = 0 // current heading, taken from degree counts from north towards east
float te = 0 // target elevation, done in meters
float ce = 0 // current elevation, done in meters

// gps
float rgx = 0 // raw gps x position
float rgy = 0 // raw gps x position

float ugx = 0 // updated gps x position
float ugy = 0 // updated gps y position

float tgx = 0 // target gps x position
float tgy = 0 // target gps y position

// constants
const float mtd = 100 // mild turn degree
const float mspd = 10 // miliseconds per degree
const float td = 10 // turn time (degree)
const float rd = 90 // rest degree

void setup() {
	res.attach(srep);
	les.attach(slep);
}

void loop() {

}

void correctgps() {
	if (rgx )
}

void distancetot() { // distance to target

}

void mildturn(direction, th) { // true is right, false as left; target heading
	float dh = ch - th;
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
