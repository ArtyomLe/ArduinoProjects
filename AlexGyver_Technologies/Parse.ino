//===============Управнеие яркостью светодиода через парсинг======================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(5, OUTPUT);
}

void loop() {
  if(Serial.available()) {
    int value = Serial.parseInt();
    analogWrite(5, value);              // Приниманиемые значения Serial monitor 0-1023
    Serial.println(value);
  }
}
//======================================Управление 2 светодиодами=====================================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if (Serial.available() > 1) {     // Если получаем как минимум два значения в порт(a0-1023,b0-1023)
    char key = Serial.read();       // Читаем и запоминаем символ
    int value = Serial.parseInt();  // Парсим оставшиеся число
    switch (key) {
      case 'a': analogWrite(5, value);
        break;
      case 'b': analogWrite(10, value);
        break;
    }
  }
}
//====================================Парсим rgb led================================================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(15);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (Serial.available() > 1) {     // Если получаем как минимум два значения в порт(r0-255,g0-255,b0-255)
    char key = Serial.read();       // Читаем и запоминаем символ
    int value = Serial.parseInt();  // Парсим оставшиеся число
    switch (key) {
      case 'r': analogWrite(3, value);
        break;
      case 'g': analogWrite(5, value);
        break;
      case 'b': analogWrite(6, value);
        break;
    }
  }
}
//=========================================================================================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
}

/* 
Serial.readBytesUntil(character, buffer, length)

Читает данные из порта и закидывает их в буфер buffer (массив char [] или byte []), также указывается количество байт, который нужно записать – length 
(чтобы не переполнить буфер) и терминальный символ character. Окончание приёма в buffer происходит при достижении заданного количества length,
при приёме терминального символа character (он в буфер не идёт) или по таймауту
*/

void loop() {
 if(Serial.available()) {
  char data[30];
  int amount = Serial.readBytesUntil(';', data, 30); // Эта функция записывает получаемые данные в указанный массив char указанного размера.
                                                     // после указания терминатора ; данные выводятся сразу без задержи Timeout
  data[amount] = NULL;                               // Закрываем строку для корректного вывода содержимого буффера
  Serial.println(data);
 }
}
//===============================================Если парсинг состоит из чисел разделённых запятой=================================================================
//ОБШИЙ ВИД ПЕРЕДАВАЕМЫХ ДАННЫХ: 123,456,789;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
}

void loop() {
  if (Serial.available()) {
    char str[30];
    int amount = Serial.readBytesUntil(';', str, 30);
    str[amount] = NULL;    // Определяем общую длинну данных

    int value[10];         // Буфер значений
    int count = 0;         // Счётчик значений
    char* off = str;       // Указатель

    while (true) {
      value[count++] = atoi(off); // Пишем число в буфер
      off = strchr(off, ',');     // Поиск следующей запятой
      if (off) off++;             // Если не NULL то продолжаем
      else break;                 // Иначе выход из цикла
    }
    for (int i = 0; i < count; i++) {
      Serial.println(value[i]);       // Вывод в буфер
    }
  }
}
//===========================================Если парсинг состоит из чисел и букв разделённых запятой=================================================
//ОБШИЙ ВИД ПЕРЕДАВАЕМЫХ ДАННЫХ: 123,as4,Ad9;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
}

void loop() {
  if (Serial.available()) {
    char str[30];
    int amount = Serial.readBytesUntil(';', str, 30);
    str[amount] = NULL;    // Определяем общую длинну данных

    char* ptrs[10];        // Указатели на строки
    int count = 0;         // Счётчик подстрок
    char* off = str;       // Указатель для работы

    while (true) {
      ptrs[count++] = off;        // Запоминаем указатель
      off = strchr(off, ',');     // Поиск следующей запятой
      if (off) {                  // Если не NULL
        *off = NULL;              // Заменяем запятую на NULL
        off++;                    // Продолжаем
      }
      else break;                 // Иначе выход из цикла
    }
    for (int i = 0; i < count; i++) {
      Serial.println(ptrs[i]);     // Вывод в буфер
    }
  }
}
//======ДОП. ПРИМЕР ДЛЯ ПАРСИНГА ЧЕРЕЗ БИБЛИОТЕКУ ГАЙВЕРА (Parser.h)=====================

 Parser data(str, ',');  // Передаём строку на обработку(парсинг)
 int am = data.split();  // Метод возвращает кол-во принятых подстрок и разделяет строку 
 // Выводим все подстроки
 for (int i = 0; i < am; i++) Serial.println(data[i]); 

      *       *       *       *

 Parser data(str, ',');          // Передаём строку на обработку
 int ints[10];                   // В случае ожидания чисел для парсинга 
 int am = data.parseInts(ints);  // Раскидываем строку в указанный массив и возвращает кол-во чисел
 for (int i = 0; i < am; i++) Serial.println(ints[i]); 

//=======================================ПРИМЕНЕНИЕ Parser.h==========================================

#include "Parser.h"
#include "Servo.h"
Servo servo;

#define R_PIN 3
#define G_PIN 5
#define B_PIN 6

#define LED_1 7
#define LED_2 8
#define SRV_PIN 9

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
  
  pinMode(R_PIN, OUTPUT);
  pinMode(G_PIN, OUTPUT);
  pinMode(B_PIN, OUTPUT);
  pinMode(LED_1, OUTPUT);
  pinMode(LED_2, OUTPUT);
  servo.attach(SRV_PIN);
}

/* 
Протокол:
0 - светодиод   0/1 
1 - светодиод2  0/1
2 - RGB (0...255, 0...255, 0...255)
3 - Servo (0...180)
*/

void loop() {
  char str[30];
  int amount = Serial.readBytesUntil(';', str, 30);
  str[amount] = NULL;
  Parser data(str, ',');
  int ints[5];
  int am = data.parseInts(ints);

  switch (ints[0]) {    // Ключ
    case 0: digitalWrite(LED_1, ints[1]); break;
    case 1: digitalWrite(LED_2, ints[1]); break;
    case 2: 
     digitalWrite(R_PIN, ints[1]);
     digitalWrite(G_PIN, ints[2]);
     digitalWrite(B_PIN, ints[3]);
       break;
    case 3: servo.write(ints[1]); break;
  }
}
//================================== Управление между 2 ардуино(RX/TX) =====================================
// Transmiter
#include <GyverButton.h>
GButton btn(3);                  // Контакт кнопки на Digital 3

void setup() {
 Serial.setup(9600);
}

void loop() {

  btn.tick();
 if (btn.isClick()) {
   static bool flag = 0;
   flag = !flag;            //При каждом нажатии кнопки инвертируем состояние
   Serial.print("0, ");
   Serial.print(flag);
   Serial.print(';');
 }

 static uint32_t tmr = 0;
 if(millis() - tmr > 50) {        // Опрос 20 раз в секунду
  tmr = millis();
  Serial.print("3, ");
  int val = analogRead(0);        // Контакт poten. на Analog 0
  val = map(val, 0, 1023, 0, 180);
  Serial.print(val);
  Serial.print(';');
 }
}
//======================================Время на чтение данных================================
void loop() {
  
  if (Serial.available()) {
    char str[30];
    uint32_t ms = millis();
    int amount = Serial.readBytesUntil(';', str, 30);
    Serial.println(millis() - ms);
  }
}
//===================================================================================
