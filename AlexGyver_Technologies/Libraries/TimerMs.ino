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

#include <TimerMs.h>

TimerMs tmr1(500, true);
TimerMs tmr2(100, true);
TimerMs trm3(2000, true);                     

void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
}

void loop() {
  if (tmr1.tick()) digitalWrite(10, !digitalRead(10));
  if (tmr2.tick()) digitalWrite(9,  !digitalRead(9));
  if (tmr3.tick()) Serial.println(random(100));
}



// пин (10) 1 раз в секунду
// пин (9)  5 раз в секунду
// каждые 2 секунды принт random
