//We are learning how to use a DC Motor
//Declaring Variables
int SPEED_PIN = 5;
int DIRECTION_PIN_ONE = 4;
int DIRECTION_PIN_TWO = 3;
//The Motor Speed is in between 0 and 255 just like the brightness of an LED
int MOTOR_SPEED = 255;


void setup() {
  //Setting up Serial Monitor
  Serial.begin(9600);

  //Setting up motor
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(DIRECTION_PIN_ONE, OUTPUT);
  pinMode(DIRECTION_PIN_TWO, OUTPUT);
}


void loop() {
  //Setting Up Motor Direction
  //Remember, if one pin for direction is on, the other one must be off
  digitalWrite(DIRECTION_PIN_ONE, LOW);
  digitalWrite(DIRECTION_PIN_TWO, HIGH);

  //Giving Motor Speed
  analogWrite(SPEED_PIN, MOTOR_SPEED);
}
