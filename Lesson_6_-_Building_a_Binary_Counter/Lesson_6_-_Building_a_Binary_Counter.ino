//https://www.youtube.com/watch?v=Lg39qKrdySU&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=6
//Giving variables interger value to represent LED pins and delay time
int BLUE_LED = 13;
int GREEN_LED = 10;
int RED_LED = 7;
int WHITE_LED = 4;
int TIME = 700;

void setup(){
  pinMode(BLUE_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(WHITE_LED, OUTPUT);
  
}

void loop(){
  ZERO();
  ONE();
  TWO();
  THREE();
  FOUR();
  FIVE();
  SIX();
  SEVEN();
  EIGHT();
  NINE();
  TEN();
  ELEVEN();
  TWELVE();
  THIRTEEN();
  FOURTEEN();
  FIFTEEN();
  exit(0);
}

void ZERO(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void ONE(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void TWO(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void THREE(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void FOUR(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void FIVE(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void SIX(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void SEVEN(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, LOW);
  delay(TIME);
}

void EIGHT(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}

void NINE(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}

void TEN(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}

void ELEVEN(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}

void TWELVE(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}

void THIRTEEN(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}

void FOURTEEN(){
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}

void FIFTEEN(){
  digitalWrite(BLUE_LED, HIGH);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, HIGH);
  digitalWrite(WHITE_LED, HIGH);
  delay(TIME);
}
