int led = 3; // Digital output 13
int led1 = 4;

void setup() {
  Serial.begin(9600); // Turn on serial monitor
  pinMode(led, OUTPUT);
  pinMode(led1, INPUT);  // Make pin 13 an output  
}

void loop() {
  digitalWrite(led,HIGH); // Turn LED on
  Serial.println("LED on");
  delay(1000);
  digitalWrite(led1, LOW); //Turn LED off
  Serial.println("LED off");
  delay(1000);
}
