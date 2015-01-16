int led = 3; // Digital pin 3
int pot = 0; // Analog pin 0 

void setup() {
  Serial.begin(9600); // Turn serial monitor on
  pinMode(led, OUTPUT); // Make digital pin 3 an output
}

void loop() {  
  int value = analogRead(pot); // Read light level
  Serial.println(value); // Display in serial monitor
  digitalWrite(led, HIGH); // Turn LED on
  delay(value/4); // Small delay
  digitalWrite(led, LOW); // Turn LED off
  delay(value/4); // Small delay
}
