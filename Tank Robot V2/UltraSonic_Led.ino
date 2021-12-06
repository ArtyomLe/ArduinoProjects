
int trigPin = 5;    // Trigger
int echoPin = 4;    // Echo
long duration, cm;

void setup() {
  Serial.begin (9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  cm = (duration/2) / 29.1;   
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);

if (cm>=2 && cm<=10)
digitalWrite(10, HIGH);
delay(1000);
digitalWrite(10, LOW);
delay(1000);
}
