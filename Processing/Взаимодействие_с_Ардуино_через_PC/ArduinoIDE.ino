//======================================= ПОТЕНЦИОМЕТР КНОПКА ============================================================

#define POT 1
#define BTN 3
#define LED_R 9
#define LED_G 10
#define LED_B 11

#include <EncButton.h>      // Подключение библиотек
#include <GParser.h>
EncButton<EB_TICK, BTN> btn;  // Инициализация кнопки на 3 контакте и назовём btn
bool flag = 0;

/* Ключи (с ардуино на ПК)
    0 - Потенциометр;
    1 - Кнопка;

    Ключи (С ПК на ардуино)
    0 - LED (13)
    1 - r,g,b
*/

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buf[50];                          // Сколько максимум символов будет в протоколе
    Serial.readBytesUntil(';', buf, 50);   // Окончание строки значений (терминатор) делаем ;
    GParser dat(buf, ',');                 // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0: digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1]
        break;
      case 1:
        break;
    }
  }

  btn.tick();                          // Инициализация кнопки в цикле
  static uint32_t tmr = 0;
  if (millis() - tmr > 100) {
    tmr = millis();
    Serial.print(0);
    Serial.print(',');
    Serial.println(analogRead(POT));   // Читаем значения с потенциометра для дальнейшего парсинга в processing
  }

  if (btn.isClick()) {                 // Если кнопка была кликнута
    flag = !flag;
    Serial.print(1);
    Serial.print(',');
    Serial.println(flag);
  }
}

//================= ПОТЕНЦИОМЕТР КНОПКА RGB LED ====================================================================

#define POT 1
#define BTN 3
#define LED_R 9
#define LED_G 10
#define LED_B 11

#include <EncButton.h>      // Подключение библиотек
#include <GParser.h>
EncButton<EB_TICK, BTN> btn;  // Инициализация кнопки на 3 контакте и назовём btn
bool flag = 0;

/* Ключи (с ардуино на ПК)
    0 - Потенциометр;
    1 - Кнопка;

    Ключи (С ПК на ардуино)
    0 - LED (13)
    1 - r,g,b
*/

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buf[50];                          // Сколько максимум символов будет в протоколе
    int num = Serial.readBytesUntil(';', buf, 50);   // Окончание строки значений (терминатор) делаем ;
    buf[num] = NULL;                          // Записываем нулевой символ (NULL) в ячейку последней принятой строки для корректного определенния конца строки во время парсинга
    GParser dat(buf, ',');                 // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0: digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1]
        break;
      case 1:
        analogWrite(LED_R, ints[1]);
        analogWrite(LED_G, ints[2]);
        analogWrite(LED_B, ints[3]);
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

//============== ПОТЕНЦИОМЕТР И КНОПКА И RGB И SERVO ===========================================================================================
#define POT 1
#define BTN 3
#define LED_R 9
#define LED_G 10
#define LED_B 11
#define SRV_PIN 2

#include <Servo.h>             // Подключение библиотек
Servo servo;                   // Инициализируем серво
#include <EncButton.h>
#include <GParser.h>
EncButton<EB_TICK, BTN> btn;  // Инициализация кнопки на 3 контакте и назовём btn
bool flag = 0;


/* Ключи (с ардуино на ПК)
    0 - Потенциометр;
    1 - Кнопка;

    Ключи (С ПК на ардуино)
    0 - LED (13)
    1 - r,g,b
    2 - angle(0-180)
*/

