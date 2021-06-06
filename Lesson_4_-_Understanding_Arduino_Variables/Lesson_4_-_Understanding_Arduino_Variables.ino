//https://www.youtube.com/watch?v=nPOKOi1jIK0&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=4
//Paul said to write a code that could display an SOS morse code call
//Giving RED_PIN an interger value of 13
//Giving SHORT an interger value of 200
//Giving LONG an interger value of 1000
int RED_PIN = 13;
int SHORT = 200;
int LONG = 1000;

//Making Red LED turn on
void setup() {
  pinMode(RED_PIN, OUTPUT);
}

//Providing loop specifications for the arduino to run
void loop() {
  red();
  exit(0);
}

//Red loop for SOS morse code
void red() {
  digitalWrite(RED_PIN, HIGH);
  delay(SHORT);
  digitalWrite(RED_PIN, LOW);
  delay(SHORT);
  digitalWrite(RED_PIN, HIGH);
  delay(SHORT);
  digitalWrite(RED_PIN, LOW);
  delay(SHORT);
  digitalWrite(RED_PIN, HIGH);
  delay(SHORT);
  digitalWrite(RED_PIN, LOW);
  delay(SHORT);
  digitalWrite(RED_PIN, HIGH);
  delay(LONG);
  digitalWrite(RED_PIN, LOW);
  delay(LONG);
  digitalWrite(RED_PIN, HIGH);
  delay(LONG);
  digitalWrite(RED_PIN, LOW);
  delay(LONG);
  digitalWrite(RED_PIN, HIGH);
  delay(LONG);
  digitalWrite(RED_PIN, LOW);
  delay(LONG);
  digitalWrite(RED_PIN, HIGH);
  delay(SHORT);
  digitalWrite(RED_PIN, LOW);
  delay(SHORT);
  digitalWrite(RED_PIN, HIGH);
  delay(SHORT);
  digitalWrite(RED_PIN, LOW);
  delay(SHORT);
  digitalWrite(RED_PIN, HIGH);
  delay(SHORT);
  digitalWrite(RED_PIN, LOW);
  delay(SHORT);
}
