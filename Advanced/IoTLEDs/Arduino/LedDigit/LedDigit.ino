int pins[] = {2,3,4,5,6,7,8};
int leds[] = {B0111111,B0000110,B1011011,B1001111,B1100110,B1101101,B1111101,B0000111,B1111111,B1100111};

void setup() {
  for (int i=0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
}

void display(int digit) {
  int pos = 1;
  
  for (int i=0; i < 7; i++) {
     if (leds[digit] & pos) {
       digitalWrite(pins[i], LOW);    
     }
     else {
       digitalWrite(pins[i], HIGH);               
     }
     pos = (pos << 1);
  }
  
  delay(1000);
}

void loop() {
  for (int i=0; i <= 9; i++) {
    display(i);
  }
}
