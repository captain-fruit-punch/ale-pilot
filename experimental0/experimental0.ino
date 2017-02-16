#include "Servo.h"
// #include "TinyGPS++.h"

// servos and turning
Servo ras; // servo right aleron
int srap = 10; // servo right aleron pin
int srarp = 90; // servo right aleron rest position

Servo las; // servo left aleron
int slap = 9; // servo left aleron pin
int slarp = 90; // servo left aleron rest position

Servo es; // servo elevator
int sep = 11; // servo elevator pin
int serp = 90; // servo elevator rest position

Servo mt; // motor throtle
int mp = 12; // motor pin

void setup() {
  // attah all servos
  ras.attach(srap);
  las.attach(slap);
  se.attach(sep);
  mt.attach(mp);
  // reset everything
  ras.write(srarp); // reset to rest
  las.write(slarp); // reset to rest
  se.write(serp); // reset to rest
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
  ras.write(srarp);
  // test left
  las.write(min);
  delay(delaytime);
  las.write(max);
  delay(delaytime);
  las.write(slarp);
  // test elevator
  es.write(min);
  delay(delaytime);
  es.write(max);
  delay(delaytime);
  es.write(serp);
  // test both
  ras.write(min);
  las.write(min);
  es.write(min);
  delay(delaytime);
  ras.write(max);
  las.write(max);
  es.write(max);
  delay(delaytime);
  ras.write(srarp);
  las.write(slarp);
  es.write(serp);
  // test inverse both
  ras.write(min);
  las.write(max);
  es.write(max);
  delay(delaytime);
  ras.write(max);
  las.write(min);
  es.write(min);
  delay(delaytime);
  ras.write(srarp);
  las.write(slarp);
  es.write(serp);
}

void quickrise(float incline, float risetime, int speed, float intensity) { // incline from rast, time in seconds
  int settime = 500; // the time of the incline elevator in ms
  mt.write(speed);
  ras.write(incline + srarp);
  las.write(incline + slarp);
  sep.write(intensity + serp);
  delay(settime);
  ras.write(srarp);
  las.write(slarp);
  es.write(serp);
  delay(risetime * 1000);
  ras.write(srarp - incline);
  las.write(slarp - incline);
  es.write(serp - intensity)
  delay(settime);
  ras.write(srarp);
  las.write(slarp);
  es.write(serp);
}

void quickglide() {

}
