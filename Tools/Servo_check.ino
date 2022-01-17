#include <Servo.h>
Servo myservo;

void setup() {
  myservo.attach(3);
}

uint32_t tmr;   
int val = 0;     
int dir = 2;    // step

void loop() {
  // асинхронный таймер на миллис
  if (millis() - tmr >= 20) {
    tmr = millis();
    val += dir;                             
    if (val >= 180|| val <= 0) dir = -dir;  // 0 - 180 degree
    myservo.write(val)                      
  }
}
