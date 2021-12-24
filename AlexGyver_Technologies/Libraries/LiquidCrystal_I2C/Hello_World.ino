// базовый пример инициализации и вывода текста
#include <LiquidCrystal_I2C.h>  // подключаем библиотеку
// адрес дисплея 0x3f или 0x27
// размер дисплея 16x2 (поддерживаются и другие, например 20x4)
// Шина l2C (Arduino: SDA – A4, SCL – A5)  (Wemos: SDA – D2, SCL – D1)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // адрес, столбцов, строк
void setup() {
  lcd.init();           // инициализация
  lcd.backlight();      // включить подсветку  
  lcd.setCursor(1, 0);  // столбец 1 строка 0
  lcd.print("Hello, world!");
  lcd.setCursor(4, 1);  // столбец 4 строка 1
  lcd.print("GyverKIT");
}
void loop() {
}
/***********************Выводим по буквам******************************/
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup() {
  lcd.init();           // инициализация
  lcd.backlight();      // включить подсветку  
  // строки для вывода
  char s1[] = "Hello, world!";
  char s2[] = "GyverKIT";
  lcd.setCursor(1, 0);
  for (int i = 0; i < strlen(s1); i++) {
    lcd.print(s1[i]);
    delay(100);
  }
  lcd.setCursor(4, 1);
  for (int i = 0; i < strlen(s2); i++) {
    lcd.print(s2[i]);
    delay(100);
  }
}
void loop() {
}
