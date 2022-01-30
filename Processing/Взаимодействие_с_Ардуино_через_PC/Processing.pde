//================================ ПОТЕНЦИОМЕТР И КНОПКА ========================================================================

int speed = 9600;
import meter.*;              // Подключаем библиотеку Meter (шкала вольтметра)
Meter m;                     //  Называем её m

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial
// Подключение библиотеки и создание обьекта
import controlP5.*;
ControlP5 cp5;
String portName ;
int potVal;                   // Переменная потенциометра
int fillVal = 0;              // Переменная кнопки

void setup() {
  size(500, 250);                // Размеры основного рабочего окна
  cp5 = new ControlP5(this);     // Базовая инициализация

  cp5.addButton("open").linebreak();    // Получается столбик из кнопок
  cp5.addButton("closePort").linebreak();
  cp5.addButton("LedOn").linebreak();
  cp5.addButton("LedOff").linebreak();
  cp5.addScrollableList("comlist").close(); // Закрываем выпадающее меню чтобы не загараживало остальные кнопки основного меню

  cp5.addColorWheel("picker", 10, 250, 100);

  m = new Meter(this, 100, 10);        // Создаём шкалу библиотеки Meter
  m.setMeterWidth(200);                     // Задаём ширину
  m.setUp(0, 1023, 0, 100, -180, 0);
  String[] scaleLabels = {"0", "20", "40", "60", "80", "100"};
  m.setScaleLabels(scaleLabels);

  String list[] = Serial.list();                            // Создаём строку
  cp5.get(ScrollableList.class, "comlist").addItems(list);  // Обращаемся к дропдаун листу и добавляем список открытых портов
}

//***********************************************************************************

void comlist(int n) {               // Принимаем номер индекса выбранной строки порта
  portName = Serial.list()[n];
}
void open() {
  serial = new Serial (this, portName, speed); // Открываем сохранённый в строке порт
}
void closePort() {
  serial.stop();
}
void LedOn() {
  serial.write("0,1;");
}
void LedOff() {
  serial.write("0,0;");
}
//************************************************************************************
void draw() {
  background(120);
  m.updateMeter(potVal);
  fill(fillVal);              // Заливка кружка в зависимости от нажатия кнопки 
  circle(340, 30, 30);


  if (serial != null) {
    if (serial.available() > 0) {
      String str = serial.readStringUntil('\n');
      if (str != null) {                           // Добавляем это условие если иногда выскакивает  null
        str = str.trim();
        String data[] = str.split(",");
        switch (int(data[0])) {
        case 0:                          // Ключ потенциометра
          potVal = int(data[1]);
          break;
        case 1:                          // Ключ кнопки(для кружка)
          fillVal = int(data[1]) * 255;  // Значение 255 нужно для цветовой заливки (между 1 и 0 нет существенной разницы)
          break;
        case 2:
          break;
        }
      }
    }
  }
}

//========================================================= ПОТЕНЦИОМЕТР И КНОПКА И RGB ======================================================================

int speed = 9600;
import meter.*;              // Подключаем библиотеку Meter (шкала вольтметра)
Meter m;                     //  Называем её m

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial
// Подключение библиотеки и создание обьекта
import controlP5.*;
ControlP5 cp5;
String portName ;
int potVal;                       // Переменная потенциометра
int fillVal = 0;                  // Переменная кнопки

void setup() {
  size(500, 600);                 // Размеры основного рабочего окна
  cp5 = new ControlP5(this);      // Базовая инициализация

  cp5.addButton("open").linebreak();           // Получается столбик из кнопок
  cp5.addButton("closePort").linebreak();
  cp5.addButton("LedOn").linebreak();
  cp5.addButton("LedOff").linebreak();
  cp5.addScrollableList("comlist").close();    // Закрываем выпадающее меню чтобы не загараживало остальные кнопки основного меню

  cp5.addColorWheel("picker", 10, 150, 300);   // Цветовое колесо для RGB диода

  m = new Meter(this, 100, 10);                // Создаём шкалу библиотеки Meter
  m.setMeterWidth(200);                        // Задаём ширину
  m.setUp(0, 1023, 0, 100, -180, 0);
  String[] scaleLabels = {"0", "20", "40", "60", "80", "100"};
  m.setScaleLabels(scaleLabels);

  String list[] = Serial.list();                            // Создаём строку
  cp5.get(ScrollableList.class, "comlist").addItems(list);  // Обращаемся к дропдаун листу и добавляем список открытых портов
}

//***********************************************************************************

void comlist(int n) {                          // Принимаем номер индекса выбранной строки порта
  portName = Serial.list()[n];
}
void open() {
  serial = new Serial (this, portName, speed); // Открываем сохранённый в строке порт
}
void closePort() {
  serial.stop();
}
void LedOn() {
  serial.write("0,1;");
}
void LedOff() {
  serial.write("0,0;");
}
void picker(int col) {        // Складываем строки по след. протоколу "1,0-255,0-255,0-255"
  String str = "1,";          // Обращаемся к RGB диоду
  str += int(red(col));       // Добавляем цвета через одноимённые функции(red, green, blue) и приравниваем к int (изначально float);
  str += ',';
  str += int(green(col));
  str += ',';
  str += int(blue(col));
  str += ';';
  if (serial != null) serial.write(str); // Если serial создан что отправляем
  println(str);              // Вывод для отладки
}

