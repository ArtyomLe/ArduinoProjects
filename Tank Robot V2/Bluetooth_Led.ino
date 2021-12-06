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
    if (i == 'a')                     // если полученное значение равно a зажигаем led
    {
      digitalWrite(ledpin, 1);
      Serial.println("led on");
    }
    if (i == 'b')                     // если полученное значение равно b гасим led
    {
      digitalWrite(ledpin, 0);
      Serial.println("led off");
    }
  }
}
