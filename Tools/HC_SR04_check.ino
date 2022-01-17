#define HC_TRIG 3
#define HC_ECHO 2

void setup() {
  Serial.begin(9600);       
  pinMode(HC_TRIG, OUTPUT); // trig выход
  pinMode(HC_ECHO, INPUT);  // echo вход
}

void loop() {
  float dist = getDist();   // получаем расстояние
  Serial.println(dist);     
  delay(50);
}

float getDist() {
  // импульс 10 мкс
  digitalWrite(HC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(HC_TRIG, LOW);

  uint32_t us = pulseIn(HC_ECHO, HIGH);   // измеряем время ответного импульса  
  return (us / 58.2);                     // считаем расстояние и возвращаем
}
