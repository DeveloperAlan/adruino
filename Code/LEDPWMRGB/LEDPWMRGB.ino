int ledR = 3; // Digital pin 3 red
int ledG = 5; // Digital pin 5 green
int ledB = 6; // Digital pin 6 blue

int slow = 20; // Time to wait to slow down transitions

void setup() {
  Serial.begin(9600); // Tuen serial monitor on
  pinMode(ledR, OUTPUT); // Make pin 3 an output
  pinMode(ledG, OUTPUT); // Make pin 5 an output
  pinMode(ledB, INPUT); // Make pin 6 an output 
  
}

// Fade in a LED
void fadein(int led, int time) {
  for (int i=0; i < 256; i++) {
    analogWrite(led, i);
    delayMicroseconds(time*slow); // Wait a little
  }
}

// Fade out a LED
void fadeout(int led, int time) {
  for (int i=0; i < 256; i++) {
    analogWrite(led, 256-i);
    delayMicroseconds(time*slow); // Wait a little
  }
}

void white(int led, int led2, int led3) {
  analogWrite(led, 1);
  analogWrite(led2, 1);
  analogWrite(led3, 1);
}


void loop() {
 // Each colour one at a time
// Serial.println("One at a time");
// fadein(ledR,100);
// fadeout(ledR,100);
// fadein(ledG,100);
// fadeout(ledG,100);
// fadein(ledB,100);
// fadeout(ledB,100);
 
 // Each colour two at a time
//  Serial.println("Two at a time");
// fadein(ledR,100);
// fadein(ledG,100);
// fadeout(ledR,100);
// fadeout(ledG,100);
// fadein(ledR,100);
// fadein(ledB,100); 
// fadeout(ledR,100);
// fadeout(ledB,100); 
// fadein(ledG,100);
// fadein(ledB,100);
// fadeout(ledG,100);
// fadeout(ledB,100); 
// 
// // Each colour three at a time
//  Serial.println("Three at a time");
// fadein(ledR,100);
// fadein(ledG,100);
// fadein(ledB,100);
// fadeout(ledR,100);
// fadeout(ledG,100);
// fadeout(ledB,100); 

white(ledR, ledG, ledB);

}
