//Declaring Variables
int READPIN = A3;
int GREENLED = 9;
int REDLED = 11;
int YELLOWLED = 10;
int READVAL;
float VOLTAGE;
int DELAY = 350;

void setup() {
  //Starting Serial Port
  Serial.begin(9600);
  //Starting analogRead
  pinMode(READPIN, INPUT);
  //Starting LED's
  pinMode(GREENLED, OUTPUT);
  pinMode(REDLED, OUTPUT);
  pinMode(YELLOWLED, OUTPUT);
}

void loop() {
  //Reading the voltage value
  READVAL = analogRead(READPIN);
  //Converting voltage value through equations for actual voltage
  VOLTAGE = (5. / 1023.) * READVAL;
  //Setting up Serial Print
  Serial.println(VOLTAGE);

//Turning on Red LED when voltage is greater than 4V
  if (VOLTAGE > 4.0) {
    digitalWrite(REDLED, HIGH);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, LOW);
  }

//Turning on Green LED when voltage is less than 3V
  if (VOLTAGE < 3.0) {
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, LOW);
    digitalWrite(GREENLED, HIGH);
  }

//Turning on Red LED when voltage is greater than 3V and less than 4V
  if (VOLTAGE > 3.0 && 4.0 > VOLTAGE) {
    digitalWrite(REDLED, LOW);
    digitalWrite(YELLOWLED, HIGH);
    digitalWrite(GREENLED, LOW);
  }
  delay(DELAY);

}
