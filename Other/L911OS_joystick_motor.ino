// Motor A
int in1 = 3;
int in2 = 2;
  
int SpeedControl = A0;
int MotorSpeed;

void setup() {
  Serial.begin(9600);
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
}

void loop() {
  Serial.println(analogRead(SpeedControl));
  
  analogWrite(in2, 0);
  analogWrite(in1, MotorSpeed);
  
  MotorSpeed = analogRead(SpeedControl);
  MotorSpeed = map(MotorSpeed, 0, 1023, 0, 255);
}
