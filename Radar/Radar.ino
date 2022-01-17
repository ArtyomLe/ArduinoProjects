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
  int val = 0;
  int dir = 1;

void setup() {
  pinMode(trigPin, OUTPUT);        // Sets the trigPin as an Output
  pinMode(echoPin, INPUT);         // Sets the echoPin as an Input
  Serial.begin(9600);
  myServo.attach(3);              // Defines on which pin is the servo motor attached
}
                            

void loop() {

  if (millis() - tmr >= 15) {                 // Instead of delay function
    tmr = millis();
    val += dir;                               // Each step of servo
    if (val >= 150 || val <= 0) dir = -dir;   // Servo rotation degree range
    myServo.write(val);                        
    
    distance = calculateDistance();           // Calls a function for calculating the distance measured by the Ultrasonic sensor for each degree
    
    Serial.print(val);                        // Sends the current degree into the Serial Port
    Serial.print(",");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
    Serial.print(distance);                   // Sends the distance value into the Serial Port
    Serial.println(".");                        // Sends addition character right next to the previous value needed later in the Processing IDE for indexing
  }
}


// Function for calculating the distance measured by the Ultrasonic sensor
int calculateDistance() { 
  
  digitalWrite (trigPin, HIGH);           // Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite (trigPin, LOW);
  
  duration = pulseIn(echoPin, HIGH);     // Reads the echoPin, returns the sound wave travel time in microseconds
  distance = duration / 58.2;
  return distance;
}
