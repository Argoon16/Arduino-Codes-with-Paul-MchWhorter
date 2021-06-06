//We are telling the serial monitor how many times we want an LED to blink
//Declaring Variables
int BLINK_NUMBER;
String INPUT_MESSAGE = "How many Blinks do you want? ";
String BLINK_MESSAGE = "The red LED blinked: ";
int BLINK_TIME = 500;
int RED_LED = 9;
int j;

void setup() {
  //Sarting Red LED
  pinMode(RED_LED, OUTPUT);

}

void loop() {
  //Starting serial monitor
  //I had a problem where after I inputted a number, it would run the command again and print
  //Both strings again, thinking I inputted the number 0 into the serial monitor
  //Putting a "Serial.begin" command and "Serial.end" command fixed this problem
  Serial.begin(9600);

  //Printing Message
  Serial.println(INPUT_MESSAGE);
  //The "Serial.available" command refers to the input box in the serial monitor
  //The double equal sign command checks to see if the statement is true
  //If we wrote one equal sign, then we would make "Serial.avaiable()" equal 0
  //In this command, we are making the serial monitor wait for an input from the user
  //It does absolutly nothinng until there is an input from the user
  while (Serial.available() == 0) {

  }

  //The "Serial.parseInt" reads the integer input from the user
  BLINK_NUMBER = Serial.parseInt();

//Setting up for loop to make the LED blink the specified amount of times from the user input
  for (j = 1; j <= BLINK_NUMBER; j = j + 1) {
    //Blinking Red LED
    digitalWrite(RED_LED, HIGH);
    delay(BLINK_TIME);
    digitalWrite(RED_LED, LOW);
    delay(BLINK_TIME);

  }

  //Printing Blink Message
  Serial.print(BLINK_MESSAGE);
  //Printing Number of inputted blinks
  Serial.println(BLINK_NUMBER);

  //Ending Serial Monitor
  Serial.end();

}
