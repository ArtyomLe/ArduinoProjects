
// First upload this sketch to arduino board (check COM port) that should correct in processing sketch


// Includes the Servo library
#include <Servo.h>

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration and the distance
uint32_t duration;
int distance;

Servo myServo;                     // Creates a servo object for controlling the servo motor


void setup() {
  pinMode(trigPin, OUTPUT);        // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);         // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(3);              // Defines on which pin is the servo motor attached
  
  uint32_t tmr;
  int val = 15;
  int dir = 1;
}


void loop() {

  if (millis() - tmr >= 20) {                 // Instead of delay function
    tmr = millis();
    val += dir;                               // Each step of servo
    if (val >= 165 || val <= 15) dir = -dir;  // Servo rotation range
    myservo.write(val)                        
    
    distance = calculateDistance();           // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
    Serial.print(val);                        // Sends the current degree into the Serial Port
    Serial.print(",");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);                   // Sends the distance value into the Serial Port
    Serial.print(".");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
}


// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() { 
 
  digitalWrite(trigPin, HIGH);           // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);     // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration / 58.2;
  return distance;
}


// ====================================================ORIGINAL=================================================
/*
#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(3);
}
uint32_t tmr;    // переменная таймера
int val = 15;    // переменная яркости
int dir = 1;     // скорость и направление яркости
void loop() {
  // асинхронный таймер на миллис
  if (millis() - tmr >= 20) {
    tmr = millis();
    val += dir;                               // прибавляем скорость
    if (val >= 180 || val <= 15) dir = -dir;  // разворачиваем
    myservo.write(val)                        // применяем
    
    distance = calculateDistance();           // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
  
    Serial.print(val);                        // Sends the current degree into the Serial Port
    Serial.print(",");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);                   // Sends the distance value into the Serial Port
    Serial.print(".");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
}

// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() { 
  
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;
  return distance;
}
*/
//====================================================================================================================
