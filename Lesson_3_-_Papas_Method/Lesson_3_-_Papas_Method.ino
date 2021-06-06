//https://www.youtube.com/watch?v=CfdaJ4z4u4w&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=3
int RED_PIN = 13;
int GREEN_PIN = 2;
int BLUE_PIN = 8;


void setup() {
  //Pin Outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  //red();
  //blue();
  // green();
  lightLed(RED_PIN, 100);
  lightLed(GREEN_PIN, 500);
  lightLed(BLUE_PIN, 1000);
  //exit(0);
}

void lightLed(int pin, int timeDelay) {
  int i = 0;
  for (i = 0; i < 5; i++) {
    digitalWrite(pin, HIGH);
    delay(timeDelay);
    digitalWrite(pin, LOW);
    delay(timeDelay);
  }
  return;
}

void red() {
  int i = 0;
  for (i = 0; i < 5; i++) {
    digitalWrite(RED_PIN, HIGH);
    delay(1000);
    digitalWrite(RED_PIN, LOW);
    delay(1000);
  }
  return;
}


void blue() {
  int i = 0;
  for (i = 0; i < 5; i++) {
    digitalWrite(8, HIGH);
    delay(1000);
    digitalWrite(8, LOW);
    delay(1000);
  }
  return;
}


void green() {
  int i = 0;
  for (i = 0; i < 5; i++) {
    digitalWrite(GREEN_PIN, HIGH);
    delay(1000);
    digitalWrite(GREEN_PIN, LOW);
    delay(1000);
  }
  return;
}
