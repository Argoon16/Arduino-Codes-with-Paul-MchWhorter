//We are making a passive buzzer turn on and change tones according to the light level
//Declaring Variables
float TONE_VALUE;
int ANALOG_PIN = A5;
int BUZZ_PIN = 10;
float VOLTAGE;
int ANALOG_VOLTAGE;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
  //Starting Buzzer Pin and Analog Pin
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(ANALOG_PIN, INPUT);
}

void loop() {
  //Reading Analog Voltage
  ANALOG_VOLTAGE = analogRead(ANALOG_PIN);
  
  //Converting Analog Voltage to Actual Voltage
  VOLTAGE = (5. / 1023.) * ANALOG_VOLTAGE;
  
  //Converting Voltage into tone equation
  TONE_VALUE = (VOLTAGE * 12450) - 2450;
  
  //Turning on passive buzzer and changing tone
  digitalWrite(BUZZ_PIN, HIGH);
  delayMicroseconds(TONE_VALUE);
  digitalWrite(BUZZ_PIN, LOW);
  delayMicroseconds(TONE_VALUE);
  Serial.println(TONE_VALUE);
}
