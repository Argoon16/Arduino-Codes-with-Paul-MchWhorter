//We are Learning how to use and LCD Display
//Starting Libraries
#include <LiquidCrystal.h>
int RS = 7;
int EN = 8;
int D4 = 9;
int D5 = 10;
int D6 = 11;
int D7 = 12;
int DELAY = 1000;
String MESSAGE = "Hello World";
String NAME = "My Name is Arjun";
//Assigning LCD Variable
//We have to also tell the LCD Library in the Arduino how we connected the LCD so it knows what to do with each pin
LiquidCrystal LCD(RS, EN, D4, D5, D6, D7);


void setup() {
  //Starting LCD
  //We have to tell Arduino what kind of LCD we are working with
  //Our LCD has 16 Columns with 2 Rows
  LCD.begin(16, 2);

  //Starting Serial Monitor
  Serial.begin(9600);
}


void loop() {
  //We have to tell Arduino where to set the cursor
  LCD.setCursor (0, 0);

  //Printing Message on LCD
  LCD.print(MESSAGE);
  delay(DELAY);

  //Clearing Message on LCD
  LCD.clear();

  //Printing Name on LCD
  LCD.setCursor(0, 1);
  LCD.print(NAME);
  delay(DELAY);

  //Clearing Name on LCD
  LCD.clear();
}
