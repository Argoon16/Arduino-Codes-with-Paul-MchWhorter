//We are learning how to use the supersonic HC-SR04 Sensor
//Declaring Variables
int TRIGGER_PIN = 12;
int ECHO_PIN = 11;
int DELAY_MICRO = 10;
int PING_TRAVEL_TIME;
int DELAY = 25;


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Pins
  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}


void loop() {
  //Sending out a pulse
  //We need to send the trigger pin low, high, low with a tiny bit of delay
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(DELAY_MICRO);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(DELAY);
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(DELAY_MICRO);

  //Getting Value of Ping Travel Time
  //The "pulseIn" Reads a pulse (either HIGH or LOW) on a pin
  //For example, if value is HIGH, pulseIn() waits for the pin to go from LOW to HIGH, starts timing, then waits for the pin to go LOW and stops timing
  //Returns the length of the pulse in microseconds or gives up and returns 0 if no complete pulse was received within the timeout.
  PING_TRAVEL_TIME = pulseIn(ECHO_PIN, HIGH);
  delay(DELAY);

  //Printing Values
  Serial.println(PING_TRAVEL_TIME);
}
