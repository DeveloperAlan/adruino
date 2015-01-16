
int dataPin = 2;
int latchPin = 3;
int clockPin = 4;

int leds[] = {B0111111,B0000110,B1011011,B1001111,B1100110,B1101101,B1111101,B0000111,B1111111,B1100111};

void setup() {
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  Serial.begin(9600);
}

void display(int digit) {
  
  digitalWrite(latchPin, LOW);
  Serial.println(~leds[digit]);
  shiftOut(dataPin, clockPin, MSBFIRST, !leds[digit]);  
  digitalWrite(latchPin, HIGH);

  delay(1000);
}

void loop() {
  for (int i=0; i <= 9; i++) {
    display(i);
  }
}
