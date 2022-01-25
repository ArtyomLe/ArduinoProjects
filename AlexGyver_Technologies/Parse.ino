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
