//We are learning how to read voltage from a joystick in the x and y directions
//Declaring Variables
int X_PIN = A0;
int Y_PIN = A5;
int SWITCH_PIN = 11;
int X_VAL;
int Y_VAL;
int SWITCH_VAL;
String X_MESSAGE = "The x value is: ";
String Y_MESSAGE = "The y value is: ";
String SWITCH_MESSAGE = "The switch value is: ";
String COMMA = ", ";
int DELAY = 200;
float X_VOLTAGE;
float Y_VOLTAGE;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Pins
  pinMode(X_PIN, INPUT);
  pinMode(Y_PIN, INPUT);
  pinMode(SWITCH_PIN, INPUT);

  //We need to set up the pull up resistor and start the voltage
  digitalWrite(SWITCH_PIN, HIGH);
}

void loop() {
  //Reading Voltage of X_PIN
  X_VAL = analogRead(X_PIN);
  //Converting to actual Voltage
  X_VOLTAGE = (5. / 1023.) * X_VAL;

  //Reading Voltage of Y_PIN
  Y_VAL = analogRead(Y_PIN);
  //Converting to actual Voltage
  Y_VOLTAGE = (5. / 1023.) * Y_VAL;

  //Reading Voltage of SWITCH_PIN
  SWITCH_VAL = digitalRead(SWITCH_PIN);

  delay(DELAY);

  //Printing Messages
  Serial.print(X_MESSAGE);
  Serial.print(X_VOLTAGE);
  Serial.print(COMMA);
  Serial.print(Y_MESSAGE);
  Serial.print(Y_VOLTAGE);
  Serial.print(COMMA);
  Serial.print(SWITCH_MESSAGE);
  Serial.println(SWITCH_VAL);
}
