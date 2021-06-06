//We are turning a servomotor using a joystick
//Setting up Libraries
#include <Servo.h>

//Declaring Variables
int X_PIN = A0;
int X_VAL;
String X_MESSAGE = "The x value is: ";
String SERVO_MESSAGE = "The Servo is at: ";
String COMMA = ", ";
float X_VOLTAGE;
float ANGLE;
int SERVO_PIN = 3;
//Giving Servo a Variable
Servo SERVO;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
  //Starting Pins
  pinMode(X_PIN, INPUT);
  SERVO.attach(SERVO_PIN);
}

void loop() {
  //Reading Voltage of X_PIN
  X_VAL = analogRead(X_PIN);
  //Converting to actual Voltage
  X_VOLTAGE = (5. / 1023.) * X_VAL;

  //Setting up Servo Angle
  ANGLE = 36 * X_VOLTAGE;
  //Turning servo accoridng to voltage
  SERVO.write(ANGLE);

  //Printing Messages
  Serial.print(X_MESSAGE);
  Serial.print(X_VOLTAGE);
  Serial.print(COMMA);
  Serial.print(SERVO_MESSAGE);
  Serial.println(ANGLE);
}
