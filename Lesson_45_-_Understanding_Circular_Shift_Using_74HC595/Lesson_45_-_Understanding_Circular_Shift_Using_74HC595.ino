//We are Understanding Circular Shift using the Serial to Parallel Shift Register 74HC595
//Declaring Variables
int LATCH_PIN = 11;
int CLOCK_PIN = 9;
int DATA_PIN = 12;
int DELAY = 500;
byte LEDS = 0xA;


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

  //Multiplying by 2 creates a Logical Shift to the Left
  //We also need to divide by 128 to create the circular shift
  LEDS = LEDS * 2 + LEDS / 128;
  delay(DELAY);
  Serial.println(LEDS);
}
