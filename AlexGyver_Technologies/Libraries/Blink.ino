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
/***********2 LEDS мигаем с разной переодичностью*******/
