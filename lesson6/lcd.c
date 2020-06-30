#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

String str;
void setup() {
  lcd.begin(16, 2);
  lcd.print("hello, world!");
}

void loop() 
{
  if(Serial.available()>0)
  {
    str = Serial.readString();
    lcd.setCursor(0,1);
    lcd.print(str);
  }
}
 