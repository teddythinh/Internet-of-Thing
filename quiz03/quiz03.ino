// C++ code
//

#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
void setup()
{
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop()
{
  float value = analogRead(A0);
  float celsius = (value * 5 / 1023) / 0.01 - 50;
  Serial.println(celsius);
  lcd.setCursor(0, 1);
  lcd.print("Temp: ");
  lcd.print(celsius);
}