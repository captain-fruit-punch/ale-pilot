#include "Servo.h"
// #include "TinyGPS++.h"

// servos and turning
Servo ras; // servo right aleron
int srap = 10; // servo right elevator pin

Servo las; // servo left aleron
int slap = 9; // servo left elevator pin

Servo es; // servo elevator
int sep = 11; // servo elevator pin

Servo mt; // motor throtle
int mp = 12; // motor pin

int restpos = 90;

void setup() {
  // attah all servos
  ras.attach(srap);
  las.attach(slap);
  se.attach(sep);
  mt.attach(mp);
  // reset everything
  ras.write(restpos); // reset to rest
  las.write(restpos); // reset to rest
  se.write(restpos); // reset to rest
  mt.write(0); // motor rest
  // test
  testsurfaces(500, 110, 70);
}

void loop() {
}

void testsurfaces(int delaytime, int max, int min) {
  // test right
  ras.write(min);
  delay(delaytime);
  ras.write(max);
  delay(delaytime);
  ras.write(restpos);
  // test left
  las.write(min);
  delay(delaytime);
  las.write(max);
  delay(delaytime);
  las.write(restpos);
  // test elevator
  es.write(min);
  delay(delaytime);
  es.write(max);
  delay(delaytime);
  es.write(restpos);
  // test both
  ras.write(min);
  las.write(min);
  es.write(min);
  delay(delaytime);
  ras.write(max);
  las.write(max);
  es.write(max);
  delay(delaytime);
  ras.write(restpos);
  las.write(restpos);
  es.write(restpos);
  // test inverse both
  ras.write(min);
  las.write(max);
  es.write(max);
  delay(delaytime);
  ras.write(max);
  las.write(min);
  es.write(min);
  delay(delaytime);
  ras.write(restpos);
  las.write(restpos);
  es.write(restpos);
}

void quickrise(int incline, float risetime) { // incline from rast, time in seconds
  int intensity = incline + restpos;
  int settime = 500; // the time of the incline elevator in ms
  ras.write(intensity);
  las.write(intensity);
  delay(settime);
  ras.write(restpos);
  las.write(restpos);
  delay(risetime * 1000);
  ras.write(intensity - (2 * incline));
  las.write(intensity - (2 * incline));
  delay(settime);
  ras.write(restpos);
  las.write(restpos);
}

void quickglide()
