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
