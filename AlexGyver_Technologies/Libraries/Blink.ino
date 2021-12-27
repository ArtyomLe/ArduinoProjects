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
/*******Мигание происходит с переодичностью в 0.6/0.3 sec********/
