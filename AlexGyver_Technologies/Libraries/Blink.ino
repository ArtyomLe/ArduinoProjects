/******************Используем millis() для многозадачности****************/

/***********2 LEDS мигаем с разной переодичностью*******/
void setup() {
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  ledBlink_1();
  ledBlink_2();
}

void ledBlink_1() {
  static uint32_t tmr;
  if(millis() - tmr >= 500) {
    tmr = millis();
    digitalWrite(10, !digitalRead(10));
 }
}


void ledBlink_2() {
  static uint32_t tmr;
  if(millis() - tmr >= 50) {
    tmr = millis();
    digitalWrite(9, !digitalRead(9));
 }
}
/*******Мигание происходит с переодичностью в 0.6/0.3 sec********/

void setup() {
  pinMode(10, OUTPUT);

}

void loop() {
  static uint32_t tmr;
  static bool flag;

  uint32_t period;
  if (flag) period = 300;
  else period = 600;

  if (millis() - tmr >= period) {
    tmr - millis();
    digitalWrite(10, !digitalRead(10));
    flag = !flag;
 }
}
/*******тернарный оператор*************************************/
// Мигание также происходит с переодичностью в 0.6/0.3 sec

void setup() {
  pinMode(10, OUTPUT);

}

void loop() {
  static uint32_t tmr;
  static bool flag;

  if (millis() - tmr >= flag ? 300:600) {
    tmr - millis();
    digitalWrite(10, !digitalRead(10));
    flag = !flag;
 }
}
/***************Программный ШИМ с заполнением duty = 800(1000)***********************/

void setup() {
  pinMode(10, OUTPUT);

}
int duty = 800;

void loop() {
  static uint32_t tmr;
  static bool flag;

  if (millis() - tmr >= (flag ? duty : 1000-duty)) {
    tmr - millis();
    digitalWrite(10, !digitalRead(10));
    flag = !flag;
 }
}
/**************Однократное действие спустя какое то время после старта (2 sec.)*********/

void setup() {
  pinMode(10, OUTPUT);

}
int duty = 800;

void loop() {
  static uint32_t tmr;
  static bool flag = true;

  if (flag && millis() - tmr >= 2000) {
    digitalWrite(10, HIGH);
    flag = false;
 }
}
/************************************************************************************/
// Однократное действие спустя какое то время после старта (2 sec.)
// и последующее возобновление через нажатие кнопки.

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  static uint32_t tmr;
  static bool flag = true;

  btn.tick();
  if (btn.isClick()) {
    flag = true;
    tmr = millis();
 }

  if (flag && millis() - tmr >= 2000) {
    digitalWrite(10, !digitalRead(10));
    flag = false;
 }
}
/*********************Мигаем однократо заданное кол-во раз (10)*********************************/

#include <EncButton.h>
EncButton<EB_TICK, 3> btn(INPUT_PULLUP);

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  static uint32_t tmr;
  static byte counter = 0;

  if (counter < 10 && millis() - tmr >= 400) {
    tmr = millis();
    digitalWrite(10, !digitalRead(10));
    counter++;
 }
}
/***********************************************************/
// Включение\отключение состояния процесса кнопкой

#include <EncButton.h>
EncButton<EB_TICK, 3> btn(INPUT_PULLUP);

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  static bool flag;
  btn.tick();
  if (btn.isClick()) {
     flag = !flag;
     digitalWrite(10, flag);
 }
}
/**************Включение\отключение  (диод мигает\не мигает)*********************/

#include <EncButton.h>
EncButton<EB_TICK, 3> btn(INPUT_PULLUP);

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  static bool flag;
  btn.tick();
  if (btn.isClick()) flag = !flag;
     
  static uint32_t tmr;
  if (flag && millis() - tmr >= 300) {
  tmr = millis();
  digitalWrite(10, !digitalRead(10));
 }
}
/***************************Плавное мигание************************/

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  static uint32_t tmr;
  static int dir = 5;                             // Переменная направления +-
  static int duty = 0;                            // Переменная заполнения
  if (millis() - tmr >= 20) {
    tmr = millis();
    duty += dir;
    if (duty >= 255 || duty <= 0) dir = -dir;    // меняем направление
    analogWrite(10, duty);
 }
}
/************************Плавное мигание 2 ver.***************************/

