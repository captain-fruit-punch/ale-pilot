#include <Servo.h>

float mpd = 111319.9 // meters per degree
float adrpd

float rgx = 0 // raw gps x position
float rgy = 0 // raw gps x position

float ugx = 0 // updated gps x position
float ugy = 0 // updated gps y position

float igx = 0 // intended gps x position
float igy = 0 // intended gps y position

Servo res; // servo right elevator
int srep = // servo right elevator pin
float recp = 0 // right elevator current position
float reg = 0 // right elevator gain
float reip = 0 // right elevator intended position

Servo le; // servo left elevator
int slep = // servo left elevator pin
float lecp = 0 // left elevator current position
float leg = 0 // left elevator gain
float leip = 0 // left elevator intended position

float ih = 0 // intended heading, taken from degree counts from north towards east
float ie = 0 // intended elevation, done in meters

float ce = 0 // current elevation, done in meters


void setup() {
	res.attach(srep);
	les.attach(slep);
}

void loop() {

}

void correctgps() {

}

void distanceto() {

}

turn function

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
