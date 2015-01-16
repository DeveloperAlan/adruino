int nocols = 5;
int norows = 7;
int cols[] = {2,3,4,5,6};
int rows[] = {7,8,9,10,11,12,13};

byte frame[] = {B1111110,B0001001,B0001001,B0001001,B1111110};

void setup() {
    for (int c=0; c < nocols; c++) {
       pinMode(cols[c], OUTPUT);
    }
    for (int r=0; r < norows; r++) {
       pinMode(rows[r], OUTPUT);
    }

    for (int c=0; c < nocols; c++) {
      for (int r=0; r < norows; r++) {
         digitalWrite(cols[c], LOW);
         digitalWrite(rows[r], HIGH);
      }
    }
   
   
  Serial.begin(9600);
}

void turnon(int col, int row) {
  digitalWrite(cols[col], HIGH);
  digitalWrite(rows[row], LOW);
}

void turnoff(int col, int row) {
  digitalWrite(cols[col], LOW);
  digitalWrite(rows[row], HIGH);
}

void display(byte data[]) {
  for (int d=0; d <100; d++) {
    for (int c=0; c < nocols; c++) {
       int col = data[c];
       int row = 1;
       int on = 0;
       for (int r=0; r < norows; r++) {
         if (col & row) {
           digitalWrite(rows[r], LOW);
           on++;  
         }
         else {
           digitalWrite(rows[r], HIGH);               
         }
         row = (row << 1);
       }      
       digitalWrite(cols[c], HIGH);
       delayMicroseconds(100*on);
       digitalWrite(cols[c], LOW);
    }
  }
}

void loop() {
  display(frame);
}
