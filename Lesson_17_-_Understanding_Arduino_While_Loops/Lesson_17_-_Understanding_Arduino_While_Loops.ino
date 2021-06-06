//We are just practicing with while loops in this section
//For circuit program, go to part 2
//Declaring Variables
int j;
int DELAY = 500;

void setup() {
  //Starting serial monitor
  Serial.begin(9600);

}

void loop() {
  //We have to give "j" a value before we start the while loop
  //We didn't wanna give "j" a value when we declared our variables
  //That's because "j" will be 1 the entire time we write "j" which we don't want
  j = 1;

  //While loops act like for loops, in that they will execute while a certain condition is met
  //We only specify the condition within the parameters of a while loop
  //While loops are a more flexible to use than for loops
  while (j <= 10) {
    Serial.println(j);
    delay(DELAY);
    j = j + 1;

  }

  //Printing a new blank line
  Serial.println();
}
