//Declaring Variables
int RED_LED = 10;
int BLUE_LED = 6;
int GREEN_LED = 3;
String MY_COLOR;
String MESSAGE = "What Color LED? ";
String OUTPUT_MESSAGE = "Your Color is: ";

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  //Starting Serial Monitor
  //Printing Message
  Serial.println(MESSAGE);

  //Waiting for user input
  while (Serial.available() == 0){
}

//The "Serial.readString" command reads the string from the user
MY_COLOR = Serial.readString();

//If user types in Red, the Red LED turns on
//The "||" means "or"
if (MY_COLOR == "red" || MY_COLOR == "Red") {
  //Turning on Red LED
  digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
  }

//If user types in Blue, the Blue LED turns on
  if (MY_COLOR == "blue" || MY_COLOR == "Blue") {
  //Turning on Blue LED
  digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }

//If user types in Green, the Green LED turns on
  if (MY_COLOR == "green" || MY_COLOR == "Green") {
    //Turning on Green LED
  digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

//Printing Output Message and Input Color
Serial.print(OUTPUT_MESSAGE);
Serial.println(MY_COLOR);
}
