//Declaring Variables
int EXAMPLE = 1;
int DELAY = 750;
int x = 3;
int y = 7;
int z;
float pi = 3.14;
float r = 2;
float area;
//A string is pretty much just a word
//Numbers and words can be stored as strings if you don't want to store them as intergers
//Strings must have quotation marks around them
//Declaring string
String MYSTRING = "EXAMPLE = ";

void setup() {
  //Running the Serial Monitor with "Serial.begin
  //The number after the command "(9600)" is the baud rate
  //The higher or lower the baud rate, the faster or slower the serial monitor will print values
  Serial.begin(9600);

}

void loop() {
  Example();
  Variables();
  Pi();
}

void Example() {
  //Printing "MYSTRING"
  Serial.print(MYSTRING);
  //Telling the Serial Monitor to print the values and on a new line
  Serial.println(EXAMPLE);
  //Adding one to "EXAMPLE" each time
  EXAMPLE = EXAMPLE + 1;
  delay(DELAY);
}

void Variables() {
  z = x + y;
  Serial.print(x);
  Serial.print(" + ");
  Serial.print(y);
  Serial.print(" = ");
  Serial.println(z);
  delay(DELAY);
}

void Pi() {
  area = pi * r * r;
  r = r + .5;
  Serial.print("A Circle with a Radius ");
  Serial.print(r);
  Serial.print(" Has an Area of ");
  Serial.print(area);
  Serial.println(".");
  delay(DELAY);
}
