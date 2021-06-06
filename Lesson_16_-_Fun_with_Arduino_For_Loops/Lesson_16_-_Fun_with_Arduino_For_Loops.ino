//We are experimenting with for loops in the serial monitor for this lesson
//Declaring Variables
int j;
int DELAY = 500;

void setup() {
  //Starting serial monitor
  Serial.begin(9600);
}

void loop() {
  //Making for loop
  for (j = 1; j <= 10; j = j + 1) {
    Serial.println(j);
    delay(DELAY);

  }
  //Printing a new line 
  Serial.println();
}
