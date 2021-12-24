#define _LCD_TYPE 1  // для работы с I2C дисплеями
#include <LCD_1602_RUS_ALL.h>
LCD_1602_RUS lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2, 0);
  lcd.print("Привет,");
  lcd.setCursor(4, 1);
  lcd.print("Говноед!");
}

void loop() {
}
