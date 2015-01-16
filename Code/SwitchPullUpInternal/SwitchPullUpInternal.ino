int led = 3; // Digital pin 3
int button = 4; // Digital pin 4

void setup() {
  Serial.begin(9600); // Turn serial monitor n
  pinMode(led, OUTPUT); // Make pin 3 an output
  pinMode(button, INPUT); // Make pin 4 an input
  digitalWrite(button, HIGH); // Turn on internal resistor
}

void loop() {
  // If switch is on turn LED on
  if (digitalRead(button) == LOW) {
    digitalWrite(led,HIGH); // Turn LED on
    Serial.println("Switch on");
  }
  else {
    digitalWrite(led,LOW); // Turn LED off
  }
}
