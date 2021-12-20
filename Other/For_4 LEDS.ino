void setup() {
  Serial.begin(9600);
  for(int i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);           // Сделать пины 2-5 выходами
  }
}

void loop() {
  for(int i = 0; i < 6; i++) {
    digitalWrite(i, HIGH);        // Включить диоды
    delay(200);
  }
  for(int i = 6; i > 1; i--) {
    digitalWrite(i, LOW);         // Выключить диоды
    delay(200);
  }
}
