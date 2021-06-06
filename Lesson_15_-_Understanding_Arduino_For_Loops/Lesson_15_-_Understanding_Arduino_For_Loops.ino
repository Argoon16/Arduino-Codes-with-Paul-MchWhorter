//Declaring Variables
int YELLOWLED = 9;
int REDLED = 6;
int YELLOWDELAY = 500;
int REDDELAY = 500;
int YELLOWBLINK = 3;
int REDBLINK = 5;
//Usually variables for counting in loops are either "i" or "j"
//Try to use "j" instead of "i" to not get confused
int j;

void setup() {
  //LED setups
  pinMode(YELLOWLED, OUTPUT);
  pinMode(REDLED, OUTPUT);

}

void loop() {
  //For loops repeat and execute themselves until a certain condition is met
  //We start it off with the starting value of the variable
  //We then set the condition we want the for loop to stop at
  //And then tell the for loop of we want to add or take away any given value from the variable
  for (j = 1; j <= YELLOWBLINK; j = j + 1) {
    //Blinking Yellow LED three times
    digitalWrite(YELLOWLED, HIGH);
    delay(YELLOWDELAY);
    digitalWrite(YELLOWLED, LOW);
    delay(YELLOWDELAY);
  }

  for (j = 1; j <= REDBLINK; j = j + 1) {
    //Blinking Red LED five times
    digitalWrite(REDLED, HIGH);
    delay(REDDELAY);
    digitalWrite(REDLED, LOW);
    delay(REDDELAY);
  }

}
