 int led = 3; // Digital pin 3

// May need to modify these values
long low = 300; // Roughtly room temp
long hi = 600; // Roughtly body temp

void setup() {
  Serial.begin(9600); // Turn serial monitor on 
  pinMode(led, OUTPUT); // Make pin 3 an output 
}

void loop() {
  int value = analogRead(0);
  
  // Map thermistor input to a value between 0 and 255 
  value = map(value, low, hi, 0, 255);
  if (value <= 263) {
    digitalWrite(led, LOW);
  } else 
    digitalWrite(led, HIGH);
  
//  analogWrite(led, value); // Set brightness of LED
  Serial.println(value);
}
