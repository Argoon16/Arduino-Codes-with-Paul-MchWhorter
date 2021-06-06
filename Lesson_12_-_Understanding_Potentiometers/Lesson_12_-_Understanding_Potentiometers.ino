//Declaring Variables
int ANALOG_PIN = A3;
int READ_VAL;
float VOLTAGE;
int DELAY = 250;

void setup() {
  //Begin Serial Port
  Serial.begin(9600);

}

void loop() {
  //Setting up READ_VAL
  READ_VAL = analogRead(ANALOG_PIN);
  //Setting up equation
  VOLTAGE = (5./1023.)*READ_VAL;
  Serial.println(VOLTAGE);
  delay(DELAY);
}
