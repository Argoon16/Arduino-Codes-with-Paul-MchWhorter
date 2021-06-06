//We are learning how to use a DC Motor and turn it off using a tilt switch
//Declaring Variables
int SPEED_PIN = 5;
int DIRECTION_PIN_ONE = 4;
int DIRECTION_PIN_TWO = 3;
//The Motor Speed is in between 0 and 255 just like the brightness of an LED
int MOTOR_SPEED = 255;
int TILT_SWITCH_PIN = 13;
int TILT_SWITCH_VALUE;


void setup() {
  //Setting up Serial Monitor
  Serial.begin(9600);

  //Setting up motor
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(DIRECTION_PIN_ONE, OUTPUT);
  pinMode(DIRECTION_PIN_TWO, OUTPUT);

  //Setting up tilt switch pin voltage and read
  pinMode(TILT_SWITCH_PIN, INPUT);
  digitalWrite(TILT_SWITCH_PIN, HIGH);
}


void loop() {
  //Reading Tilt Switch Value of it is on or off
  TILT_SWITCH_VALUE = digitalRead(TILT_SWITCH_PIN);

  //Turning off Motor when circuitry is flipped
  if (TILT_SWITCH_VALUE == 1) {
    //Setting Up Motor Direction
    //Remember, if one pin for direction is on, the other one must be off
    digitalWrite(DIRECTION_PIN_ONE, LOW);
    digitalWrite(DIRECTION_PIN_TWO, LOW);
  }

  //Turning on Motor when Circuitry is flat on the ground
  if (TILT_SWITCH_VALUE == 0) {
    digitalWrite(DIRECTION_PIN_ONE, HIGH);
    digitalWrite(DIRECTION_PIN_TWO, LOW);

    //Giving Motor Speed
    analogWrite(SPEED_PIN, MOTOR_SPEED);
  }

  //Printing Tilt Switch Value
  Serial.println(TILT_SWITCH_VALUE);
}
