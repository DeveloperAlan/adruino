int ledR = 3;
int ledG = 5;
int ledB = 6;

double brightR = 700;
double brightG = 1300;
double brightB = 300;

double currentR = 20;
double currentG = 20;
double currentB = 20;

double brightMin = brightB;
double currentMin = currentG;

void setup() {
 pinMode(ledR, OUTPUT);
 pinMode(ledG, OUTPUT);
 pinMode(ledB, OUTPUT); 
 
 Serial.begin(9600); 
}

void loop() {
 double red =  255 * brightMin/brightR * currentR/currentMin;
 double green =  255 * brightMin/brightG * currentG/currentMin;
 double blue =  255 * brightMin/brightB * currentB/currentMin;
 
 Serial.print('R');
 Serial.print(red);
 Serial.print('G');
 Serial.print(green);
 Serial.print('B');
 Serial.println(blue);
 
 analogWrite(ledR, red);
 analogWrite(ledG, green);
 analogWrite(ledB, blue);
}
