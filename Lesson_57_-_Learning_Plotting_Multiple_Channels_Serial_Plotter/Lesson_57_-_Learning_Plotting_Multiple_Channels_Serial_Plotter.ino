//Learning how to plot multiple channels on the serial plotter
//Declaring Variables
float SIN_VAL;
float COS_VAL;
float j;


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);
}


void loop() {
  //We need to use a for loop to set the autoscaled two desired points on our graph
  //We want the graph to increase by .01 each calculation and to start from 0
  for (j = 0; j <= 2 * 3.14159265; j = j + .01) {
    SIN_VAL = sin(j);
    COS_VAL = cos(j);
    Serial.print(SIN_VAL);
    Serial.print(",");
    Serial.println(COS_VAL);
  }
}
