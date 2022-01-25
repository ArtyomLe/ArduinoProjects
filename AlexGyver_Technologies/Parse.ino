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
//ОБШИЙ ВИД ПЕРЕДАВАЕМЫХ ДАННЫХ: 123,456,789;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
}

void loop() {
  if (Serial.available()) {
    char str[30];
    int amount = Serial.readBytesUntil(';', str, 30);
    str[amount] = NULL;    // Определяем общую длинну данных

    int value[10];         // Буфер значений
    int count = 0;         // Счётчик значений
    char* off = str;       // Указатель

    while (true) {
      value[count++] = atoi(off); // Пишем число в буфер
      off = strchr(off, ',');     // Поиск следующей запятой
      if (off) off++;             // Если не NULL то продолжаем
      else break;                 // Иначе выход из цикла
    }
    for (int i = 0; i < count; i++) {
      Serial.println(value[i]);       // Вывод в буфер
    }
  }
}
//===========================================Если парсинг состоит из чисел и букв разделённых запятой=================================================
//ОБШИЙ ВИД ПЕРЕДАВАЕМЫХ ДАННЫХ: 123,as4,Ad9;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(1000);
}

void loop() {
  if (Serial.available()) {
    char str[30];
    int amount = Serial.readBytesUntil(';', str, 30);
    str[amount] = NULL;    // Определяем общую длинну данных

    char* ptrs[10];        // Указатели на строки
    int count = 0;         // Счётчик подстрок
    char* off = str;       // Указатель для работы

    while (true) {
      ptrs[count++] = off;        // Запоминаем указатель
      off = strchr(off, ',');     // Поиск следующей запятой
      if (off) {                  // Если не NULL
        *off = NULL;              // Заменяем запятую на NULL
        off++;                    // Продолжаем
      }
      else break;                 // Иначе выход из цикла
    }
    for (int i = 0; i < count; i++) {
      Serial.println(ptrs[i]);     // Вывод в буфер
    }
  }
}
//=======================================================================================
