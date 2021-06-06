//We are controlling the speed and rotation of a DC motor using push buttons
//If we keep pushing a button, the speed will increase in the specified direction
//At some point, the DC motor will rotate the other way and increase in the other direction if the other button is to be pushed
//Declaring Variables
int CLOCKWISE_BUTTON_PIN = 12;
int COUNTERCLOCKWISE_BUTTON_PIN = 13;
int SPEED_PIN = 5;
int MOTOR_CLOCKWISE_PIN = 4;
int MOTOR_COUNTERCLOCKWISE_PIN = 3;
int CLOCKWISE_BUTTON_VALUE;
int COUNTERCLOCKWISE_BUTTON_VALUE;
int CLOCKWISE_BUTTON_VALUE_OLD;
int CLOCKWISE_BUTTON;
int SPEED;
int COUNTERCLOCKWISE_BUTTON_VALUE_OLD;
int SPEED_INCREASE_AND_DECREASE_VALUE = 5;
String CLOCKWISE_BUTTON_MESSAGE = "Clockwise Button Value: ";
String COUNTERCLOCKWISE_BUTTON_MESSAGE = "Counterclockwise Button Value: ";
String SPEED_MESSAGE = "Speed: ";
String COMMA = ", ";


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Setting initial speed
  SPEED = 0;

  //Starting Button Pins
  pinMode(CLOCKWISE_BUTTON_PIN, INPUT);
  pinMode(COUNTERCLOCKWISE_BUTTON_PIN, INPUT);

  //Starting Motor Pins
  pinMode(SPEED_PIN, OUTPUT);
  pinMode(MOTOR_CLOCKWISE_PIN, OUTPUT);
  pinMode(MOTOR_COUNTERCLOCKWISE_PIN, OUTPUT);

  //Giving the Buttons a starting voltage for the digital read
  digitalWrite(CLOCKWISE_BUTTON_PIN, OUTPUT);
  digitalWrite(COUNTERCLOCKWISE_BUTTON_PIN, OUTPUT);
}


void loop() {
  //Reading Button Values
  CLOCKWISE_BUTTON_VALUE = digitalRead(CLOCKWISE_BUTTON_PIN);
  COUNTERCLOCKWISE_BUTTON_VALUE = digitalRead(COUNTERCLOCKWISE_BUTTON_PIN);

  //Increasing the clockwise speed of the DC motor when the clockwise button is pressed
  if (CLOCKWISE_BUTTON_VALUE == 1 && CLOCKWISE_BUTTON_VALUE_OLD == 0) {
    SPEED = SPEED + SPEED_INCREASE_AND_DECREASE_VALUE;
  }
  //Meeting the if statement requirements
  CLOCKWISE_BUTTON_VALUE_OLD = CLOCKWISE_BUTTON_VALUE;


  //Increasing the counterclockwise speed of the DC motor when the counterclockwise button is pressed
  if (COUNTERCLOCKWISE_BUTTON_VALUE == 1 && COUNTERCLOCKWISE_BUTTON_VALUE_OLD == 0) {
    SPEED = SPEED - SPEED_INCREASE_AND_DECREASE_VALUE;
  }
  //Meeting the if statement requirements
  COUNTERCLOCKWISE_BUTTON_VALUE_OLD = COUNTERCLOCKWISE_BUTTON_VALUE;

  //Setting Max Speed Limit
  if (SPEED > 255) {
    SPEED = 255;
  }

  //Setting Max Speed Limit
  if (SPEED < -255) {
    SPEED = -255;
  }

  //Setting Min Speed Limit
  if (SPEED == 5) {
    SPEED = 160;
  }

  //Setting Min Speed Limit
  if (SPEED == -5) {
    SPEED = -160;
  }

  //Making the DC Motor stop when other button is pressed after going underneath min speed limit
  if (SPEED == 155) {
    SPEED = 0;
  }

  //Making the DC Motor stop when other button is pressed after going underneath min speed limit
  if (SPEED == -155) {
    SPEED = 0;
  }

  //Turning Motor on in clockwise direction with desired speed
  if (SPEED > 0) {
    digitalWrite(MOTOR_CLOCKWISE_PIN, HIGH);
    digitalWrite(MOTOR_COUNTERCLOCKWISE_PIN, LOW);
    analogWrite(SPEED_PIN, abs(SPEED));
  }

  //Turning Motor off if speed is zero
  if (SPEED == 0) {
    digitalWrite(MOTOR_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR_COUNTERCLOCKWISE_PIN, LOW);
    analogWrite(SPEED_PIN, abs(SPEED));
  }

  //Turning Motor on in counterclockwise direction with desired speed
  if (SPEED < 0) {
    digitalWrite(MOTOR_CLOCKWISE_PIN, LOW);
    digitalWrite(MOTOR_COUNTERCLOCKWISE_PIN, HIGH);
    analogWrite(SPEED_PIN, abs(SPEED));
  }

  //Printing
  Serial.print(CLOCKWISE_BUTTON_MESSAGE);
  Serial.print(CLOCKWISE_BUTTON_VALUE);
  Serial.print(COMMA);
  Serial.print(COUNTERCLOCKWISE_BUTTON_MESSAGE);
  Serial.println(COUNTERCLOCKWISE_BUTTON_VALUE_OLD);
  Serial.print(SPEED_MESSAGE);
  Serial.println(abs(SPEED));
}
