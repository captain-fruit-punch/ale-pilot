#include "Servo.h"
// #include "TinyGPS++.h"

// servos and turning
Servo res; // servo right elevator
int srep = 10; // servo right elevator pin
double recp = 0; // right elevator current position

Servo les; // servo left elevator
int slep = 9; // servo left elevator pin
double lecp = 0;// left elevator current position

int rest = 90;

void setup() {
  res.attach(srep);
  les.attach(slep);
  res.write(90); // reset to position 0
  les.write(90); // reset to position 0
}

void loop() {
  testsurfaces(100);
}

void testsurfaces(int delaytime) {
  int max = 180;
  int min = 0;
  // test right
  res.write(min);
  delay(delaytime);
  res.write(max);
  delay(delaytime);
  res.write(rest);
  // test left
  les.write(min);
  delay(delaytime);
  les.write(max);
  delay(delaytime);
  les.write(rest);
  // test both
  res.write(min);
  les.write(min);
  delay(delaytime);
  res.write(max);
  les.write(max);
  delay(delaytime);
  res.write(rest);
  les.write(rest);
  // test inverse both
  res.write(min);
  les.write(max);
  delay(delaytime);
  res.write(max);
  les.write(min);
  delay(delaytime);
  res.write(rest);
  les.write(rest);
}

void quickglide(int altitude) {
  
}
