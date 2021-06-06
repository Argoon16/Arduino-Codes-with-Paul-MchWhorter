//We are making a buzzer turn on when the Potentiometer Voltage reaches 3 Volts or Higher
//Declaring Variables
int BUZZ_PIN = 11;
int POTENTIOMETER_PIN = A5;
float VOLTAGE;
int POTENTIOMETER_VAL;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
  //Starting Buzzer Pin
  pinMode(BUZZ_PIN, OUTPUT);

}

void loop() {
  //Reading Potentiometer Scaled Votlage
  POTENTIOMETER_VAL = analogRead(POTENTIOMETER_PIN);
  //Converting Potentiometer Voltage value to actual Voltage
  VOLTAGE = (5. / 1023.) * POTENTIOMETER_VAL;
  Serial.println(VOLTAGE);

  //Setting up while loop to turn on Buzzer while Voltage is greater than 3 Volts
  while (VOLTAGE >= 3.0) {
    digitalWrite(BUZZ_PIN, HIGH);
    //Reading Potentiometer Scaled Votlage
    POTENTIOMETER_VAL = analogRead(POTENTIOMETER_PIN);
    //Converting Potentiometer Voltage value to actual Voltage
    VOLTAGE = (5. / 1023.) * POTENTIOMETER_VAL;
    Serial.println(VOLTAGE);

  }

  //Turning off Buzzer when Buzzer Voltage less than 3 Volts
  digitalWrite(BUZZ_PIN, LOW);
}
