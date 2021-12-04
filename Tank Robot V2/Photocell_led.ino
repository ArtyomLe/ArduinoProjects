
int analogInPin = A1;  // Analog input pin that the photocell is attached to
int analogOutPin = 10; // Analog output pin that the LED is attached to
int sensorValue = 0;   // value read from photoresistor
int outputValue = 0;   // value output to the LED

void setup(){
  Serial.begin(9600);
}

void loop(){
  sensorValue = analogRead(analogInPin);            // Считаваемое аналоговое значение с фоторезистора (0, 1023) 
  outputValue = map(sensorValue, 0, 1023, 0, 255);  // Аналого-цифровая конвертация(0-1023 к 0-255)
  analogWrite(analogOutPin, outputValue);           // Подаём на выход(LED)значение полученное через map(конвертацию)

  // wait 2 milliseconds before the next loop for the analog-to-digital
  // converter to settle after the last reading:
  
  Serial.println(sensorValue);  //serial port prints the value of photoresistor
  delay(2);
}
// Чем ярче свет падающий на фоторезистор тем ярче становиться LED