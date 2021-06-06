//We are Creating a Binary Bit Flipper
//Declaring Variables
int LATCH_PIN = 11;
int CLOCK_PIN = 9;
int DATA_PIN = 12;
int DELAY = 500;
byte LEDS = 0xF;
byte LEDS_FLIPPED;


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
  delay(DELAY);

  //Now we have to flip the values, we could write a bunch of if statements, but there is an easier way that always works
  //To do this, we simply subtact 255, the maximum value of a byte, from the decimal value of the binary value
  LEDS_FLIPPED = 255-LEDS;
  
  //We want to send in data, and in order to do that we must set the latch pin low
  digitalWrite(LATCH_PIN, LOW);

  //Sending Data
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS_FLIPPED);

  //Set the latch pin back to high
  digitalWrite(LATCH_PIN, HIGH);
  delay(DELAY);
}
