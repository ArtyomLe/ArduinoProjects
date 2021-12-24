
  print(data);          // вывести (любой тип данных)
setCursor(x, y);      // курсор на (столбец, строка)
clear();              // очистить дисплей
home();               // аналогично setCursor(0, 0)
noDisplay();          // отключить отображение
display();            // включить отображение
blink();              // мигать курсором на его текущей позиции
noBlink();            // не мигать
cursor();             // отобразить курсор
noCursor();           // скрыть курсор
scrollDisplayLeft();  // подвинуть экран влево на 1 столбец
scrollDisplayRight(); // подвинуть экран вправо на 1 столбец
backlight();          // включить подсветку
noBacklight();        // выключить подсветку
createChar(uint8_t, uint8_t[]);                     // создать символ
createChar(uint8_t location, const char *charmap);  // создать символ
