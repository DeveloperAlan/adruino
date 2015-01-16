
int data = 2;
int clock = 3;
int latch = 4;
int enable = 5;

int leds[] = {B0111111,B0000110,B1011011,B1001111,B1100110,B1101101,B1111101,B0000111,B1111111,B1100111};

void setup() {
  Serial.begin(9600);
  
  pinMode(data, OUTPUT);
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(enable, OUTPUT);
  
  digitalWrite(data, LOW);
  digitalWrite(latch, LOW);
  digitalWrite(clock, LOW);
  digitalWrite(enable, HIGH);
}

void setMode(boolean special) {
    digitalWrite(latch, LOW);
    digitalWrite(clock, LOW);
    digitalWrite(enable, HIGH);
    digitalWrite(enable, LOW);
    digitalWrite(clock, HIGH);
    digitalWrite(enable, HIGH);
    digitalWrite(clock, LOW);
    digitalWrite(clock, HIGH);
    digitalWrite(clock, LOW);
    digitalWrite(latch, special ? HIGH : LOW);
    digitalWrite(clock, HIGH);
    digitalWrite(latch, LOW);
    digitalWrite(clock, LOW);
}

void setCurrent(int value) {
    setMode(true);
    digitalWrite(data, LOW);
    digitalWrite(clock, LOW);
    shiftOut(data, clock, LSBFIRST, value);
    digitalWrite(latch, HIGH);
    digitalWrite(latch, LOW);
    digitalWrite(data, LOW);
    digitalWrite(clock, LOW);
    setMode(false);
}

void display(int digit) {
  Serial.println(digit);
  digitalWrite(enable, LOW);
  digitalWrite(data, LOW);
  digitalWrite(clock, LOW);
  shiftOut(data, clock, LSBFIRST, leds[0]);
  digitalWrite(latch, HIGH);
  digitalWrite(latch, LOW);
  digitalWrite(data, LOW);
  digitalWrite(clock, LOW);

  delay(200);
}

void loop() {
  for (int i=0; i <= 9; i++) {
    display(i);
  }
}
