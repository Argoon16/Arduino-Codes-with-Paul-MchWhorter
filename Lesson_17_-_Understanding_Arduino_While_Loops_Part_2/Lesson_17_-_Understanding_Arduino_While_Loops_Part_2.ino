//Declaring Variables
int POTENTIOMETERVAL;
int DELAY = 500;
int POTENTIOMETERPIN = A5;
int REDLED = 9;
float VOLTAGE;

void setup() {
  //Sarting serial monitor
  Serial.begin(9600);
  //Sarting Red LED and Potentiometer Pin
  pinMode(REDLED, OUTPUT);
  pinMode(POTENTIOMETERPIN, INPUT);

}

void loop() {
  //Getting analogRead voltage
  POTENTIOMETERVAL = analogRead(POTENTIOMETERPIN);
  //Getting actual Voltage by converting potentiometer analogread value
  VOLTAGE = (5. / 1023.) * POTENTIOMETERVAL;
  Serial.println(VOLTAGE);
  delay(DELAY);

  //Making while loop
  while (VOLTAGE > 3) {
    //Turning on Red LED
    digitalWrite(REDLED, HIGH);
    //We need to rewrite everything inside the loop
    //If we don't, the while loop will continue on forever and ever
    //The while loop has to also read the voltage and print it
    POTENTIOMETERVAL = analogRead(POTENTIOMETERPIN);
    VOLTAGE = (5. / 1023) * POTENTIOMETERVAL;
    Serial.println(VOLTAGE);
    delay(DELAY);
  }
  //Turning off the Red LED
  //This is after the while loop since we want to execute it while the while condition is not met
  digitalWrite(REDLED, LOW);

}