void setup() {
  Serial.begin(9600);
  servo.attach(SRV_PIN);
  pinMode(13, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buf[50];                          // Сколько максимум символов будет в протоколе
    int num = Serial.readBytesUntil(';', buf, 50);   // Окончание строки значений (терминатор) делаем ;
    buf[num] = NULL;                          // Записываем нулевой символ (NULL) в ячейку последней принятой строки для корректного определенния конца строки во время парсинга
    GParser dat(buf, ',');                 // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0:
        digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1]
        break;
      case 1:
        analogWrite(LED_R, ints[1]);
        analogWrite(LED_G, ints[2]);
        analogWrite(LED_B, ints[3]);
        break;
      case 2:
        servo.write(ints[1]);
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
//================================================ ПОТЕНЦИОМЕТР И КНОПКА И RGB И SERVO И ФОТОРЕЗИСТОР ============================================================
#define POT A0
#define BTN 3
#define LED_R 9
#define LED_G 10
#define LED_B 11
#define SRV_PIN 2
#define PHOTO A2

#include <Servo.h>             // Подключение библиотек
Servo servo;                   // Инициализируем серво
#include <EncButton.h>
#include <GParser.h>
EncButton<EB_TICK, BTN> btn;  // Инициализация кнопки на 3 контакте и назовём btn
bool flag = 0;


/* Ключи (с ардуино на ПК)
    0 - Потенциометр и Фоторезистор в одном пакете
    1 - Кнопка;

    Ключи (С ПК на ардуино)
    0 - LED (13);
    1 - r,g,b;
    2 - angle(0-180);
*/

void setup() {
  Serial.begin(9600);
  servo.attach(SRV_PIN);
  pinMode(13, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buf[50];                          // Сколько максимум символов будет в протоколе
    int num = Serial.readBytesUntil(';', buf, 50);   // Окончание строки значений (терминатор) делаем ;
    buf[num] = NULL;                          // Записываем нулевой символ (NULL) в ячейку последней принятой строки для корректного определенния конца строки во время парсинга
    GParser dat(buf, ',');                 // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0:
        digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1]
        break;
      case 1:
        analogWrite(LED_R, ints[1]);
        analogWrite(LED_G, ints[2]);
        analogWrite(LED_B, ints[3]);
        break;
      case 2:
        servo.write(ints[1]);
        break;
    }
  }

  btn.tick();                          // Инициализация кнопки в цикле
  static uint32_t tmr = 0;
  if (millis() - tmr > 100) {
    tmr = millis();
    Serial.print(0);
    Serial.print(',');
    Serial.print(analogRead(POT));
    Serial.print(',');
    Serial.println(analogRead(PHOTO));
  }

  if (btn.isClick()) {                 // Если кнопка была кликнута
    flag = !flag;
    Serial.print(1);
    Serial.print(',');
    Serial.println(flag);
  }
}
//====================================================================== ПОТЕНЦИОМЕТР И КНОПКА И RGB И SERVO И ФОТОРЕЗИСТОР И ТЕРМИСТОР =======================================
#define POT A0
#define BTN 3
#define LED_R 9
#define LED_G 10
#define LED_B 11
#define SRV_PIN 2
#define PHOTO A2
#define THERM 12

#include <OneWire.h>
OneWire term(THERM);

#include <DallasTemperature.h>
DallasTemperature Tsensor(&term);

#include <Servo.h>             // Подключение библиотек
Servo servo;                   // Инициализируем серво

#include <EncButton.h>
#include <GParser.h>

EncButton<EB_TICK, BTN> btn;  // Инициализация кнопки на 3 контакте и назовём btn
bool flag = 0;
float Celsius = 0;

/* Ключи (с ардуино на ПК)
    0 - Потенциометр и Фоторезистор и Термистор в одном пакете
    1 - Кнопка;

    Ключи (С ПК на ардуино)
    0 - LED (13);
    1 - r,g,b;
    2 - angle(0-180);
*/

