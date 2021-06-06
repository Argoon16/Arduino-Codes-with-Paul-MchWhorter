//We are Making a Binary counter using the 74HC595
//Declaring Variables
int LATCH_PIN = 11;
int CLOCK_PIN = 9;
int DATA_PIN = 12;
int DELAY = 100;
byte LEDS = 0x00;


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

  //Adding one to counter everytime the loop runs
  LEDS = LEDS + 1;

  //Setting Maximum value and Resetting Counter
  if (LEDS == 256) {
    LEDS = 0;
  }

  //Printing Counter Value
  Serial.println(LEDS);
  delay(DELAY);
}
