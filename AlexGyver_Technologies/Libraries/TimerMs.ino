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
