//We are changing the brightness of LEDs using pull up resistor push buttons
//At max brightness, the active buzzer will turn on
//Declaring Variables
int BUTTON_LOW = 11;
int BUTTON_HIGH = 9;
int RED_LED = 6;
int BUZZ_PIN = 3;
int BUTTON_HIGH_VAL;
int BUTTON_LOW_VAL;
int LED_BRIGHTNESS = 0;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Diodes
  pinMode(RED_LED, OUTPUT);
  pinMode(BUTTON_HIGH, INPUT);
  pinMode(BUTTON_LOW, INPUT);
  pinMode(BUZZ_PIN, OUTPUT);
}

void loop() {
  //Reading Button Values
  BUTTON_HIGH_VAL = digitalRead(BUTTON_HIGH);
  BUTTON_LOW_VAL = digitalRead(BUTTON_LOW);

  //Brightness increases while pushing right button
  if (BUTTON_HIGH_VAL == 0) {
    LED_BRIGHTNESS = LED_BRIGHTNESS + 1;
  }

  //Brightness decreases while pushing left button
  if (BUTTON_LOW_VAL == 0) {
    LED_BRIGHTNESS = LED_BRIGHTNESS - 1;
  }

  //Constraining lowest brightness value to 0
  if (LED_BRIGHTNESS < 0) {
    LED_BRIGHTNESS = 0;
  }

  //Constraining maximum brightness value to 255
  if (LED_BRIGHTNESS > 255) {
    LED_BRIGHTNESS = 255;
  }

//Turning on active buzzer at maximum brightness
if (LED_BRIGHTNESS == 255){
  digitalWrite(BUZZ_PIN, HIGH);
}

//Turning off active buzzer at maximum brightness
if (LED_BRIGHTNESS < 255){
  digitalWrite(BUZZ_PIN, LOW);
}

  //Turning on LED with requested brightness
  analogWrite(RED_LED, LED_BRIGHTNESS);

  //Printing brightness value
  Serial.println(LED_BRIGHTNESS);
}
