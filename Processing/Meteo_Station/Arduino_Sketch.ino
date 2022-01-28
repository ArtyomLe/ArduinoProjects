void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    switch(c) {
      case 'n':
      digitalWrite(13, HIGH);
      break;
      case 'f':
      digitalWrite(13, LOW);
      break;
    }
  }
}
//==========================ВЕРСИЯ С ПРОТОКОЛОМ===========================
#define POT 0
#define BTN 3

#include <EncButton.h>      // Подключение библиотек
#include <GParser.h>
EncButton<EB_TICK, 3> btn;  // Инициализация кнопки на 3 контакте и назовём btn
bool flag = 0;

/* Ключи (с ардуино на ПК)
    0 - Потенциометр;
    1 - Кнопка;

    Ключи (С ПК на ардуино)
    0 - LED (13)
*/

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buff[50];                         // Сколько максимум символов будет в протоколе
    Serial.readBytesUntil(';', buff, 50);  // Окончание строки значений (терминатор) делаем ;
    GParser dat(buff, ',');                // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser 
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0: digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1] 
        break;
    }
  }

  btn.tick();                          // Инициализация кнопки в цикле
  static uint32_t tmr = 0;
  if (millis() - tmr > 100) {
    tmr = millis();
    Serial.print(0);
    Serial.print(',');
    Serial.println(analogRead(POT));
  }

  if (btn.isClick()) {                 // Если кнопка была кликнута
    flag = !flag;
    Serial.print(1);
    Serial.print(',');
    Serial.println(flag);
  }
}
//=================================================================================================================
