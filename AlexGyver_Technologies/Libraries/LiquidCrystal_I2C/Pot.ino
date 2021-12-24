#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.home();
  lcd.print("Pot. val: ");
}

void loop() {
  static unsigned long tmr;
  if (millis() - tmr >= 100) {
    tmr = millis();            // 10 раз в секунду считываем значения потенциометра
    lcd.setCursor(10, 0);      // Pot. val: занимает 9 клеток, выводим значение с 10
    lcd.print(analogRead(A0)); // Считываем значения потенциометра
    lcd.print("   ");          // Чтобы строка оставалась пустой при смене кол-ва символов значения потенциометра
  }
}
