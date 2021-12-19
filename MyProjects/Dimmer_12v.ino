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
/*******Мерцание*************************************************************************/
/*
 * #define pot 0                           // Вход потинциометра
int value; 


void setup() {
  Serial.begin(9600);
}

void loop() {
  for (value = 0; value < 255; value++) {
    analogWrite(5, value);
    delay(10);
  }
  for (value = 255; value > 0; value--) {
    analogWrite(5, value);
    delay(10);
  }
}
 */
/*****Мерцание в зависимости от показания потенциометра*********************************/
/*
 * #define pot 0                           // Вход потинциометра
int value; 
int i;

void setup() {
  Serial.begin(9600);
}

void loop() {
  value = analogRead(pot);
  value = map(value, 0, 1023, 0, 255);
  value = constrain(value, 0, 255);
  for(i = 0; i < value; i++) {
    analogWrite(5, i);
    delay(10);
  }
  for(i = value; i > 0; i--) {
    analogWrite(5, i);
    delay(10);
  }
}
