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
/*********Каждому углу соответствует своё время таймера*************************/
