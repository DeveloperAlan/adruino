int led = 3; // Digital pin 3
int button = 4; // Digtal pin 4

void setup() {
  Serial.begin(9600); // Turn serial monitor on
  pinMode(led, OUTPUT); // Make pin 3 an output
  pinMode(button, INPUT); // Make pin 4 an input
}

void loop() {
  // If switch is on 
  if (digitalRead(button) == LOW) {
    digitalWrite(led,HIGH); // Turn LED on
    Serial.println("Switch on");
  }
  else {
    digitalWrite(led,LOW); // Turn LED off
    Serial.println("Switch off");
  }
}
