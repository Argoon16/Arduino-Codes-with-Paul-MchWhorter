//We are learning how to use Temperature/Humidity Sensor
//Including Library
#include <DHT.h>
//We also need to Tell Arduino what Sensor we are using
#define Type DHT11

//Declaring Variables
int SENSOR_PIN = 2;
int START_TIME = 500;
int DELAY = 500;

float HUMIDITY;
float TEMP_C;
float TEMP_F;

String HUMIDITY_MESSAGE = "Humidity: ";
String TEMP_C_MESSAGE = "Temperature in Celcius: ";
String TEMP_F_MESSAGE = "Temperature in Fahrenheit: ";
String SPACE = " ";

//Setting up Sensor Variable
DHT HT(SENSOR_PIN, Type);


void setup() {
  //Starting Serial Monitor
  Serial.begin(9600);

  //Starting Sensor
  HT.begin();
  //Let's be safe and give the sensor some time to start up
  delay(DELAY);
}


void loop() {
  //Reading Humidity
  HUMIDITY = HT.readHumidity();

  //Reading Celcius Temperature
  TEMP_C = HT.readTemperature();
  //Reading Fahrenheit Temperature
  TEMP_F = HT.readTemperature(true);

  //Printing Values
  Serial.print(HUMIDITY_MESSAGE);
  Serial.print(HUMIDITY);
  Serial.print(SPACE);
  Serial.print(TEMP_C_MESSAGE);
  Serial.print(TEMP_C);
  Serial.print(SPACE);
  Serial.print(TEMP_F_MESSAGE);
  Serial.println(TEMP_F);
  delay(DELAY);
}
