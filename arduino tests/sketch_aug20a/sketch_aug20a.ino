#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F , 16, 2);
int flag=0;
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  lcd.setCursor(0,0);

}

void loop() {
  if(Serial.available()){
    lcd.clear();
    String c = Serial.readString();
    Serial.print(c) ;
    lcd.print(c);
    
    
  }
  delay(500);
  

}
