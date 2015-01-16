int led = 3; // Digital pin 3

void setup() {
  pinMode(led, OUTPUT); // Turn LED pin 
}

// Fade in LED 
void fadein(int time) {
  for (int i =0; i < 256; i++) {
    analogWrite(led, i);
    delayMicroseconds(time*4); // Delay a very small amount of time
  }
}

// Fade out LED 
void fadeout(int time) {
  for (int i =0; i < 256; i++) {
    analogWrite(led, 255-i);
    delayMicroseconds(time*4); // Delay a very small amount of time
  }
}

void loop() {
  fadein(2000);
  delay(1000); // Wait a second
  fadeout(2000);
  delay(1000); // Wait a second
}
