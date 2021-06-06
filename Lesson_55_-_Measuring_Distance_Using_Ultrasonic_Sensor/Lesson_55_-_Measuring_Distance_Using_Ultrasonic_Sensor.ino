//We are Calculating Distance using the Ultrasonic Sensor
//Declaring Variables
int TRIGGER_PIN = 12;
int ECHO_PIN = 11;
int DELAY_MICRO = 10;
int DELAY = 25;

float PING_TRAVEL_TIME;
float DISTANCE;
float OBJECT_DISTANCE;

String DISTANCE_MESSAGE = "The Distance from the Target Object is: ";
String INCHES = "inches";


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
  PING_TRAVEL_TIME = pulseIn(ECHO_PIN, HIGH);
  delay(DELAY);

  //Calculating Distance
  //We are only measuring the distance between the sensor and the object
  //The equation is the same equation we made in lesson 54 where we used the half distance the wave travelled
  //and measured how long it took for the ping to back and forth between the object
  DISTANCE = 0.00643 * (PING_TRAVEL_TIME);

  //Printing Values
  Serial.print(DISTANCE_MESSAGE);
  Serial.print(DISTANCE);
  Serial.println(INCHES);
}