void setup() {
  Serial.begin(115200);
  Tsensor.begin();
  servo.attach(SRV_PIN);
  pinMode(13, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {
  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buf[50];                          // Сколько максимум символов будет в протоколе
    int num = Serial.readBytesUntil(';', buf, 50);   // Окончание строки значений (терминатор) делаем ;
    buf[num] = NULL;                          // Записываем нулевой символ (NULL) в ячейку последней принятой строки для корректного определенния конца строки во время парсинга
    GParser dat(buf, ',');                 // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0:
        digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1]
        break;
      case 1:
        analogWrite(LED_R, ints[1]);
        analogWrite(LED_G, ints[2]);
        analogWrite(LED_B, ints[3]);
        break;
      case 2:
        servo.write(ints[1]);
        break;
    }
  }

  btn.tick();                           // Инициализация кнопки в цикле
  static uint32_t tmr = 0;
  if (millis() - tmr > 100) {
    tmr = millis();
    Serial.print(0);
    Serial.print(',');
    Serial.print(analogRead(POT));
    Serial.print(',');
    Serial.print(analogRead(PHOTO));
    Serial.print(',');
    
    Tsensor.requestTemperatures();
    Celsius = Tsensor.getTempCByIndex(0);
    Serial.println(Celsius);            // Читаем показания с термистра
  }

  if (btn.isClick()) {                  // Если кнопка была кликнута
    flag = !flag;
    Serial.print(1);
    Serial.print(',');
    Serial.println(flag);
  }
}
//================================== ПОТЕНЦИОМЕТР И КНОПКА И RGB И SERVO И ФОТОРЕЗИСТОР И ТЕРМИСТОР И ДЖОЙСТИК ========================================
#define POT A0         // Контакт потенциометра
#define BTN 3          // Контакт кнопки
#define LED_R 9        // Контакт LED RGB
#define LED_G 10       // Контакт LED RGB
#define LED_B 11       // Контакт LED RGB
#define SRV_PIN 2      // Контакт серво
#define PHOTO A2       // Контакт фоторезистора
#define THERM 12       // Контакт термистора
#define JOYX A6        // Контакт джойстика Х
#define JOYY A7        // Контакт джойстика Y

#include <OneWire.h>
OneWire term(THERM);

#include <DallasTemperature.h>
DallasTemperature Tsensor(&term);

#include <Servo.h>             // Подключение библиотек
Servo servo;                   // Инициализируем серво

#include <EncButton.h>
#include <GParser.h>

EncButton<EB_TICK, BTN> btn;  // Инициализация кнопки на 3 контакте и назовём btn
bool flag = 0;
float Celsius = 0;

/* Ключи (с ардуино на ПК)
    0 - Потенциометр и Фоторезистор и Термистор в одном пакете
    1 - Кнопка;
    2 - joyX, joyY (джойстик)

    Ключи (С ПК на ардуино)
    0 - LED (13);
    1 - r,g,b;
    2 - angle(0-180);
*/

void setup() {
  Serial.begin(115200);

  Tsensor.begin();
  servo.attach(SRV_PIN);
  pinMode(13, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
}

void loop() {

  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buf[50];                          // Сколько максимум символов будет в протоколе
    int num = Serial.readBytesUntil(';', buf, 50);   // Окончание строки значений (терминатор) делаем ;
    buf[num] = NULL;                          // Записываем нулевой символ (NULL) в ячейку последней принятой строки для корректного определенния конца строки во время парсинга
    GParser dat(buf, ',');                 // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0:
        digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1]
        break;
      case 1:
        analogWrite(LED_R, ints[1]);
        analogWrite(LED_G, ints[2]);
        analogWrite(LED_B, ints[3]);
        break;
      case 2:
        servo.write(ints[1]);
        break;
    }
  }

  btn.tick();                           // Инициализация кнопки в цикле
  static uint32_t tmr = 0;
  if (millis() - tmr > 80) {
    tmr = millis();
    Serial.print(0);
    Serial.print(',');
    Serial.print(analogRead(POT));
    Serial.print(',');
    Serial.print(analogRead(PHOTO));
    Serial.print(',');

    Tsensor.requestTemperatures();
    Celsius = Tsensor.getTempCByIndex(0);
    Serial.println(Celsius);            // Читаем показания с термистра
  }

  static uint32_t tmr2 = 0;
  if (millis() - tmr2 > 50) {
    tmr2 = millis();
    Serial.print(2);
    Serial.print(',');
    Serial.print(analogRead(JOYX));
    Serial.print(',');
    Serial.println(analogRead(JOYY));
  }

  if (btn.isClick()) {                  // Если кнопка была кликнута
    flag = !flag;
    Serial.print(1);
    Serial.print(',');
    Serial.println(flag);
  }
}
//=================================ПОТЕНЦИОМЕТР И КНОПКА И RGB И SERVO И ФОТОРЕЗИСТОР И ТЕРМИСТОР И ДЖОЙСТИК И LCD =============================================
#define POT A0         // Контакт потенциометра
#define BTN 3          // Контакт кнопки
#define LED_R 9        // Контакт LED RGB
#define LED_G 10       // Контакт LED RGB
#define LED_B 11       // Контакт LED RGB
#define SRV_PIN 2      // Контакт серво
#define PHOTO A2       // Контакт фоторезистора
#define THERM 12       // Контакт термистора
#define JOYX A6        // Контакт джойстика Х
#define JOYY A7        // Контакт джойстика Y
#define MOS 4          // Мосфет (для управления лампой от сети) *Опционально
#define RELAY 5        // Реле (для управления лампой от сети) *Опционально