void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  static uint32_t tmr;
  static int dir = 5;                                    // Переменная направления +-
  static int duty = 0;                                   // Переменная заполнения
  if (millis() - tmr >= 20) {
    tmr = millis();
    duty += dir;
    if (duty >= 255 || duty <= 0) dir = -dir;            // меняем напрaвление
    analogWrite(10, ((long)duty * duty + 255) >> 8);     // crt gamma
 }
}
/***************************Отработка нажатий кнопки***************************/
void setup() {
  Serial.print(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  static bool flag = false;
  static uint32_t tmr;                                  // таймер дребезга   
  bool state = !digitalRead(3);
  
  if (state && !flag && millis() - tmr > 100) {         // кнопка нажата и флаг не поднят
    flag = true;                                        // поднимаем флаг
    tmr = millis();
    Serial.println("Click!"); 
}

  if (!state && flag) {                                 // кнопка не нажата и флаг поднят
    flag = false;                                       // опускаем флаг
    tmr = millis();
 }
}
/*****************************Отработка нажатий кнопки с удержанием**************/
void setup() {
  Serial.print(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  static bool flag = false;
  static uint32_t tmr;                                  // таймер дребезга   
  bool state = !digitalRead(3);
  
  if (state && !flag && millis() - tmr > 100) {         // кнопка нажата и флаг не поднят
    flag = true;                                        // поднимаем флаг
    tmr = millis();
    Serial.println("Click!"); 
  }
  if (state && !flag && millis() - tmr > 500 {          // удержание больше 0.5 сек.
    Serial.println("Hold!");
  }
  if (!state && flag) {                                 // кнопка не нажата и флаг поднят
    flag = false;                                       // опускаем флаг
    tmr = millis();
 }
}
/*******************************Изменение яркости диода с помощью одной кнопки***************************************/
void setup() {
  Serial.print(9600);
  pinMode(3, INPUT_PULLUP);
  pinMode(10, OUTPUT);
}

void loop() {
  static bool flag = false;
  static int dir = 5;                                   // Направление
  static int bri = 0;                                   // Яркость
  static uint32_t tmr, tmr2;                            // таймер дребезга   
  bool state = !digitalRead(3);
  
  if (state && !flag && millis() - tmr > 100) {         // кнопка нажата и флаг не поднят
    flag = true;                                        // поднимаем флаг
    tmr = millis();
    Serial.println("Click!"); 
    dir = -dir;                                         // При повторном нажатии на кнопку меняем направление яркости 
  }
  if (state && !flag && millis() - tmr > 500 {          // удержание больше 0.5 сек.
    Serial.println("Hold!");
    if (millis() - tmr2 >= 20)  {                       // Создаем счётчик внутри счётчика для управления яркостью диода
      tmr2 = millis();
      bri += dir;
      analogWrite(10, bri);                             // 0,5,10,15,20,24....каждые 20 милисек.
  }
  if (!state && flag) {                                 // кнопка не нажата и флаг поднят
    flag = false;                                       // опускаем флаг
    tmr = millis();
 }
}
/******************************* Четыре режима **********************/

#include <EncButton.h>
EncButton<EB_TICK, 3> btn(INPUT_PULLUP);

void setup() {
  Serial.begin(9600);
}

void loop() {
  static byte mode = 0;
  btn.tick();
  if (btn.isClick()) {
    mode++;
    if (mode >= 4) mode = 0;
//  if (++mode >= 4) mode = 0;  // Укороченная версия (убираем строку mode++;)
    Serial.println(mode);
 }
}

/********************* Добавляем switch ****************************/

#include <EncButton.h>
EncButton<EB_TICK, 3> btn(INPUT_PULLUP);

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
}

void loop() {
  static byte mode = 0;
  btn.tick();
  if (btn.isClick()) {
  if (++mode >= 4) mode = 0;
 }
 switch (mode) {
    case 0: task1(); break;
    case 1: task2(); break;
    case 2: task3(); break;
    case 3: task4(); break;
 }
}

void task1() {
  static uint32_t tmr;
  if (millis() - tmr >= 500) {
    tmr = millis();
    static bool flag;
    flag = !flag;
    digitalWrite(10, flag);
 }
}
void task2() {

}
void task3() {

}
void task4() {

}
