//We are making a toggetable Red LED using a pull up resistor push button
//Declaring Variables
int RED_LED = 6;
int BUTTON_PIN = 11;
int DELAY = 100;
String MESSAGE_1 = "Button old is a: ";
String MESSAGE_2 = "Button new is a: ";

//We have to keep track if the LED is on or off
//When we first start the program, the LED will be stored as a 0 and be off
int LED_STATE = 0;

//We have to keep track of what the value of the button is now
int BUTTON_NEW;

//We also have to keep track of what the value of the button was before
//When we first start the program, the old value of the button is 1
int BUTTON_OLD = 1;

void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
  //Starting Button Read Pin
  pinMode(BUTTON_PIN, INPUT);
  //Starting Red LED
  pinMode(RED_LED, OUTPUT);
}

void loop() {
  //Reading New Value from button pin
  BUTTON_NEW = digitalRead(BUTTON_PIN);

  //If the old value was a 0, and the new value is 1, then we want to switch
  //To switch is to execute the if statements accordingly AND THEN change/switch the LED state
  if (BUTTON_OLD == 0 && BUTTON_NEW == 1) {
    //If the LED was off, turn it on
    if (LED_STATE == 0) {
      digitalWrite(RED_LED, HIGH);
      //Now, Change the LED State to "on"
      LED_STATE = 1;
    }
    //If the LED was on, turn it off
    else {
      digitalWrite(RED_LED, LOW);
      //Now, turn the LED State to "off"
      LED_STATE = 0;
    }
  }
  //Now, we need to give the old value the new value
  //This is so the if statements can execute, since we need button old to be a 0
  //And then we push the button, we will read a 0, since button new reads a 0
  //When the loop restarts, button old will be a zero, and button new will be a 1 as soon as we let go of the button
  //This will make the if statement execute
  BUTTON_OLD = BUTTON_NEW;
  
  //We need a little bit of delay
  //Pushbuttons sort of malfunction as we push them down, and sort of turn on and off really quickly
  //This is called bouncing a switch
  //Adding a delay will fix this problem
  delay(DELAY);

  //Printing Messages to see how program works
  Serial.print(MESSAGE_1);
  Serial.println(BUTTON_OLD);
  Serial.print(MESSAGE_2);
  Serial.println(BUTTON_NEW);
}
