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
//================================================================================
