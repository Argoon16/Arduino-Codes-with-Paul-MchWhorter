//We are changing the tone of an active buzzer
//It is much easier to use a passive buzzer for changing tones
//However we are just learning how to change the tone for the active buzzer for the sake of it
//The active buzzer will switch between two for loops for two different sounds performing on after the other
//Declaring Variables
int BUZZ_PIN = 11;
int DELAY_1 = 1;
int DELAY_2 = 2;
int j;


void setup() {
  //Sarting Buzzer Pin
  pinMode(BUZZ_PIN, OUTPUT);
}

void loop() {
  //Setting up for loop for different tone
  //Sound Number 1
  for (j = 1; j <= 100; j = j + 1) {
    digitalWrite(BUZZ_PIN, HIGH);
    delay(DELAY_1);
    digitalWrite(BUZZ_PIN, LOW);
    delay(DELAY_1);
  }

  //Setting up for loop for different tone (2)
  //Sound Number 2
  for (j = 1; j <= 100; j = j + 1) {
    digitalWrite(BUZZ_PIN, HIGH);
    delay(DELAY_2);
    digitalWrite(BUZZ_PIN, LOW);
    delay(DELAY_2);
  }
}
