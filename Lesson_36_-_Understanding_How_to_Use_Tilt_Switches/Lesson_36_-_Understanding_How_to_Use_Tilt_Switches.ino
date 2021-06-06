//We are learning how to use a Tilt Switch
//Declaring Variables
int TILT_SWITCH_PIN = 2;
int TILT_SWITCH_VALUE;
int RED_LED = 11;
int GREEN_LED = 9;


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
  
  //Starting Tilt Switch Pin
  pinMode(TILT_SWITCH_PIN, INPUT);

  //Turning on Tilt Switch Pin to start voltage
  digitalWrite(TILT_SWITCH_PIN, HIGH);

  //Starting LEDs
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
}


void loop() {
  //Reading Voltage from Switch
  TILT_SWITCH_VALUE = digitalRead(TILT_SWITCH_PIN);

  //Turning on Green LED when Tilt switch is on the ground
  if (TILT_SWITCH_VALUE == 0) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
  }

  //Turning on Red LED when Tilt switch is tilted
  if (TILT_SWITCH_VALUE == 1) {
    digitalWrite(RED_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
  }

  //Printing Tilt Switch Value
  Serial.println(TILT_SWITCH_VALUE);
}
