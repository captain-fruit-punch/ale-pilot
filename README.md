# Autoplane
Plane autopilot built to run on an atmega328 microcontroller.

## Parts
Currently, it's planned to run on a GP-20U7 GPS receiver module, a LSM9DS1 from a 9DoF sensor stick, and a BMP180 barometric pressure sensor all attached to a Arduino Pro Mini.
The planned plane body is an Alpha from Flite Test, with a Sunnysky 2300kv 2204 (motor size) powered by an Afro ESC 12A (salvaged from an old tricopter i made). (this is totally up for change)
Since I obviously have to test the plane before I fly it, I'll be using a OrangeRX receiver running off of the DSM2 protocol.
I'm currently planning on having a HC-12 wireless transceiver to transmit the data between the controller and the plane, though this might change

## Functionality
Currently at the time of me writing this, this is the functionality it has.
- GPS correction
- (i think it's functional) turning
- Target seeking

## Todo
- Takeoff
- Landing
- Kill-switch
- Wireless variable update over Serial
- FPV?

## Sensors
- Barometric pressure
- GPS position
- Accelerometer
- Magnetometer
- Gyroscope
