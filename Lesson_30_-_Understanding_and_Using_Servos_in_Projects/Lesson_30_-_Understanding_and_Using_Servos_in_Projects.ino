//We are Learning how to use a servo
//We need to load a library to work with the servo
//Starting Libraries
#include <Servo.h>

//Declaring Variables
int SERVO_PIN = 11;
int SERVO_POSITION;
String MESSAGE = "What Angle for the Servo? ";

//Giving the servo a variable
Servo MY_SERVO;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
  
  //Starting Servo Pin
  MY_SERVO.attach(SERVO_PIN);
}

void loop() {
  //Printing Message
  Serial.println(MESSAGE);
  
  //Waiting for user input
  while(Serial.available() == 0){
    
  }
  
  //Storing user input in server position variable
  SERVO_POSITION = Serial.parseInt();
  
  //Turning Required Servo Position from user
  MY_SERVO.write(SERVO_POSITION);
}
