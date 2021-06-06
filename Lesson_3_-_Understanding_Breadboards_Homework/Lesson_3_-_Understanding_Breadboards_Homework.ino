//https://www.youtube.com/watch?v=CfdaJ4z4u4w&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=3
//Giving variables an interger value to represent pin numbers using "int" command
int RED_PIN = 13;
int GREEN_PIN = 2;
int BLUE_PIN = 8;

//"void setup()" is used to give output and input commands
void setup() {
  //Pin Outputs
  pinMode(RED_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
}

void loop() {
  red();
  blue();
  green();
  exit(0);
}

//Red Light Commands
void red() {
  int r = 0;
  for (r = 0; r < 5; r++) {
    digitalWrite(RED_PIN, HIGH);
    delay(1000);
    digitalWrite(RED_PIN, LOW);
    delay(1000);
  }
}

//Blue Light Commands
void blue() {
  int b = 0;
  for (b = 0; b < 10; b++) {
    digitalWrite(BLUE_PIN, HIGH);
    delay(200);
    digitalWrite(BLUE_PIN, LOW);
    delay(200);
  }
}

//Green Light Commands
void green() {
  int g = 0;
  for (g = 0; g < 5; g++) {
    digitalWrite(GREEN_PIN, HIGH);
    delay(1000);
    digitalWrite(GREEN_PIN, LOW);
    delay(1000);
  }
}
