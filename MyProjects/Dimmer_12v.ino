#define pot 0                           // Вход потинциометра
int value; 

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pot);
  value = map(value, 0, 1023, 0, 255);
  value = constrain(value, 0, 255);
  analogWrite(5, value);               // Выход ШИМ сигнала на транзистор 
  Serial.println(value);
}
