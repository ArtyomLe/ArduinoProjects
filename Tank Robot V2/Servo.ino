
#define servoPin 9       //servo Pin
int pos;                 //angle variable of servo
int pulsewidth;          // pulse width variable of servo

void setup() {
  pinMode(servoPin, OUTPUT);    //set servo pin to OUTPUT
  procedure(0); 		//set the angle of servo to 0°
}


void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees in steps of 1 degree

    procedure(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                   //control the rotation speed of servo
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    procedure(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                    
  }
}


void procedure(int myangle) {          // function to control servo
  pulsewidth = myangle * 11 + 500;     //calculate the value of pulse width
  digitalWrite(servoPin,HIGH);
  delayMicroseconds(pulsewidth);       //The duration of high level is pulse width
  digitalWrite(servoPin,LOW);
  delay((20 - pulsewidth / 1000));     // the cycle is 20ms, the low level last for the rest of time
}