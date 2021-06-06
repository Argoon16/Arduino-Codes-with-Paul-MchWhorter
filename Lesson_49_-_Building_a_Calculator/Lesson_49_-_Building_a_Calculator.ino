//We are building a Calculator with the LCD Display
//Including Libraies
#include <LiquidCrystal.h>

//Declaring Variables
int RS = 7;
int EN = 8;
int D4 = 9;
int D5 = 10;
int D6 = 11;
int D7 = 12;
int DELAY = 1000;
int DELAY_2 = 10000;

float FIRST_NUMBER;
float SECOND_NUMBER;
float ANSWER;

String QUESTION_WHAT = "What is your";
String QUESTION_FIRST_NUMBER = "First Number?";
String QUESTION_SECOND_NUMBER = "Second Number?";
String QUESTION_OPERATOR = "Operator?";
String ANSWER_STATEMENT = "Your Answer is:";
String EQUAL = "=";
String OPERATOR;

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
  //Printing First Number Question
  LCD.setCursor(0, 0);
  LCD.print(QUESTION_WHAT);
  LCD.setCursor(0, 1);
  LCD.print(QUESTION_FIRST_NUMBER);

  //Waiting for user input
  while (Serial.available() == 0) {
  }

  //Clearing LCD Display
  LCD.clear();

  //Getting user input for First Number and storing it
  FIRST_NUMBER = Serial.parseFloat();


  //Printing Second Number Question
  LCD.setCursor(0, 0);
  LCD.print(QUESTION_WHAT);
  LCD.setCursor(0, 1);
  LCD.print(QUESTION_SECOND_NUMBER);

  //Waiting for user input
  while (Serial.available() == 0) {
  }

  //Clearing LCD Display
  LCD.clear();

  //Getting user input for Second Number and storing it
  SECOND_NUMBER = Serial.parseFloat();

  //Printing Operator Question
  LCD.setCursor(0, 0);
  LCD.print(QUESTION_WHAT);
  LCD.setCursor(0, 1);
  LCD.print(QUESTION_OPERATOR);

  //Waiting for user input
  while (Serial.available() == 0) {
  }

  //Clearing LCD Display
  LCD.clear();

  //Getting Operator from user and Storing it
  OPERATOR = Serial.readString();

  //Printing Answer Statement
  LCD.setCursor(0, 0);
  LCD.print(ANSWER_STATEMENT);

  //Printing Input Numbers and Operator on Serial Monitor along with Equal Sign
  LCD.setCursor(0, 1);
  LCD.print(FIRST_NUMBER);
  LCD.print(OPERATOR);
  LCD.print(SECOND_NUMBER);
  LCD.print(EQUAL);

  //Getting Answer
  if (OPERATOR == "+") {
    ANSWER = FIRST_NUMBER + SECOND_NUMBER;
  }

  if (OPERATOR == "-") {
    ANSWER = FIRST_NUMBER - SECOND_NUMBER;
  }

  if (OPERATOR == "*") {
    ANSWER = FIRST_NUMBER * SECOND_NUMBER;
  }

  if (OPERATOR == "/") {
    ANSWER = FIRST_NUMBER / SECOND_NUMBER;
  }

  //Printing the Answer
  LCD.print(ANSWER);
  delay(DELAY_2);
  LCD.clear();

}
