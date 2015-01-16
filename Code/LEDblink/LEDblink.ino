int led = 3; // Digital output 3

void setup() {
  Serial.begin(9600); // Turn on serial monitor
  pinMode(led, OUTPUT); // Make pin 3 an output
}

void loop() {
  digitalWrite(led, HIGH); // Turn LED on
  Serial.write("ON");
  delay(1000); // Wait one second
  digitalWrite(led, LOW); // Turn LED off
  Serial.write("OFF");
  delay(1000); // Wait one second
}
