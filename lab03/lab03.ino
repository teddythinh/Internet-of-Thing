// C++ code
//

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int button = 13;
int ScreenDisplayState = 1;

void setup()
{
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  Screen1();
  Serial.begin(9600);
}

float calculateTempurature(float value) {
  float celsius = (value * 5 / 1023) / 0.01 - 50;
  return celsius;
}

void Screen1() {
  lcd.setCursor(5, 0); // (column, line)
  lcd.print("CLASS");
  lcd.setCursor(4, 1);
  lcd.print("20CLC03");
}

void Screen2() {
  lcd.setCursor(0, 0);
  lcd.print("Pham Huy Cuong");
  //lcd.display();
  //lcd.clear();
  //lcd.noDisplay();

  
  lcd.setCursor(0, 1);
  lcd.print("Thinh");
  //lcd.display();
  //lcd.clear();
  //lcd.noDisplay();
  
  lcd.setCursor(6, 1);
  lcd.print("20127335");
  //lcd.display();  
  //lcd.clear();
  //lcd.noDisplay();
  
}

void Screen3() {
  float temp = analogRead(A0);
  float result = calculateTempurature(temp);
  lcd.setCursor(2, 0);
  lcd.print("Temp: ");
  lcd.print(result);
}

void loop()
{
  int buttonState = digitalRead(button);
  if(digitalRead(button) == HIGH) {
    lcd.clear();
	delay(500);
    ScreenDisplayState+=1;
 
    if(ScreenDisplayState > 3) {
      ScreenDisplayState = 1;
    }
 
    switch(ScreenDisplayState) {
      case 1:
        lcd.clear();
        Screen1();
      	break;
      case 2: {
        lcd.clear();
        Screen2();
        break;
      }
      case 3: {
        lcd.clear();        
      	Screen3();
        break;
      }
    }
  }
}