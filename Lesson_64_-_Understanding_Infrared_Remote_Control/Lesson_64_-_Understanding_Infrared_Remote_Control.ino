//Learning how to use an Infrared Remote Control
//Including Libraries
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
  
}
