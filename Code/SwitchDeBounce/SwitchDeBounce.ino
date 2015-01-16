int led = 3; // Digital pin 3
int button = 4; // Digital pin 4
int previous = LOW; // Previous state
int time = 0; // Time since last press
int debounce = 200; // Time to wait for signal to settle

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT); // Make pin 3 an output
  pinMode(button, INPUT); // Make pin 4 an input
}

void loop() {
  int reading = digitalRead(button);
  
  // If button chnage and a certain amount of time has passed
  if (reading != previous && millis() - time > debounce) {
    if (reading == LOW) {
      digitalWrite(led,HIGH); // Turn LED on
      Serial.println("Switch on");
    }
    else {
      digitalWrite(led,LOW); // Turn LED off
      Serial.println("Switch off");
    }
    time = millis(); // Get current time
  }
    
  previous = reading;
}
