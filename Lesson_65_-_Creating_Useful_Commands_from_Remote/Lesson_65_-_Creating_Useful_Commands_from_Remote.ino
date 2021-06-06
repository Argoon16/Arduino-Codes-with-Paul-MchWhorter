//We are Making Useful Commands by Giving String Values to Each Button on the Remote Control
//Declaring Variables
#include <IRremote.h>

//Declaring Variables
int IR_PIN = 9;
int DELAY = 1500;

String MY_CMD;

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
    MY_CMD = "Zero";
    Serial.println(MY_CMD);
  }

  //If we press the 1 button...
  if (CMD.value == 0xFF30CF) {
    MY_CMD = "One";
    Serial.println(MY_CMD);
  }

  //If we press the 2 button...
  if (CMD.value == 0xFF18E7) {
    MY_CMD = "Two";
    Serial.println(MY_CMD);
  }

  //If we press the 3 button...
  if (CMD.value == 0xFF7A85) {
    MY_CMD = "Three";
    Serial.println(MY_CMD);
  }

    //If we press the 4 button...
  if (CMD.value == 0xFF10EF) {
    MY_CMD = "Four";
    Serial.println(MY_CMD);
  }

    //If we press the 5 button...
  if (CMD.value == 0xFF38C7) {
    MY_CMD = "Five";
    Serial.println(MY_CMD);
  }

    //If we press the 6 button...
  if (CMD.value == 0xFF5AA5) {
    MY_CMD = "Six";
    Serial.println(MY_CMD);
  }

    //If we press the 7 button...
  if (CMD.value == 0xFF42BD) {
    MY_CMD = "Seven";
    Serial.println(MY_CMD);
  }

    //If we press the 8 button...
  if (CMD.value == 0xFF4AB5) {
    MY_CMD = "Eight";
    Serial.println(MY_CMD);
  }

    //If we press the 9 button...
  if (CMD.value == 0xFF52AD) {
    MY_CMD = "Nine";
    Serial.println(MY_CMD);
  }

    //If we press the Power button...
  if (CMD.value == 0xFFA25D) {
    MY_CMD = "Power";
    Serial.println(MY_CMD);
  }

    //If we press the Volume_Up button...
  if (CMD.value == 0xFF629D) {
    MY_CMD = "Volume_Up";
    Serial.println(MY_CMD);
  }

    //If we press the Volume_Down button...
  if (CMD.value == 0xFFA857) {
    MY_CMD = "Volume_Down";
    Serial.println(MY_CMD);
  }

    //If we press the Stop button...
  if (CMD.value == 0xFFE21D) {
    MY_CMD = "Stop";
    Serial.println(MY_CMD);
  }

    //If we press the Rewind button...
  if (CMD.value == 0xFF22DD) {
    MY_CMD = "Rewind";
    Serial.println(MY_CMD);
  }

    //If we press the Fast_Forward button...
  if (CMD.value == 0xFFC23D) {
    MY_CMD = "Fast_Forward";
    Serial.println(MY_CMD);
  }

    //If we press the Pause_Play button...
  if (CMD.value == 0xFF02FD) {
    MY_CMD = "Pause_Play";
    Serial.println(MY_CMD);
  }

  //If we press the Up button...
  if (CMD.value == 0xFF906F) {
    MY_CMD = "Up";
    Serial.println(MY_CMD);
  }

    //If we press the Down button...
  if (CMD.value == 0xFFE01F) {
    MY_CMD = "Down";
    Serial.println(MY_CMD);
  }

    //If we press the EQ button...
  if (CMD.value == 0xFF9867) {
    MY_CMD = "EQ";
    Serial.println(MY_CMD);
  }

    //If we press the ST button...
  if (CMD.value == 0xFFB04F) {
    MY_CMD = "ST";
    Serial.println(MY_CMD);
  }
}
