#include <Wire.h>

int a;

void setup()
{
  Wire.begin();             
  Serial.begin(9600);       
}

void loop()
{
  a = analogRead(A3);          
  Serial.println(a);         
  delay(500);
 
  Wire.beginTransmission(4); 
  Wire.write("ON ");         
  Wire.write(a);             
  Wire.endTransmission();    
  delay(500);                
}
