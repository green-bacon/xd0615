void setup()
{
  int i=0;
  for(i=0;i<10;i++)
  {pinMode(i, OUTPUT);}
}

void loop()
{
  int i=0;
  digitalWrite(2*i, HIGH);
  digitalWrite(2*i+1, HIGH);
  delay(1000); 
  for(i=1;i<5;i++)
  {
  digitalWrite(2*i, HIGH);
  digitalWrite(2*i+1, HIGH);
  digitalWrite(2*i-2, LOW);
  digitalWrite(2*i-1, LOW);
  delay(1000); 
  }
  digitalWrite(2*i-2, LOW);
  digitalWrite(2*i-1, LOW);
}