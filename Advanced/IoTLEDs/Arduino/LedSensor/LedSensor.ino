int LEDA = 2;
int LEDB = 3;
int LEDC = 4;

void setup() {
  // No need to set LADA or LEDB
  pinMode(LEDC, OUTPUT);
   
  Serial.begin(9600);
}

void loop() {
  // Turn LED on
  pinMode(LEDA,OUTPUT);
  pinMode(LEDB,OUTPUT);  
  digitalWrite(LEDA, HIGH);
  digitalWrite(LEDB, LOW);
  
  // Try range 100 - 5000
  delayMicroseconds(500);
  
  // Reverse bias LED
  digitalWrite(LEDA, LOW);
  digitalWrite(LEDB, HIGH);
  
  // Workout how long it take to got from 1 to 0
  pinMode(LEDB,INPUT);
  long value = 0;
  while (digitalRead(LEDB) != 0) {  
    value++;
  }
  
  // Will vary from 200 - 20000 depening on light conditions and LED
  if (value > 15000) {
    digitalWrite(LEDC, HIGH);
  }
  else {
    digitalWrite(LEDC, LOW);
  } 
      
  Serial.println(value, DEC);
}
