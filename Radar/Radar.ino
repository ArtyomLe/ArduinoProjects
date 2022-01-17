//=======First upload this sketch to arduino board (check COM port) that should correct in processing sketch========

// Includes the Servo library
#include <Servo.h>

// Defines Tirg and Echo pins of the Ultrasonic Sensor
const int trigPin = 10;
const int echoPin = 11;

// Variables for the duration and the distance
uint32_t duration;
int distance;

Servo myServo;                     // Creates a servo object for controlling the servo motor

  uint32_t tmr;
  int i = 15;                      // Set angle to start from 
  int dir = 1;                     // Set step (increase number = high rotation)

void setup() {
  pinMode(trigPin, OUTPUT);        // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);         // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(3);               // Defines on which pin is the servo motor attached
}
                            

void loop() {

  if (millis() - tmr >= 20) {                 // Instead of delay function (increase number = low rotation)
    tmr = millis();
    i += dir;                                 // Each step of servo
    if (i >= 165 || i <= 15) dir = -dir;      // Set servo rotation degree range
    myServo.write(i);                        
    
    distance = calculateDistance();           // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    
    Serial.print(i);                          // Sends the current degree into the Serial Port
    Serial.print(",");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);                   // Sends the distance value into the Serial Port
    Serial.print(".");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
}


// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() { 
  
  digitalWrite (trigPin, HIGH);               // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite (trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);          // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration / 58.2;
  return distance;
}
