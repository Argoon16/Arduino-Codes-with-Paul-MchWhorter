//https://www.youtube.com/watch?v=5TitZmA66bI&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=10
//Refer to the multiple resistors practice quesiton in lesson 9
//Because we are reading analog voltage, we are not going to be using any digitalWrite, analogWrite, or connecting our circuit to any of the pin numbers
//Start the circuit by connecting a wire to the 5V slot followed by a 330ohm and 100ohm resistor and a wire connecting to the ground
//In order to read the analog voltage, we must connect a wire from the resistors to the analog inputs (ANALOG IN)(A0, A1, A2, A3, A4, A5)

//Declaring variables for analog input, voltage, and delay
int READ_PIN = A3;
//Since the Serial port reads us a scaled version of the voltage, we can convert this into an actual equation
float VOLTAGE = 0;
int DELAY_TIME = 500;
//The READ_VAL interger value does not matter. We are only setting up the variable for A3 to read and we are going to give it a new value in the "void loop"
int READ_VALUE;

//Void setup
void setup() {
  pinMode(READ_PIN, INPUT);
  //"Serial.begin" executes the serial monitor to display the analog voltage and essentailly print strings and values
  //It is followed by a number which represents the baud rate which represent how quickly the serial monitor will be communicating/updating
  Serial.begin(9600);
}

//Void loop for arduino to keep reading and printing the analog voltage
void loop() {
  //Originally, "READ_VAL" was replaced with "VOLTAGE", but we wanted a new variable to convert out scaled values into an actual voltage
  READ_VALUE = analogRead(READ_PIN);
  //Equation that converts scaled values into actual voltage
  //The reason we put "." at the end of our numbers is because we need to convert the intergers as floats
  //In arduino math, if you get a float (which is a decimal value) within an interger caclculation, you will get an interger value
  //To avoid this, we must convert our intergers into float numbers in order to get float values
  VOLTAGE = (5. / 1023.) * READ_VALUE;
            //"Serial.println" prints the analog voltage on a new line in the serial monitor
            Serial.println(VOLTAGE);
  delay(DELAY_TIME);
}
