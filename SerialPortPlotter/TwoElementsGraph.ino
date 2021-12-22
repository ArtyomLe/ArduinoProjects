void setup() {
  Serial.begin(115200);
}
void loop() {
  Serial.println("$");               // Обязательный синтаксис для вывода графика
  Serial.println(analogRead(A7));    // Подключаем датчик на 7 пин
  Serial.println(" ");               // Убираем эти 2 строки если хотим 
  Serial.println(analogRead(A3));    // вывести только одно значение
  Serial.println(";");               // Обязательный синтаксис для вывода графика
  delay(50);
}
