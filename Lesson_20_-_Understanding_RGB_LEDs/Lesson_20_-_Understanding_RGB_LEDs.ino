//Declaring Variables
int RED = 3;
int GREEN = 6;
int BLUE = 10;
String MY_COLOR;
String MESSAGE = "What Color would you like? ";
String OUTPUT_MESSAGE = "Your Color is: ";


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
  //Starting LEDs
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}

void loop() {
  //Printing Message
  Serial.println(MESSAGE);

  //Waiting for user input
  while (Serial.available() == 0){
  }

//Reading user input
MY_COLOR = Serial.readString();

//If user inputs "off", LED will turn off
if (MY_COLOR == "off"){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

//If user inputs "red", LED will turn red
if (MY_COLOR == "red"){
  digitalWrite(RED, HIGH);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
}

//If user inputs "green", LED will turn green
if (MY_COLOR == "green"){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, HIGH);
  digitalWrite(BLUE, LOW);
}

//If user inputs "blue", LED will turn blue
if (MY_COLOR == "blue"){
  digitalWrite(RED, LOW);
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, HIGH);
}

//If user inputs "aqua", LED will turn aqua
if (MY_COLOR == "aqua"){
  digitalWrite(RED, LOW);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 80);
}

//If user inputs "cyan", LED will turn cyan
if (MY_COLOR == "cyan"){
  digitalWrite(RED, LOW);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, 255);
}

//If user inputs "yellow", LED will turn yellow
if (MY_COLOR == "yellow"){
  digitalWrite(RED, 255);
  analogWrite(GREEN, 255);
  analogWrite(BLUE, LOW);
}

//If user inputs "magenta", LED will turn magenta
if (MY_COLOR == "magenta"){
  digitalWrite(RED, 255);
  analogWrite(GREEN, LOW);
  analogWrite(BLUE, 255);
}

//If user inputs "orange", LED will turn orange
if (MY_COLOR == "orange"){
  digitalWrite(RED, 255);
  analogWrite(GREEN, 80);
  analogWrite(BLUE, LOW);
}

//If user inputs "fuchsia", LED will turn fuchsia
if (MY_COLOR == "fuchsia"){
  digitalWrite(RED, 240);
  analogWrite(GREEN, 130);
  analogWrite(BLUE, 225);
}

//Printing Output and Color Messages
Serial.print(OUTPUT_MESSAGE);
Serial.println(MY_COLOR);
}
