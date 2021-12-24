// выводим счётчик нажатий по событию
#include <EncButton.h>
EncButton<EB_TICK, 3> btn(INPUT_PULLUP);  // кнопка на D3

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();           // инициализация
  lcd.backlight();      // включить подсветку
  lcd.home();
  lcd.print("Counter: ");
}

void loop() {
  btn.tick();
  if (btn.isClick()) {
    static int count = 0;
    count++;

    lcd.setCursor(9, 0);
    lcd.print(count);
  }
}
/************************Вариант с clear*******************************/
// выводим счётчик нажатий по событию
#include <EncButton.h>
EncButton<EB_TICK, 3> btn(INPUT_PULLUP);  // кнопка на D3

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();           // инициализация
  lcd.backlight();      // включить подсветку
}

void loop() {
  btn.tick();
  if (btn.isClick()) {
    static int count = 0;
    count++;

    // очищаем и выводим текст и значение
    lcd.home();
    lcd.clear();
    lcd.print("Counter: ");
    lcd.print(count);
  }
}
