#include <Servo.h>
Servo potservo;

int potpin = 0;                    // Analog pin used to connect potentiometer
int val;                           // Variable to read value from analog pin

void setup(){
  potservo.attach(9);              // Attaches servo on pin 9
}

void loop(){
  val = analogRead(potpin);        // Read the value of the potentiometer (0 to 1023)
  val = map(val, 0, 1023, 0, 180); // Scale it to use it with the servo (0 to 180)
  potservo.write(val);             // Sets the servo position according to the scaled value
  delay(15);                       // Wait for the servo to get there   
}
