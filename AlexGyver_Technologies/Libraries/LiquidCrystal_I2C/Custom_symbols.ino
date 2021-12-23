// выводим кастомные символы
// https://maxpromer.github.io/LCD-Character-Creator/      (Генератор символов)

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte bell[]  = {0x4, 0xe, 0xe, 0xe, 0x1f, 0x0, 0x4};
byte note[]  = {0x2, 0x3, 0x2, 0xe, 0x1e, 0xc, 0x0};
byte clock[] = {0x0, 0xe, 0x15, 0x17, 0x11, 0xe, 0x0};
byte heart[] = {0x0, 0xa, 0x1f, 0x1f, 0xe, 0x4, 0x0};
byte duck[]  = {0x0, 0xc, 0x1d, 0xf, 0xf, 0x6, 0x0};
byte check[] = {0x0, 0x1, 0x3, 0x16, 0x1c, 0x8, 0x0};
byte cross[] = {0x0, 0x1b, 0xe, 0x4, 0xe, 0x1b, 0x0};
byte retarrow[] = {0x1, 0x1, 0x5, 0x9, 0x1f, 0x8, 0x4};

void setup() {
  lcd.init();           // инициализация
  lcd.backlight();      // включить подсветку

  // загружаем все сразу
  lcd.createChar(0, bell);
  lcd.createChar(1, note);
  lcd.createChar(2, clock);
  lcd.createChar(3, heart);
  lcd.createChar(4, duck);
  lcd.createChar(5, check);
  lcd.createChar(6, cross);
  lcd.createChar(7, retarrow);

  // выводим для примера все
  lcd.home();
  lcd.write(0);
  lcd.write(1);
  lcd.write(2);
  lcd.write(3);
  lcd.write(4);
  lcd.write(5);
  lcd.write(6);
  lcd.write(7);
}

void loop() {
}
