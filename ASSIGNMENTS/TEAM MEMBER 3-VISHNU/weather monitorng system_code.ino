#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float value;
int tmp = A1;
const int hot = 75;
const int cold = 20;

void setup() {
  pinMode(tmp, INPUT);
  pinMode(8, OUTPUT); //blue LED
  pinMode(7, OUTPUT); //yellow LED
  pinMode(6, OUTPUT); //red LED
  Serial.begin(9600);
}

void loop() {
  value = analogRead(tmp)*0.004882814;
  value = (value - 0.5) * 100.0;
  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(value);
  delay(1000);
  lcd.clear();
 
 
  Serial.print("Temp: ");
  Serial.print(value);
 
  if (value < cold) { //cold
    digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    digitalWrite(6, LOW);
    Serial.println(" It's Cold.");
  }
  else if (value >= hot) { //hot
    digitalWrite(8, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    Serial.println(" It's Hot.");
  }
  else { //Normal
    digitalWrite(8, LOW);
    digitalWrite(7, HIGH);
    digitalWrite(6, LOW);
    Serial.println(" It's Normal.");
  }
  delay(10);
}