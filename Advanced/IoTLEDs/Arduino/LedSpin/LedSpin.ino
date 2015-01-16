
int pins[] = {2,3,4,5,6,7};

void setup() {
  for (int l=0; l < 6; l++) {
    pinMode(pins[l], OUTPUT);
  }
}

void loop() {
  for (int l=0; l < 6; l++) {
     digitalWrite(pins[l], HIGH);
     delay(40);    
     digitalWrite(pins[l], LOW);               
  }

}
