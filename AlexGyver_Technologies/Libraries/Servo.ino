/***************Раз в секунду задаем угол положения серво**********************/

#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(12);
}

void loop() {
  static uint32_t tmr;
  static byte mode = 0;
  if(millis() - tmr >= 1000) {
    tmr = millis();
    if(++mode >= 4) mode = 0;
    switch (mode) {
      case 0: servo.write(10); break;
      case 1: servo.write(50); break;
      case 2: servo.write(120); break;
      case 3: servo.write(170); break;
  } 
 }
}

/*********Каждому углу соответствует своё время таймера*************************/

  #include <Servo.h>
Servo servo;

void setup() {
  servo.attach(12);
}

void loop() {
  static uint32_t tmr, period;
  static byte mode = 0;
  if(millis() - tmr >= period) {
    tmr = millis();
    if(++mode >= 4) mode = 0;
    switch (mode) {
      case 0: servo.write(10); period = 200; break;
      case 1: servo.write(50); period = 400; break;
      case 2: servo.write(120); period = 800; break;
      case 3: servo.write(170); period = 1000; break;
  } 
 } 
}

/*******Каждому углу соответствует своё время таймера посредством массива*******/

#include <Servo.h>
Servo servo;

void setup() {
  servo.attach(12);

  int angls[] = {10, 50, 120, 170};     // массив угла поворота
  int prds[]  = {200, 400, 800, 1000};  // массив таймера
}

void loop() {
  static uint32_t tmr, period;
  static byte mode = 0;

  if(millis() - tmr >= prds[mode]) {
    tmr = millis();
    if(++mode >= 4) mode = 0;
    servo.write(angls[mode]);
 } 
}
/****************************************************************/
