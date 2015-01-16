int nodisplays = 2;
int displays[] = {9,10};
int pins[] = {2,3,4,5,6,7,8};

byte leds[] = {B0111111,B0000011,B1011110,B1001111,B1100011,B1101101,B1111101,B0000111,B1111111,B1100111};
byte saved[] = {};

void setup() {
  for (int i=0; i < 7; i++) {
    pinMode(pins[i], OUTPUT);
  }
  for (int i=0; i < nodisplays; i++) {
    pinMode(displays[i], OUTPUT);
    saved[i] = B0000000;
  }
}

void turnoff() {
  for (int i=0; i < nodisplays; i++) {
    digitalWrite(displays[i], HIGH);
  } 
}

void turnon(int display) {
   digitalWrite(displays[display], LOW); 
}

void setleds(int digits) {
  int pos = 1;
  
  for (int i=0; i < 8; i++) {
     if (digits & pos) {
       digitalWrite(pins[i], HIGH);    
     }
     else {
       digitalWrite(pins[i], LOW);               
     }
     pos = (pos << 1);
  } 
}

void display(int display, int digit) {
  int pos = 1;
  
  saved[display] = leds[digit];
  
  for (int d =0; d < 10; d++) {
    for (int i = 0; i < nodisplays; i++) {
      turnoff();
      setleds(saved[i]);
      turnon(i); 
      delay(5);
    }
  }
}

void loop() {
  for (int d1=0; d1 <= 9; d1++) {
    for (int d2=0; d2 <= 9; d2++) {  
      display(0,d1);
      display(1,d2);
    }
  }  
}
