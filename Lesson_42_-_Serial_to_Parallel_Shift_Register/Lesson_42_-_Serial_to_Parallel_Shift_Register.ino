//We are Learning how to use a Serial to Parallel Shift Register (74HC595)
//Declaring Variables
int LATCH_PIN = 11;
int CLOCK_PIN = 9;
int DATA_PIN = 12;
int DELAY = 250;

//Setting up Hexadecimanl Number
//We can also use binary by using a "b" instead of an "x"
byte LEDS_1 = 0xAA;
byte LEDS_2 = 0b01010101;


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

  //Now we can send in our data
  //The "shiftOut" command automatically synchronizes the data the latch pin inputs with the clock pin
  //We want to send the data out using the data pin
  //We also have to tell the Arduino which pin uses the clock pin so the arduino knows where the clock pin is to syncrhonize the data with the clock pin
  //We also have to tell the arduino if the least significant or most significant bit is going to be sent first
  //We also have to tell the arduino what data we are sending
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS_1);

  //Now that we have sent the data, we have to set the latch pin to high
  digitalWrite(LATCH_PIN, HIGH);
  delay(DELAY);

  //Making a cool pattern
  digitalWrite(LATCH_PIN, LOW);
  shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, LEDS_2);
  digitalWrite(LATCH_PIN, HIGH);
  delay(DELAY);
}
