/****************Step 1***********************/

#include <TimerMs.h>
TimerMs tmr(500);

void setup() {
  tmr.start();                           // Включаем таймер
  pinMode(10, OUTPUT);
  tmr.attach(func);
}

void func() {
  digitalWrite(10, !digitalRead(10));
}

void loop() {
  tmr.tick()                              // Опрашиваем таймер
}



// пин (10) 1 раз в секунду
// пин (9)  5 раз в секунду
// каждые 2 секунды принт random

/******************Step 2***********************/
#include <TimerMs.h>
TimerMs tmr(2000);                       // Включить LED через 2 секунды после запуска программы

void setup() {
  tmr.start();                           // Включаем таймер
  pinMode(10, OUTPUT);
  tmr.attach(func);                      // Режим периода
  tmr.setTimerMode();                    // Режим таймера
}

void func() {
  digitalWrite(10, 1);
}

void loop() {
  tmr.tick()                              // Опрашиваем таймер
}



// пин (10) 1 раз в секунду
// пин (9)  5 раз в секунду
// каждые 2 секунды принт random

/******************Step 3***********************/
