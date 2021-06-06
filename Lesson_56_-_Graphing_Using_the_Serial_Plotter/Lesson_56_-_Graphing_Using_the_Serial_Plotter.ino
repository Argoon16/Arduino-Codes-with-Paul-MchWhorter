//We are learning how to Use the Serial Plotter
//Our data is coming from the lesson 55 supersonic lesson
//Declaring Variables
int TRIGGER_PIN = 12;
int ECHO_PIN = 11;
int DELAY_MICRO = 10;
int DELAY = 25;

float PING_TRAVEL_TIME;
float DISTANCE;
float OBJECT_DISTANCE;


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

  //Printing Values on Serial Plotter
  //We have to autoscale between two desired points
  //I want to scale my graph to show between 0inch and and 10inch
  Serial.print(0);
  //We need a seperator
  Serial.print(",");
  //We Now we can print the data
  Serial.print(DISTANCE);
  //Serperator
  Serial.print(",");
  //Scale between 0inch and 10inch
  Serial.println(10);
}
