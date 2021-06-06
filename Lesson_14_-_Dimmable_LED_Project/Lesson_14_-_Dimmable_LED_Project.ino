//Declaring Variables
int POTENTIOMETERPIN = A0;
int REDLED = 10;
int POTENTIOMETERVAL;
float BRIGHTNESSVAL;
int DELAY = 350;

void setup() {
  //Starting LED
  pinMode(REDLED, OUTPUT);
  //Starting Potentiometer pin
  pinMode(POTENTIOMETERPIN, INPUT);
  //Starting serial port
  Serial.begin(9600);

}

void loop() {
  //Reading Potentiometer Value
  POTENTIOMETERVAL = analogRead(POTENTIOMETERPIN);
  //Converting potentiometer value into Brightness value
  BRIGHTNESSVAL = (255. / 1023.) * POTENTIOMETERVAL;
  //Giving Red LED the converted brightness
  analogWrite(REDLED, BRIGHTNESSVAL);
  //Printing brightness value on serial port
  Serial.println(BRIGHTNESSVAL);
  delay(DELAY);

}
