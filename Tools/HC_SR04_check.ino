#define HC_TRIG 10
#define HC_ECHO 11

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

  digitalWrite(HC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(HC_TRIG, LOW);

  uint32_t us = pulseIn(HC_ECHO, HIGH);   // измеряем время ответного импульса  
  return (us / 58.2);                     // считаем расстояние и возвращаем
}
