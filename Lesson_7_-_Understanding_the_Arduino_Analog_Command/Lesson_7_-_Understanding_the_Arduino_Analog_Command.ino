//https://www.youtube.com/watch?v=6CRhpUV92ww&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=7
//Giving RED_LED an interger value of 9 to represent LED Pin number
//Giving FULL_BRIGHTNESS and interger value of 255 to represent the analog voltage as maximum capacity at 5V
int RED_LED = 9;
int FULL_BRIGHTNESS = 255;
int HALF_BRIGHTNESS = 127;
int QUARTER_BRIGHTNESS = 63;

//Giving RED_PIN and output
void setup() {
  pinMode(RED_LED, OUTPUT);
}

//Declaring loop order
void loop() {
  red();
  exit(0);
}

//The "analogWrite" command controls the voltage the LED can receive to a certain extent
//The command only work if the LED is connected to a pin with the "~" symbol next to the number (Ex: 9~)
//The second parameter of the code ranges from 0-255
//0 = 0 Volts, 255 = 5 Volts
//The number "255" results from binary quadratic relations (Ex: 1, 2, 4, 8, 16, 32, 64, 128, 256)
//Binary also counts zero as a number, which is why it is 255 instead of 256
//Think of the voltage as 8 bits of resolution (2^8)
void red() {
  analogWrite(RED_LED, FULL_BRIGHTNESS);
  delay(1000);
  analogWrite(RED_LED, HALF_BRIGHTNESS);
  delay(1000);
  analogWrite(RED_LED, QUARTER_BRIGHTNESS);
  delay(1000);
  analogWrite(RED_LED, FULL_BRIGHTNESS);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
  analogWrite(RED_LED, HALF_BRIGHTNESS);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
  analogWrite(RED_LED, QUARTER_BRIGHTNESS);
  delay(1000);
  digitalWrite(RED_LED, LOW);
  delay(1000);
}
