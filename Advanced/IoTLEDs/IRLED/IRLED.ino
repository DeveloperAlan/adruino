int photo = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(photo, INPUT);
}

void loop()
{
  int value = analogRead(photo);
  Serial.println(value);
  delay(10);
}