//************************************************************************************
void draw() {
  background(120);
  m.updateMeter(potVal);
  fill(fillVal);              // Заливка кружка в зависимости от нажатия кнопки 
  circle(340, 30, 30);


  if (serial != null) {
    if (serial.available() > 0) {
      String str = serial.readStringUntil('\n');
      if (str != null) {                           // Добавляем это условие если иногда выскакивает  null
        str = str.trim();
        String data[] = str.split(",");
        switch (int(data[0])) {
        case 0:                                    // Ключ потенциометра
          potVal = int(data[1]);
          break;
        case 1:                          // Ключ кнопки(для кружка)
          fillVal = int(data[1]) * 255;  // Значение 255 нужно для цветовой заливки (между 1 и 0 нет существенной разницы_)
          break;
        case 2:
          break;
        }
      }
    }
  }
}
//================================================ ПОТЕНЦИОМЕТР И КНОПКА И RGB И SERVO =========================================================

int speed = 9600;
import meter.*;              // Подключаем библиотеку Meter (шкала вольтметра)
Meter m;                     //  Называем её m

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial
// Подключение библиотеки и создание обьекта
import controlP5.*;
ControlP5 cp5;
String portName ;
int potVal;                       // Переменная потенциометра
int fillVal = 0;                  // Переменная кнопки

void setup() {
  size(500, 600);                 // Размеры основного рабочего окна
  cp5 = new ControlP5(this);      // Базовая инициализация

  cp5.addButton("open").linebreak();           // Получается столбик из кнопок
  cp5.addButton("closePort").linebreak();
  cp5.addButton("LedOn").linebreak();
  cp5.addButton("LedOff").linebreak();
  cp5.addScrollableList("comlist").close();    // Закрываем выпадающее меню чтобы не загараживало остальные кнопки основного меню
  cp5.addKnob("knob")                          // Добавляем крутилку для серво
  .setRange(0,180)
  .setRadius(30)
  ;
  cp5.addColorWheel("picker", 10, 250, 100);   // Цветовое колесо для RGB диода

  m = new Meter(this, 100, 10);                // Создаём шкалу библиотеки Meter
  m.setMeterWidth(200);                        // Задаём ширину
  m.setUp(0, 1023, 0, 100, -180, 0);
  String[] scaleLabels = {"0", "20", "40", "60", "80", "100"};
  m.setScaleLabels(scaleLabels);

  String list[] = Serial.list();                            // Создаём строку
  cp5.get(ScrollableList.class, "comlist").addItems(list);  // Обращаемся к дропдаун листу и добавляем список открытых портов
}

//***********************************************************************************

void comlist(int n) {                          // Принимаем номер индекса выбранной строки порта
  portName = Serial.list()[n];
}
void open() {
  serial = new Serial (this, portName, speed); // Открываем сохранённый в строке порт
}
void closePort() {
  serial.stop();
}
void LedOn() {
  serial.write("0,1;");
}
void LedOff() {
  serial.write("0,0;");
}
void picker(int col) {        // Складываем строки по след. протоколу "1,0-255,0-255,0-255"
  String str = "1,";          // Обращаемся к RGB диоду
  str += int(red(col));       // Добавляем цвета через одноимённые функции(red, green, blue) и приравниваем к int (изначально float);
  str += ',';
  str += int(green(col));
  str += ',';
  str += int(blue(col));
  str += ';';
  if (serial != null) serial.write(str); // Если serial создан что отправляем
  println(str);                          // Вывод для отладки
}
void knob(int val) {                     // Складываем строки для угла поворота серво по след. протоколу "2,val"
  String str = "2," + val + ';';
  if (serial != null) serial.write(str);
}

//************************************************************************************
void draw() {
  background(120);
  m.updateMeter(potVal);
  fill(fillVal);              // Заливка кружка в зависимости от нажатия кнопки 
  circle(340, 30, 30);


  if (serial != null) {
    if (serial.available() > 0) {
      String str = serial.readStringUntil('\n');
      if (str != null) {                           // Добавляем это условие если иногда выскакивает  null
        str = str.trim();
        String data[] = str.split(",");
        switch (int(data[0])) {
        case 0:                                    // Ключ потенциометра
          potVal = int(data[1]);
          break;
        case 1:                          // Ключ кнопки(для кружка)
          fillVal = int(data[1]) * 255;  // Значение 255 нужно для цветовой заливки (между 1 и 0 нет существенной разницы_)
          break;
        case 2:
          break;
        }
      }
    }
  }
}
//=========================================================================================================================
