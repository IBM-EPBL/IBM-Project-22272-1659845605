int sensor=9;
int Buzzer=11;
int led=10;

void setup()
{
  Serial.begin(9600);
  pinMode(Buzzer,OUTPUT);
  pinMode(led,OUTPUT);
  pinMode(sensor,INPUT);
}

void loop()
{
  if(digitalRead(sensor)==HIGH)
  {
    digitalWrite(Buzzer,HIGH);
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(Buzzer,LOW);
    digitalWrite(led,LOW);
  }
}