// Подключение библиотек и инициализация компонентов
#include <OneWire.h>
OneWire term(THERM);

#include <DallasTemperature.h>
DallasTemperature Tsensor(&term);

#include <Servo.h>
Servo servo;

#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include <EncButton.h>
#include <GParser.h>

EncButton<EB_TICK, BTN> btn;  // Инициализация кнопки на 3 контакте и назовём btn

bool flag = 0;
float Celsius = 0;

/* Ключи (с ардуино на ПК)
    0 - Потенциометр и Фоторезистор и Термистор в одном пакете
    1 - Кнопка;
    2 - joyX, joyY (джойстик)

    Ключи (С ПК на ардуино)
    0 - LED (13);
    1 - r,g,b;
    2 - angle(0-180);
    3 - Fan
    4 - Relay
    5 - Text
*/

void setup() {
  Serial.begin(115200);

  Tsensor.begin();
  servo.attach(SRV_PIN);
  lcd.init();                 // инициализация LCD
  lcd.backlight();            // включить подсветку
  pinMode(13, OUTPUT);
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);
  pinMode(MOS, OUTPUT);       // *Опционально
  pinMode(RELAY, OUTPUT);     // *Опционально
}

void loop() {

  if (Serial.available()) {                // Если порт открыт. Пишем протокол связи (здесь численный посему "int ints[]" )
    char buf[50];                          // Сколько максимум символов будет в протоколе
    int num = Serial.readBytesUntil(';', buf, 50);   // Окончание строки значений (терминатор) делаем ;
    buf[num] = NULL;                          // Записываем нулевой символ (NULL) в ячейку последней принятой строки для корректного определенния конца строки во время парсинга
    GParser dat(buf, ',');                 // После того как прочитали входящие данные через "readBytesUntil" и занесли их в буфер "char buff" начинаем парсить с помощью библиотеки GParser
    int ints[10];                          // Разбиваем полученные численные значения на массив интов
    dat.parseInts(ints);                   // Заносим полученные данные в массив интс

    switch (ints[0]) {                     // Ключ (если 0 то задействуем светодиод)
      case 0:
        digitalWrite(13, ints[1]);   // Значение(on/off) получаем со второй цифры массива ints[0, 1]
        break;
      case 1:
        analogWrite(LED_R, ints[1]);
        analogWrite(LED_G, ints[2]);
        analogWrite(LED_B, ints[3]);
        break;
      case 2:
        servo.write(ints[1]);
        break;
      case 3:
        digitalWrite(MOS, ints[1]);
        break;
      case 4:
        digitalWrite(RELAY, ints[1]);
        break;
      case 5:
        dat.split();                   // Парсим знаки а не числа с помощью библиотеки GParser.h
        lcd.clear();
        lcd.home();
        lcd.print(dat[1]);             // Выводим на LCD экран
        break;
    }
  }

  btn.tick();                           // Инициализация кнопки в цикле
  static uint32_t tmr = 0;
  if (millis() - tmr > 80) {
    tmr = millis();
    Serial.print(0);
    Serial.print(',');
    Serial.print(analogRead(POT));
    Serial.print(',');
    Serial.print(analogRead(PHOTO));
    Serial.print(',');

    Tsensor.requestTemperatures();
    Celsius = Tsensor.getTempCByIndex(0);
    Serial.println(Celsius);            // Читаем показания с термистра
  }

  static uint32_t tmr2 = 0;
  if (millis() - tmr2 > 50) {
    tmr2 = millis();
    Serial.print(2);
    Serial.print(',');
    Serial.print(analogRead(JOYX));
    Serial.print(',');
    Serial.println(analogRead(JOYY));
  }

  if (btn.isClick()) {                  // Если кнопка была кликнута
    flag = !flag;
    Serial.print(1);
    Serial.print(',');
    Serial.println(flag);
  }
}
//===========================================================================================================
