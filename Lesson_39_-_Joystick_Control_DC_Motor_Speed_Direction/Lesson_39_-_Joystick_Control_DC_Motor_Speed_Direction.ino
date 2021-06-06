//We are using a Joystick to Control a DC Motor Speed and Direction
//Declaring Variables
int MOTOR_CLOCKWISE_PIN = 4;
int MOTOR_COUNTERCLOCKWISE_PIN = 3;
int SPEED_PIN = 5;
int JOYSTICK_PIN = A5;
float ANALOG_VOLTAGE;
int DELAY = 200;
float SPEED;
float MOTOR_SPEED;


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Motor Pins
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(MOTOR_CLOCKWISE_PIN, OUTPUT);
  pinMode(MOTOR_COUNTERCLOCKWISE_PIN, OUTPUT);
}

void loop() {
  //Reading Joystick Analog Voltage
  ANALOG_VOLTAGE = analogRead(JOYSTICK_PIN);

  //Making Speed equation
  SPEED = (255. / 511.5) * abs(ANALOG_VOLTAGE - 511.5);

  //Rotating Motor Clockwise if Joystick is pushed on way
  if (ANALOG_VOLTAGE > 511.5) {
    digitalWrite(MOTOR_CLOCKWISE_PIN, HIGH);
    digitalWrite(MOTOR_COUNTERCLOCKWISE_PIN, LOW);
    analogWrite(SPEED_PIN, SPEED);
  }

  //Turning off joystick in neutral position
  if (ANALOG_VOLTAGE == 511.5) {
    digitalWrite(MOTOR_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR_COUNTERCLOCKWISE_PIN, LOW);
  }

  //Rotating Motor Clockwise if Joystick is pushed the other way
  if (ANALOG_VOLTAGE < 511.5) {
    digitalWrite(MOTOR_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR_COUNTERCLOCKWISE_PIN, HIGH);
    analogWrite(SPEED_PIN, SPEED);
  }

  //Printing Speed
  Serial.println(ANALOG_VOLTAGE);
}
