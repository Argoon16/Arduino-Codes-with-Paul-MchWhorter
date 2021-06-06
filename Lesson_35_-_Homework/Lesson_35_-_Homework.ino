//We are making a stepper motor turn without stopping and then reversing its rotation after pushing a button
//Staring Library
#include <Stepper.h>

//Declaring Variables
int BUTTON_PIN = 7;
int BUTTON_NEW;
int STEPS_PER_REVOLUTION = 2048;
int SPEED = 10;
int STEP = 1;
int BUTTON_OLD;

//Setting up stepper motor
Stepper STEPPER(STEPS_PER_REVOLUTION, 8, 10, 9, 11);


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Reading Button Value
  pinMode(BUTTON_PIN, INPUT);

  //Starting Button
  digitalWrite(BUTTON_PIN, HIGH);

  //Giving Stepper Motor a Speed
  STEPPER.setSpeed(SPEED);
}


void loop() {
  //Reading Button Value
  BUTTON_NEW = digitalRead(BUTTON_PIN);

  //Starting the Rotation of the Stepper Motor
  STEPPER.step(STEP);

  //Setting up if statement to execute when the button is pushed down
  if (BUTTON_OLD == 0 && BUTTON_NEW == 1) {
    //Reversing the Direction of the spin
      STEP = STEP * (-1);
  }

  //In order for the if statement to execute, button old must hold button new's value
  //When the program restarts, and if we push the button, button old will be 0, and button new will be 1
  BUTTON_OLD = BUTTON_NEW;
}
