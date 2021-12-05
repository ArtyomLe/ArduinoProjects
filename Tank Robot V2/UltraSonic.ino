
int trigPin = 5;            // Trigger
int echoPin = 4;            // Echo
long duration, cm;


void setup() {
  
  Serial.begin (9600);      //Serial Port begin
  
  pinMode(trigPin, OUTPUT); // Посылает ультразвуковой сигнал
  pinMode(echoPin, INPUT);  // Принимает сигнал
}


void loop() {
  
  digitalWrite(trigPin, LOW);  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
   
  // duration is the time (in microseconds) from the sending  of the ping to the reception of its echo off of an object.
  // продолжительность - сколько времени прошло с того момента как отослали сигнал(Trig) и когда его получили(echo) в микросекундах 
  
  duration = pulseIn(echoPin, HIGH);    // Read the signal from the sensor: a HIGH pulse whose
  
  // Convert the time into a distance
  cm = (duration/2) * 0.0343;     // distance = (traveltime/2) x speed of sound     (343m/s = 0.0343 cm/uS = 1/29.1 cm/uS)
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(250);
}
