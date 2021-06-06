//We are understanding Logical Shift Left and Logical Shift Right with the 74HC595
//Declaring Variables
int LATCH_PIN = 11;
int CLOCK_PIN = 9;
int DATA_PIN = 12;
int DELAY = 500;
byte LEDS = 0xFF;


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Serial to Parallel Shift Register Pins
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(DATA_PIN, OUTPUT);
}


void loop() {
  //We want to send in data, and in order to do that we must set the latch pin low
  digitalWrite(LATCH_PIN, LOW);

  //Sending Data
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS);

  //Set the latch pin back to high
  digitalWrite(LATCH_PIN, HIGH);

  //Dividing by 2 creates a Logical Shift to the Right
  //We can also multiply by two to move the Logical Shift Left
  LEDS = LEDS / 2;
  delay(DELAY);
  Serial.println(LEDS);
}
