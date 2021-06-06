//We are making a Push Button work without any Pull up or Pull down Resistors
//Declaring Variables
int BUTTON_PIN = 2;
int BUTTON_VALUE;
String BUTTON_MESSAGE = "Your Button is: ";

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Button Pin
  pinMode(BUTTON_PIN, INPUT);
  //We have to provide a voltage of 5V to the button
  //To do this, we simply turn on the pin using a digitalWrite Command
  digitalWrite(BUTTON_PIN, HIGH);
}

void loop() {
  //Reading voltage from the Button Pin
  BUTTON_VALUE = digitalRead(BUTTON_PIN);
  Serial.print(BUTTON_MESSAGE);
  Serial.println(BUTTON_VALUE);
}
