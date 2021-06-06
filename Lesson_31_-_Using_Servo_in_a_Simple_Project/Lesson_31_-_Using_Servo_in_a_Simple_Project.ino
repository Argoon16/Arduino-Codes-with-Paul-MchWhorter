//We are making the servo angle change in accordance to the light level

//Starting Servo Library
#include <Servo.h>

//Declaring Variables
int SERVO_PIN = 11;
int PHOTORESISTOR_PIN = A5;
float ANGLE;
int LIGHT_READ;
float LIGHT_VALUE;
String LIGHT_MESSAGE = "The Light Level is: ";
String ANGLE_MESSAGE = "The Angle is: ";
String COMMA = ", ";
Servo SERVO;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Servo Pin
  SERVO.attach(SERVO_PIN);
}

void loop() {
  //Reading Light Value
  LIGHT_READ = analogRead(PHOTORESISTOR_PIN);

  //Converting analog read voltage to actual voltage
  LIGHT_VALUE = (5. / 1023.) * LIGHT_READ;

  //Angle is based off of the light value
  //Creating equation
  ANGLE = 150. * LIGHT_VALUE;
  
  //Constraining maximum Value
  if (ANGLE > 180) {
    ANGLE = 180;
  }

  //Constraining minimum Value
  if (ANGLE < 0) {
    ANGLE = 0;
  }
  
  //Rotating Servo
  SERVO.write(ANGLE);
  
  //Printing Messages
  Serial.print(LIGHT_MESSAGE);
  Serial.print(LIGHT_VALUE);
  Serial.print(COMMA);
  Serial.print(ANGLE_MESSAGE);
  Serial.println(ANGLE);
}
