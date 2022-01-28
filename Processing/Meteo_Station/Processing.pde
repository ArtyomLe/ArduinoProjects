//======================ДВА СПОСОБА ИНИЦИАЛИЗАЦИИ ПОРТА=========================================
//================================== 1 =========================================================

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial

void setup() {
  size(400, 200);                // Размеры основного рабочего окна
  String str[] = Serial.list();  // Вывести доступные рабочие порты(получаем массив строк)
  print(str[0]);
}

void draw() {
}

//=================================== 2 =========================================================

int speed = 9600;

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial

void setup() {
  size(400, 200);                // Размеры основного рабочего окна
  // Инициализация порта
  String str[] = Serial.list();
  serial = new Serial (this, str[0], speed);                                        // str[0] можно заменить на "COMn" n - это номер порта 1,2,3...
}

void draw() {
}
//==================================================================================================

//========Отправляем команды на ардуино для мигания светодиодом=====================================
int speed = 9600;

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial

void setup() {
  size(400, 200);                // Размеры основного рабочего окна
  // Инициализация порта
  String str[] = Serial.list();
  serial = new Serial (this, str[1], speed); // str[1] Нужно указать верный номер порта. Скорость должна быть одинаковой
}

void draw() {
  serial.write('n');
  delay(1000);
  serial.write('f');
  delay(1000);
}
//===========================================ПОСТРОЕНИЕ МЕНЮ (1) ======================================================
int speed = 9600;

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial
// Подключение библиотеки и создание обьекта
import controlP5.*;
ControlP5 cp5;

void setup() {
  size(400, 200);                // Размеры основного рабочего окна
  cp5 = new ControlP5(this);     // Базовая инициализация

  cp5.addButton("refresh").linebreak(); // После этой кнопки новая строка
  cp5.addButton("open").linebreak();    // Получается столбик из кнопок
  cp5.addButton("close").linebreak();
  cp5.addButton("LedOn").linebreak();
  cp5.addButton("LedOff").linebreak();
  cp5.addScrollableList("comlist").close(); // Закрываем выпадающее меню чтобы не загараживало остальные кнопки основного меню 

  serial = new Serial (this, "COM9", speed); // Нужно указать верный номер порта. Скорость должна быть одинаковой
}
//================================================
void refresh() {
  String list[] = Serial.list();                            // Создаём строку
  cp5.get(ScrollableList.class, "comlist").addItems(list);  // Обращаемся к дропдаун листу и добавляем список открытых портов
}
//================================================
void draw() {
  background(120);
  /*  serial.write('n');
   delay(1000);
   serial.write('f');
   delay(1000);
   */
}
//=========================================== ПОСТРОЕНИЕ МЕНЮ (2) ======================================================
// Требуется также прошить ардуино и указать там выводы диода и команды (n, f)

int speed = 9600;
String portName;

import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial
// Подключение библиотеки и создание обьекта
import controlP5.*;
ControlP5 cp5;

void setup() {
  size(400, 200);                // Размеры основного рабочего окна
  cp5 = new ControlP5(this);     // Базовая инициализация

  cp5.addButton("refresh").linebreak(); // После этой кнопки новая строка
  cp5.addButton("open").linebreak();    // Получается столбик из кнопок
  cp5.addButton("closePort").linebreak();
  cp5.addButton("LedOn").linebreak();
  cp5.addButton("LedOff").linebreak();
  cp5.addScrollableList("comlist").close(); // Закрываем выпадающее меню чтобы не загараживало остальные кнопки основного меню
}
//================================================
void refresh() {
  String list[] = Serial.list();                            // Создаём строку
  cp5.get(ScrollableList.class, "comlist").addItems(list);  // Обращаемся к дропдаун листу и добавляем список открытых портов
}
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
  serial.write('n');
}
void LedOff() {
  serial.write('f');
}
//================================================
void draw() {
  background(120);
}
//==================================================================================================================
