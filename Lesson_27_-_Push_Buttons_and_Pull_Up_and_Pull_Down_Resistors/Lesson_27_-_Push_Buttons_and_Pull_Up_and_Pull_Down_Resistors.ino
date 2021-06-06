//We are making a pull up resistor push button turn on a Red LED
//Declaring Variables
int RED_LED = 6;
int BUTTON_PIN = 11;
int BUTTON_READ;
int DELAY = 250;

void setup() {
  //Beginning Serial Monitor
  Serial.begin(9600);
  //Turning on Red LED
  pinMode(RED_LED, OUTPUT);
  //We are reading from the Button Pin, so we are giving it an input value
  //Reading Button Pin
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  //Reading value from button pin
  BUTTON_READ = digitalRead(BUTTON_PIN);
  //Printing Button Read Value
  Serial.println(BUTTON_READ);
  delay(DELAY);

  //Turning off Red LED when button is not pushed
  if (BUTTON_READ == 1) {
    digitalWrite(RED_LED, LOW);
  }

  //Turning on Red LED when button is pushed
  if (BUTTON_READ == 0) {
    digitalWrite(RED_LED, HIGH);
  }
}
