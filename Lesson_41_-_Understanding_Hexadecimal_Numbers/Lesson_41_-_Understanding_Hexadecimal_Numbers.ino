//We are experimenting with Hexadecimal Numbers
//Declaring Variables
//The "byte" command tells the arduino that we are assigning a hexidecimal number to the variable
byte MY_BYTE = 0;
int DELAY = 500;
String SPACE = "  ";


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
}


void loop() {
  //Printing the Hexadecimal Number as a Decimal Number
  Serial.print(MY_BYTE, DEC);
  Serial.print(SPACE);

  //Printing the Hexadecimal Number as a Binary Number
  Serial.print(MY_BYTE, BIN);
  Serial.print(SPACE);
  
  //Printing the Hexadecimal Number
  //We don't need to tell the arduino to print the number in Hex, since the variable is already assigned as a byte/hexadecimal number
  //We are just doing it cause why not
  Serial.println(MY_BYTE, HEX);

  //Increasing Everything by 1
  MY_BYTE = MY_BYTE + 1;
  delay(DELAY);
}
