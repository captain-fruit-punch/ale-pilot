#include "Servo.h"
// #include "TinyGPS++.h"

// servos and turning
Servo res; // servo right elevator
int srep = 10; // servo right elevator pin
double recp = 0; // right elevator current position

Servo les; // servo left elevator
int slep = 9; // servo left elevator pin
double lecp = 0;// left elevator current position

int restpos = 90;

void setup() {
  res.attach(srep);
  les.attach(slep);
  res.write(90); // reset to position 0
  les.write(90); // reset to position 0
}

void loop() {
  testsurfaces(500);
}

void testsurfaces(int delaytime) {
  int max = 180;
  int min = 0;
  // test right
  res.write(min);
  delay(delaytime);
  res.write(max);
  delay(delaytime);
  res.write(restpos);
  // test left
  les.write(min);
  delay(delaytime);
  les.write(max);
  delay(delaytime);
  les.write(restpos);
  // test both
  res.write(min);
  les.write(min);
  delay(delaytime);
  res.write(max);
  les.write(max);
  delay(delaytime);
  res.write(restpos);
  les.write(restpos);
  // test inverse both
  res.write(min);
  les.write(max);
  delay(delaytime);
  res.write(max);
  les.write(min);
  delay(delaytime);
  res.write(restpos);
  les.write(restpos);
}

void quickrise(int incline, float risetime) { // incline from rest, time in seconds
  int intensity = incline + restpos;
  int settime = 500; // the time of the incline elevator in ms
  res.write(intensity);
  les.write(intensity);
  delay(settime);
  res.write(restpos);
  les.write(restpos);
  delay(risetime * 1000);
  res.write(intensity - (2 * incline));
  les.write(intensity - (2 * incline));
  delay(settime);
  res.write(restpos);
  les.write(restpos);
}

void quickglide()
