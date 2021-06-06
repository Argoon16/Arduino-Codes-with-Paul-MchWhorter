//We are making a Passive Buzzer work
//Declaring Variables
int BUZZ_PIN = 10;
float TONE_VAL;
int POTENTIOMETER_VALUE;
int POTENTIOMETER_PIN = A5;

void setup() {
  Serial.begin(9600);
  //Turning on Passive Buzzer pin
  pinMode(BUZZ_PIN, OUTPUT);
  pinMode(POTENTIOMETER_PIN, INPUT);
}

void loop() {
  //Reading Potentiometer Sclaed Voltage Value
  POTENTIOMETER_VALUE = analogRead(POTENTIOMETER_PIN);
  //Making an equations for amount of microseconds for delay time/tone value
  //The tone of a buzzer is dependent on the delay time between the Alternating Current Signals
  TONE_VAL = (9940. / 1023.) * POTENTIOMETER_VALUE + 60;
  //Turning the Passive Buzzer on by looping Alternating Current Signalas
  digitalWrite(BUZZ_PIN, HIGH);
  //We can control the tone of the buzzer by changing the delay time
  //We use microseconds since they act as better units for buzzer tones
  delayMicroseconds(TONE_VAL);
  digitalWrite(BUZZ_PIN, LOW);
  delayMicroseconds(TONE_VAL);
}
