//https://www.youtube.com/watch?v=fJWR7dBuc18&list=PLGs0VKk2DiYw-L-RibttcvK-WBZm8WLEP&index=1
void setup() {
  // pinMode is used to turn LED's on
  pinMode(13, OUTPUT);
}

void loop() {
  // digitalWrite is used to turn LED's on
  digitalWrite(13, HIGH);
  // delay is measured in milliseconds. Without delay, the LED would just blink way too fast for the human eye to see, and will dim as a result
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}
