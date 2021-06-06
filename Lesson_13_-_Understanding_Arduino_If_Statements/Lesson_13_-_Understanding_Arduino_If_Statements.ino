//Declaring Variables
int MYPIN = A3;
int READVAL;
float VOLTAGE;
int DELAY = 350;
int GREENLED = 9;
void setup() {
  //Starting serial port
  Serial.begin(9600);
  //Starting analog read
  pinMode(MYPIN, INPUT);
  //Starting LED
  pinMode(GREENLED, OUTPUT);

}

void loop() {
  //Reading voltage value
  READVAL = analogRead(MYPIN);
  //Converting voltage value through the equation
  VOLTAGE = (5. / 1023.) * READVAL;
  //Setting up serial print
  Serial.print(" Potentiometer Voltage is ");
  Serial.println(VOLTAGE);

  //If statements only execute when a certain condition is met
  if (VOLTAGE > 4.0) {
    //Turns on Green LED
    digitalWrite(GREENLED, HIGH);

  }

  if (VOLTAGE < 4.0) {
    //Turning Gree LED off
    digitalWrite(GREENLED, LOW);

  }
  delay(DELAY);

}
