//We are Controlling an RGB LED using an IR Remote Control
//Including Libraries
#include <IRremote.h>

//Declaring Variables
int IR_PIN = 9;
int DELAY = 1500;
int BLUE_PIN = 6;
int GREEN_PIN = 5;
int RED_PIN = 10;
int BLUE_BRIGHTNESS;
int RED_BRIGHTNESS;
int GREEN_BRIGHTNESS;

String BLUE_MESSAGE = "Blue: ";
String GREEN_MESSAGE = "Green: ";
String RED_MESSAGE = "Red: ";
String MY_CMD;
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

  //Starting RBG LED Pins
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  //Setting up initial Brightness Values
  BLUE_BRIGHTNESS = 0;
  RED_BRIGHTNESS = 0;
  GREEN_BRIGHTNESS = 0;
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

  //If we press the 0 button...
  if (CMD.value == 0xFF6897) {
    MY_CMD = "White";
    Serial.println(MY_CMD);
  }

  //If we press the 1 button...
  if (CMD.value == 0xFF30CF) {
    MY_CMD = "Red_Increase";
    Serial.println(MY_CMD);
  }

  //If we press the 2 button...
  if (CMD.value == 0xFF18E7) {
    MY_CMD = "Green_Increase";
    Serial.println(MY_CMD);
  }

  //If we press the 3 button...
  if (CMD.value == 0xFF7A85) {
    MY_CMD = "Blue_Increase";
    Serial.println(MY_CMD);
  }

  //If we press the 4 button...
  if (CMD.value == 0xFF10EF) {
    MY_CMD = "Red";
    Serial.println(MY_CMD);
  }

  //If we press the 5 button...
  if (CMD.value == 0xFF38C7) {
    MY_CMD = "Green";
    Serial.println(MY_CMD);
  }

  //If we press the 6 button...
  if (CMD.value == 0xFF5AA5) {
    MY_CMD = "Blue";
    Serial.println(MY_CMD);
  }

  //If we press the 7 button...
  if (CMD.value == 0xFF42BD) {
    MY_CMD = "Red_Decrease";
    Serial.println(MY_CMD);
  }

  //If we press the 8 button...
  if (CMD.value == 0xFF4AB5) {
    MY_CMD = "Green_Decrease";
    Serial.println(MY_CMD);
  }

  //If we press the 9 button...
  if (CMD.value == 0xFF52AD) {
    MY_CMD = "Blue_Decrease";
    Serial.println(MY_CMD);
  }

  //If we press the Power button...
  if (CMD.value == 0xFFA25D) {
    MY_CMD = "On";
    Serial.println(MY_CMD);
  }

  //If we press the Stop button...
  if (CMD.value == 0xFFE21D) {
    MY_CMD = "Off";
    Serial.println(MY_CMD);
  }


  //If we press the Up button...
  if (CMD.value == 0xFF906F) {
    MY_CMD = "Brightness_Up";
    Serial.println(MY_CMD);
  }

  //If we press the Down button...
  if (CMD.value == 0xFFE01F) {
    MY_CMD = "Brightness_Down";
    Serial.println(MY_CMD);
  }


  //Increasing Brightness of everything
  if (MY_CMD == "Brightness_Up") {
    RED_BRIGHTNESS = RED_BRIGHTNESS + 20;
    GREEN_BRIGHTNESS = GREEN_BRIGHTNESS + 20;
    BLUE_BRIGHTNESS = BLUE_BRIGHTNESS + 20;
  }

  //Increasing Brightness of Red
  if (MY_CMD == "Red_Increase") {
    RED_BRIGHTNESS = RED_BRIGHTNESS + 20;
  }

  //Increasing Brightness of Blue
  if (MY_CMD == "Blue_Increase") {
    BLUE_BRIGHTNESS = BLUE_BRIGHTNESS + 20;
  }

  //Increasing Brightness of Green
  if (MY_CMD == "Green_Increase") {
    GREEN_BRIGHTNESS = GREEN_BRIGHTNESS + 20;
  }


  //Decreasing Brightness of everything
  if (MY_CMD == "Brightness_Down") {
    RED_BRIGHTNESS = RED_BRIGHTNESS - 20;
    GREEN_BRIGHTNESS = GREEN_BRIGHTNESS - 20;
    BLUE_BRIGHTNESS = BLUE_BRIGHTNESS - 20;
  }

  //Decreasing Brightness of Red
  if (MY_CMD == "Red_Decrease") {
    RED_BRIGHTNESS = RED_BRIGHTNESS - 20;
  }

  //Decreasing Brightness of Blue
  if (MY_CMD == "Blue_Decrease") {
    BLUE_BRIGHTNESS = BLUE_BRIGHTNESS - 20;
  }

  //Decreasing Brightness of Green
  if (MY_CMD == "Green_Decrease") {
    GREEN_BRIGHTNESS = GREEN_BRIGHTNESS - 20;
  }


  //Setting Maximum red Brightness Value
  if (RED_BRIGHTNESS > 255) {
    RED_BRIGHTNESS = 255;
  }

  //Setting Maximum Blue Brightness Value
  if (BLUE_BRIGHTNESS > 255) {
    BLUE_BRIGHTNESS = 255;
  }

  //Setting Maximum Green Brightness Value
  if (GREEN_BRIGHTNESS > 255) {
    GREEN_BRIGHTNESS = 255;
  }


  //Setting Minimum Red Brightness Value
  if (RED_BRIGHTNESS < 0) {
    RED_BRIGHTNESS = 0;
  }

  //Setting Minimum Green Brightness Value
  if (GREEN_BRIGHTNESS < 0) {
    GREEN_BRIGHTNESS = 0;
  }

  //Setting Minimum Red Brightness Value
  if (BLUE_BRIGHTNESS < 0) {
    BLUE_BRIGHTNESS = 0;
  }


  //Making Red Value Proper to Work With so we always get the same values when increasing and decreasing Brightness
  //Must be a multiple of 20 and close to 255
  if (RED_BRIGHTNESS == 235) {
    RED_BRIGHTNESS = 240;
  }

  //Making Blue Value Proper to Work With so we always get the same values when increasing and decreasing Brightness
  //Must be a multiple of 20 and close to 255
  if (BLUE_BRIGHTNESS == 235) {
    BLUE_BRIGHTNESS = 240;
  }

  //Making Red Value Proper to Work With so we always get the same values when increasing and decreasing Brightness
  //Must be a multiple of 20 and close to 255
  if (GREEN_BRIGHTNESS == 235) {
    GREEN_BRIGHTNESS = 240;
  }


  //Turning On Power when power button is pressed
  if (MY_CMD == "On") {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, HIGH);
  }

  //Turning Off Power when power button is pressed
  if (MY_CMD == "Off") {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  }

  //Making LED Red
  if (MY_CMD == "Red") {
    digitalWrite(RED_PIN, HIGH);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, LOW);
  }

  //Making LED Green
  if (MY_CMD == "Green") {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, HIGH);
    digitalWrite(BLUE_PIN, LOW);
  }

  //Making LED Blue
  if (MY_CMD == "Blue") {
    digitalWrite(RED_PIN, LOW);
    digitalWrite(GREEN_PIN, LOW);
    digitalWrite(BLUE_PIN, HIGH);
  }

  if (MY_CMD == "Red_Increase" || MY_CMD == "Blue_Increase" || MY_CMD == "Green_Increase" || MY_CMD == "Red_Decrease" || MY_CMD == "Blue_Decrease" || MY_CMD == "Green_Decrease" || MY_CMD == "Brightness_Up" || MY_CMD == "Brightness_Down") {
    analogWrite(RED_PIN, RED_BRIGHTNESS);
    analogWrite(GREEN_PIN, GREEN_BRIGHTNESS);
    analogWrite(BLUE_PIN, BLUE_BRIGHTNESS);
  }

  //Printing Values
  Serial.print(RED_MESSAGE);
  Serial.print(RED_BRIGHTNESS);
  Serial.print(COMMA);
  Serial.print(BLUE_MESSAGE);
  Serial.print(BLUE_BRIGHTNESS);
  Serial.print(COMMA);
  Serial.print(GREEN_MESSAGE);
  Serial.println(GREEN_BRIGHTNESS);
}
