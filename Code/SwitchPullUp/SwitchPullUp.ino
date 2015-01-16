int led = 3; // Digital pin 3
int button = 4; // digital pin 4

void setup() {
  Serial.begin(9600);  // Turn serial monitor on
  pinMode(led, OUTPUT); // Make pin 3 an output
  pinMode(button, INPUT); // Make pin 4 an input
}

void loop() {
  // If button is on turn LED on
  if (digitalRead(button) == LOW) {
      digitalWrite(led,HIGH); // Turn LED on
      Serial.println("Switch on");
  }
  // Otherwise turn LED off
  else {
    digitalWrite(led,LOW); // Turn LED on
  }
}
