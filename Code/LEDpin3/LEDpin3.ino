int led = 3; // Digtal pin 3

void setup() {
  Serial.begin(9600); // Help with debugging
  pinMode(led, OUTPUT); // Make pin 3 an output
}

void loop() {
  digitalWrite(led,HIGH); // Turn LED on
  Serial.println("LED on"); // Display in serial monitor
}
