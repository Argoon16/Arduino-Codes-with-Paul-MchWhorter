//We are Controlling a DC Motor Speed, Direction, and On and Off Power using a Remote Control
//Including Libraries
#include <IRremote.h>

//Declaring Variables
int IR_PIN = 9;
int DELAY = 500;
int SPEED_PIN = 5;
int CLOCKWISE_PIN = 4;
int COUNTERCLOCKWISE_PIN = 3;
int SPEED;
int CLOCKWISE_STATE;
int COUNTERCLOCKWISE_STATE;

String MY_CMD;
String SPEED_MESSAGE = "The speed of the motor is: ";
String DIRECTION_MESSAGE = "The direction of the motor is: ";
String DIRECTION;
String COMMA = ", ";

//We have to create the IR object
IRrecv IR(IR_PIN);
//We need to decode the results
//This command comes from the library
//We are going to name this "CMD" which means Command
decode_results CMD;


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //We need to enable the module
  IR.enableIRIn();

  //Starting Motor Pins
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(CLOCKWISE_PIN, OUTPUT);
  pinMode(COUNTERCLOCKWISE_PIN, OUTPUT);

  //Setting Initial Speed
  SPEED = 255;
}


void loop() {
  //We are sitting and waiting for data
  //We are going to decode the data from the module
  while (IR.decode(&CMD) == 0) {
  }

  //We are reading the data as a hexadecimal
  Serial.println(CMD.value, HEX);
  delay(DELAY);

  //We need the module to start reading again
  IR.resume();


  //If we press the Power button...
  if (CMD.value == 0xFFA25D) {
    MY_CMD = "Power_On";
    Serial.println(MY_CMD);
  }

  //If we press the Volume_Up button...
  if (CMD.value == 0xFF629D) {
    MY_CMD = "Speed_Up";
    Serial.println(MY_CMD);
  }

  //If we press the Volume_Down button...
  if (CMD.value == 0xFFA857) {
    MY_CMD = "Speed_Down";
    Serial.println(MY_CMD);
  }

  //If we press the Stop button...
  if (CMD.value == 0xFFE21D) {
    MY_CMD = "Power_Off";
    Serial.println(MY_CMD);
  }

  //If we press the Rewind button...
  if (CMD.value == 0xFF22DD) {
    MY_CMD = "Clockwise";
    Serial.println(MY_CMD);
  }

  //If we press the Fast_Forward button...
  if (CMD.value == 0xFFC23D) {
    MY_CMD = "Counterclockwise";
    Serial.println(MY_CMD);
  }

  //Increasing Speed every time speed up button is pressed
  if (MY_CMD == "Speed_Up") {
    SPEED = SPEED + 10;
    analogWrite(SPEED_PIN, SPEED);
  }

  //Decreasing Speed every time speed down button is pressed
  if (MY_CMD == "Speed_Down") {
    SPEED = SPEED - 10;
    analogWrite(SPEED_PIN, SPEED);
  }

  //Creating Max speed value
  if (SPEED > 255) {
    SPEED = 255;
    analogWrite(SPEED_PIN, SPEED);
  }

  //Creating Min speed value
  if (SPEED < 170) {
    SPEED = 170;
    analogWrite(SPEED_PIN, SPEED);
  }

  //We have to limit the speed value to proper values so speed does not get messed up values
  //We need it to be multiples of 10 since we are increasing and deccreasing by 10 every time the button is pressed
  if (SPEED == 245) {
    SPEED = 250;
    analogWrite(SPEED_PIN, SPEED);
  }


  //Making direction clockwise when fast forward button is pressed
  if (MY_CMD == "Clockwise") {
    digitalWrite(CLOCKWISE_PIN, HIGH);
    digitalWrite(COUNTERCLOCKWISE_PIN, LOW);
    analogWrite(SPEED_PIN, SPEED);
    CLOCKWISE_STATE = HIGH;
    COUNTERCLOCKWISE_STATE = LOW;
    DIRECTION = "CLOCKWISE";
  }


  //Making direction counterclockwise when rewind button is pressed
  if (MY_CMD == "Counterclockwise") {
    digitalWrite(CLOCKWISE_PIN, LOW);
    digitalWrite(COUNTERCLOCKWISE_PIN, HIGH);
    analogWrite(SPEED_PIN, SPEED);
    CLOCKWISE_STATE = LOW;
    COUNTERCLOCKWISE_STATE = HIGH;
    DIRECTION = "COUNTERCLOCKWISE";
  }


  //When the power on button is pressed motor turns on
  if (MY_CMD == "Power_On") {
    digitalWrite(CLOCKWISE_PIN, CLOCKWISE_STATE);
    digitalWrite(COUNTERCLOCKWISE_PIN, COUNTERCLOCKWISE_STATE);
    analogWrite(SPEED_PIN, SPEED);
  }


  //When the power off button is pressed motor turns off
  if (MY_CMD == "Power_Off") {
    digitalWrite(CLOCKWISE_PIN, LOW);
    digitalWrite(COUNTERCLOCKWISE_PIN, LOW);
    analogWrite(SPEED_PIN, SPEED);
  }


  //Printing Values
  Serial.print(SPEED_MESSAGE);
  Serial.print(SPEED);
  Serial.print(COMMA);
  Serial.print(DIRECTION_MESSAGE);
  Serial.println(DIRECTION);
}
