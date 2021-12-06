
#define ML_DirA 12               //define the direction control pin of left motor
#define MR_DirB 13               //define the direction control pin of right motor
#define ML_SpeedA 3              //define the PWM control pin of left motor
#define MR_SpeedB 11             //define the PWM control pin of right motor

void setup()
{
  pinMode(ML_DirA, OUTPUT);      //define direction control pin of left motor as output
  pinMode(MR_DirB, OUTPUT);      //define direction control pin of right motor as output.
  pinMode(ML_SpeedA, OUTPUT);    //define the PWM control pin of left motor as output
  pinMode(MR_SpeedB, OUTPUT);    //define the PWM control pin of right motor as output
}

void loop()               // rotation direction of motors is decided by the high/low level
{                         // LOW = Clockwise,  HIGH = Anticlockwise
  delay(5000);
  
  //front
  digitalWrite(ML_DirA, LOW);     //set the direction control pin of left motor to LOW
  digitalWrite(MR_DirB, LOW);     //set the direction control pin of right motor to LOW
  analogWrite(ML_SpeedA, 200);    //set the PWM control speed of left motor to 200rpm
  analogWrite(MR_SpeedB, 200);    //set the PWM control speed of right motor to 200rpm

  //back
  delay(2000);                     //delay in 2s
  digitalWrite(ML_DirA, HIGH);     //set the direction control pin of left motor to HIGH
  digitalWrite(MR_DirB, HIGH);     //set the direction control pin of right motor to HIGH
  analogWrite(ML_SpeedA, 200);     //set the PWM control speed of left motor to 200  
  analogWrite(MR_SpeedB, 200);     //set the PWM control speed of right motor to 200

  //left
  delay(2000);                     //delay in 2s 
  digitalWrite(ML_DirA, HIGH);     //set the direction control pin of left motor to HIGH
  digitalWrite(MR_DirB, LOW);      //set the direction control pin of right motor to LOW
  analogWrite(ML_SpeedA, 200);     //set the PWM control speed of left motor to 200
  analogWrite(MR_SpeedB, 200);     //set the PWM control speed of right motor to 200

  //right 
  delay(2000);                     //delay in 2s
  digitalWrite(ML_DirA, LOW);      //set the direction control pin of left motor to LOW
  digitalWrite(MR_DirB, HIGH);     //set the direction control pin of right motor to HIGH
  analogWrite(ML_SpeedA, 200);     //set the PWM control speed of left motor to 200
  analogWrite(MR_SpeedB, 200);     //set the PWM control speed of right motor to 200

  //stop 
  delay(2000);                     //delay in 2s
  analogWrite(ML_SpeedA, 0);       //set the PWM control speed of left motor to 0
  analogWrite(MR_SpeedB, 0);       //set the PWM control speed of right motor to 0

  
  delay(2000);                     //delay in 2s
}
