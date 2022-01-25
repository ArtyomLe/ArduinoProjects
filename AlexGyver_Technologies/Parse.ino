//===============Управнеие яркостью светодиода через парсинг======================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(5, OUTPUT);
}

void loop() {
  if(Serial.available()) {
    int value = Serial.parseInt();
    analogWrite(5, value);              // Приниманиемые значения Serial monitor 0-1023
    Serial.println(value);
  }
}
//======================================Управление 2 светодиодами=====================================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(5);
  pinMode(5, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  if (Serial.available() > 1) {     // Если получаем как минимум два значения в порт(a0-1023,b0-1023)
    char key = Serial.read();       // Читаем и запоминаем символ
    int value = Serial.parseInt();  // Парсим оставшиеся число
    switch (key) {
      case 'a': analogWrite(5, value);
        break;
      case 'b': analogWrite(10, value);
        break;
    }
  }
}
//====================================Парсим rgb led================================================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(15);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
}

void loop() {
  if (Serial.available() > 1) {     // Если получаем как минимум два значения в порт(r0-255,g0-255,b0-255)
    char key = Serial.read();       // Читаем и запоминаем символ
    int value = Serial.parseInt();  // Парсим оставшиеся число
    switch (key) {
      case 'r': analogWrite(3, value);
        break;
      case 'g': analogWrite(5, value);
        break;
      case 'b': analogWrite(6, value);
        break;
    }
  }
}
//=========================================================================================
void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
}

void loop() {
 if(Serial.available()) {
  char data[30];
  int amount = Serial.readBytesUntil(';', data, 30); // Эта функция записывает получаемые данные в указанный массив char указанного размера.
                                                     // после указания терминатора ; данные выводятся сразу без задержи Timeout
  data[amount] = NULL;                               // Закрываем строку для корректного вывода содержимого буффера
  Serial.println(data);
 }
}
//===============================================Если парсинг состоит из чисел разделённых запятой=================================================================
