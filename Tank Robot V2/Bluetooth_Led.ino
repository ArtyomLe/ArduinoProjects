int ledpin = 10;

void setup()
{
  Serial.begin(9600);
  pinMode(ledpin, OUTPUT);
}

void loop()
{
  int i;
  if (Serial.available())             // если поступил сигнал, то активизируется цикл
  {
    i = Serial.read();                // переменная i получает значение сигнала
    Serial.println("DATA RECEIVED:"); 
    if (i == '1')                     // если полученное значение равно "1" зажигаем led
    {
      digitalWrite(ledpin, 1);
      Serial.println("led on");
    }
    if (i == '0')                     // если полученное значение равно "0" гасим led
    {
      digitalWrite(ledpin, 0);
      Serial.println("led off");
    }
  }
}
