//We are making the Red LED turn on when the lights in the room are off
//and the Green LED turn on when the lights in the room are on
//Declaring Variables
int RED_LED = 11;
int GREEN_LED = 6;
float VOLTAGE;
int ANALOG_PIN = A5;
int ANALOG_VOLTAGE;

void setup() {
  ///Turning on Serial Monitor
  Serial.begin(9600);
  //Turning on LEDs and Analog Pin
  pinMode(ANALOG_PIN, INPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}

void loop() {
  //Reading Analog Voltage
  ANALOG_VOLTAGE = analogRead(ANALOG_PIN);
  //Converting Analog Voltage to actual Voltage
  VOLTAGE = (5. / 1023.) * ANALOG_VOLTAGE;
  Serial.println(VOLTAGE);

//Turning Green LED on if lights are on
  if (VOLTAGE >= 0.5) {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(RED_LED, LOW);
  }

//Turning Red LED on when light are off
  if (VOLTAGE < 0.5) {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(RED_LED, HIGH);
  }
}
