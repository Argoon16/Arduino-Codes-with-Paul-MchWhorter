//We are making a stepper motor work
//Loading Library
#include <Stepper.h>

//Declaring Variables
int SPEED = 10;
int DELAY = 500;

//Revolution refers to a full 360 degree turn
//A step is a portion of a revolution
//With 2048 steps, we can obtain one full revolution
int STEPS_PER_REVOLUTION = 2048;

//We need to tell the arduino how many steps are in a full revolution
//We also need to tell the arduino the pin sequence
//This pin sequence works because of the way the driver and stepper motor works, and the way we circuit the wires
//The pin sequence may change if the circuit is different, or there is a different driver or motor
//Always figure this out
Stepper STEPPER(STEPS_PER_REVOLUTION, 8, 10, 9, 11);


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Telling Stepper Motor how Fast we want it to go
  STEPPER.setSpeed(SPEED);
}


void loop() {
  //Making the stepper motor make a full ravolution in the clockwise direction
  STEPPER.step(STEPS_PER_REVOLUTION);
  delay(DELAY);
  //Making the stepper motor make a full ravolution in the counterclockwise direction
  STEPPER.step(-STEPS_PER_REVOLUTION);
  delay(DELAY);
}
