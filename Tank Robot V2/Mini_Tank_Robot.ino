
//Array, used to store the data of the pattern, can be calculated by yourself or obtained from the modulus tool
unsigned char start01[]     = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[]       = {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[]        = {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[]        = {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[]       = {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[]      = {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char Ultrafollow[] = {0x00,0x1c,0x22,0x2a,0x22,0x1c,0x00,0x00,0x00,0x00,0x1c,0x22,0x2a,0x22,0x1c,0x00};
unsigned char Lightfollow[] = {0x3c,0x20,0x00,0x34,0x00,0x3c,0x24,0x30,0x00,0x3c,0x10,0x3c,0x00,0x04,0x3c,0x04};
unsigned char Avoid[]       = {0xff,0x11,0xd5,0x85,0xfd,0xb1,0x87,0xb5,0xa5,0xa1,0xfd,0x81,0xdf,0x91,0x85,0xfd};
unsigned char clear[]       = {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#define SCL_Pin  A5                     //Set clock pin to A5 (LED Display)
#define SDA_Pin  A4                     //Set data pin to A4  (LED Dispaly)

#define ML_Ctrl 13                      //define direction control pin of left motor
#define ML_PWM  11                       //define PWM control pin of left motor
#define MR_Ctrl 12                      //define direction control pin of right motor
#define MR_PWM  3                        //define PWM control pin of right motor

#define Trig 5                          //ultrasonic trig Pin
#define Echo 4                          //ultrasonic echo Pin
int distance;                           //save the distance value detected by ultrasonic, follow function
int random2;                            //save the variable of random numbers save the variable of random numbers

int a;                                  //straight distance (obstacle avoidance variables)
int a1;                                 //left distance (obstacle avoidance variables)
int a2;                                 //right distance (obstacle avoidance variables)

#define servoPin 9                      //Servo Pin
int pulsewidth;

#define light_L_Pin A1                  //Photoresistor sensor (left)
#define light_R_Pin A2                  //Photoresistor sensor (right)

int left_light;
int right_light;

char bluetooth_val;                     //save the value of Bluetooth reception
int flag;                               //flag variable, it is used to entry and exist function


void setup(){
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);          //Ultrasonic
  pinMode(Echo, INPUT);           //Ultrasonic
  pinMode(ML_Ctrl, OUTPUT);       //LMotor direction
  pinMode(ML_PWM, OUTPUT);        //LMotor speed
  pinMode(MR_Ctrl, OUTPUT);       //RMotor direction
  pinMode(MR_PWM, OUTPUT);        //RMotor speed
  
  pinMode(servoPin, OUTPUT);      //Servo
  procedure(90);                  //Set servo to 90°
  
  pinMode(SCL_Pin,OUTPUT);        //Display LED
  pinMode(SDA_Pin,OUTPUT);        //Display LED
  matrix_display(clear);          //Clear the display
  matrix_display(start01);        //Display start pattern
  
  pinMode(light_L_Pin, INPUT);    //Photoresistor (left)
  pinMode(light_R_Pin, INPUT);    //Photoresistor (right)
}

void loop(){
  if (Serial.available())
  {
    bluetooth_val = Serial.read();
    Serial.println(bluetooth_val);
  }
  switch (bluetooth_val) 
  {
    case 'F':                      //Forward instruction 
      Car_front();
      matrix_display(front);       //display forward pattern
      break;
    case 'B':                      //Back instruction
      Car_back(); 
      matrix_display(back);        // display back pattern
      break;
    case 'L':                      //left-turning instruction
      Car_left();
      matrix_display(left);        //show left-turning pattern
      break;
    case 'R':                      //right-turning instruction
      Car_right();
      matrix_display(right);       //show right-turning pattern
      break;
    case 'S':                      //stop instruction
      Car_Stop();
      matrix_display(STOP01);      //display stop pattern
      break;
   case 'Y':
      follow();                    //ultrasonic following function
      matrix_display(Ultrafollow); //show Ultrafollow pattern
      break;
   case 'U':
      avoid();                     //obstacle avoidance function
      matrix_display(Avoid);       //show Avoid pattern
      break;
   case 'X':
      light_track();               //light following function
      matrix_display(Lightfollow); //show Lightfollow pattern
      break;
  }}

/*****************Obstacle Avoidance Function**************/
void avoid() 
{
  flag = 0;                                     //the design that enter obstacle avoidance function
  while (flag == 0) 
  {
    random2 = random(1, 100);
    a = checkdistance();                        //assign the front distance detected by ultrasonic sensor to variable a
    
    if (a < 20)                                 //when the front distance detected is less than 20cm
    {
      Car_Stop();                               //robot stops
      matrix_display(Avoid);
      delay(200);                               //delay in 200ms
      
      procedure(160);                           //Ultrasonic platform turns left
      for (int j = 1; j <= 10; j = j + (1)) {   //for statement, the data will be more accurate if ultrasonic sensor detect a few times.
        a1 = checkdistance();                   //assign the left distance detected by ultrasonic sensor to variable a1
      }
      delay(200);
      
      procedure(20);                            //Ultrasonic platform turns right
      for (int k = 1; k <= 10; k = k + (1)) {
        a2 = checkdistance();                   //assign the right distance detected by ultrasonic sensor to variable a2
      }
     
      if (a1 < 50 || a2 < 50)                   //robot will turn to the longer distance side when left or right distance is less than 50cm.if the left or right distance is less than 50cm, the robot will turn to the greater distance
      {
        if (a1 > a2)                            //left distance is greater than right
        {
          procedure(90);                        //Ultrasonic platform turns back to right ahead ultrasonic platform turns front
          Car_left();                           //robot turns left
          matrix_display(Avoid);
          delay(500);                           //turn left 500ms
          Car_front();                          //go forward
          matrix_display(Avoid);
        } 
        else 
        {
          procedure(90);
          Car_right();                          //robot turns right
          matrix_display(Avoid);
          delay(500);
          Car_front();                          //go forward
          matrix_display(Avoid);
        }
      } 
      else                                      //both distance on two side is greater than or equal to 50cm, turn randomly
      {
        if ((long) (random2) % (long) (2) == 0) //when the random number is even
        {
          procedure(90);
          Car_left();                           //robot turns left
          matrix_display(Avoid);
          delay(500);
          Car_front();                          //go forward
          matrix_display(Avoid);
        } 
        else 
        {
          procedure(90);
          Car_right();                          //robot turns right
          matrix_display(Avoid);
          delay(500);
          Car_front();                          //go forward
          matrix_display(Avoid);
       } } } 
  else                                          //If the front distance is greater than or equal to 20cm, robot car will go front
  {
      Car_front();                              //go forward
      matrix_display(Avoid);
  }
  
  // receive the Bluetooth value to end the obstacle avoidance function
  if (Serial.available())
  {
    bluetooth_val = Serial.read();
    if (bluetooth_val == 'S')                   //receive S
    {
      flag = 1;                                 //when assign 1 to flag, end loop
    }}}}

/*******************Ultra Follow****************/
void follow() {
  flag = 0;
  while (flag == 0) {
    distance = checkdistance();                   //assign the distance detected by ultrasonic sensor to distance
    if (distance >= 20 && distance <= 60)         //the range to go front
    {
      Car_front();
      matrix_display(Ultrafollow);
    }
    else if (distance > 10 && distance < 20)      //the range to stop
    {
      Car_Stop();
      matrix_display(Ultrafollow);
    }
    else if (distance <= 10)                      // the range to go back
    {
      Car_back();
      matrix_display(Ultrafollow);
    }
    else                                          //other situations, stop
    {
      Car_Stop();
      matrix_display(Ultrafollow);
    }
    if (Serial.available())
    {
      bluetooth_val = Serial.read();
      if (bluetooth_val == 'S') 
      {
        flag = 1;                                 //end loop
      }}}}

//The function to control ultrasonic sensor the function controlling ultrasonic sensor
float checkdistance() {
  digitalWrite(Trig, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trig, LOW);
  float distance = pulseIn(Echo, HIGH) / 58.00;              //58.20 means 2*29.1=58.2
  delay(10);
  return distance;
}

//The function to control servo the function controlling servo
void procedure(int myangle) {
  for (int i = 0; i <= 50; i = i + (1)) {
    pulsewidth = myangle * 11 + 500;
    digitalWrite(servoPin,HIGH);
    delayMicroseconds(pulsewidth);
    digitalWrite(servoPin,LOW);
    delay((20 - pulsewidth / 1000));
  }}

/****************Light Follow******************/
void light_track() {
  flag = 0;
  while (flag == 0) {
    left_light = analogRead(light_L_Pin);
    right_light = analogRead(light_R_Pin);
    if (left_light > 650 && right_light > 650)           //the value detected by photo resistor, go forward
    {  
      Car_front();
      matrix_display(Lightfollow);
    } 
    else if (left_light > 650 && right_light <= 650)     //the value detected by photo resistor, turn left
    {
      Car_left();
      matrix_display(Lightfollow);
    } 
    else if (left_light <= 650 && right_light > 650)     //the value detected by photo resistor, turn right
    {
      Car_right();
      matrix_display(Lightfollow);
    } 
    else                                                 //other situations, stop
    {
      Car_Stop();
      matrix_display(Lightfollow);
    }
    if (Serial.available())
    {
      bluetooth_val = Serial.read();
      if (bluetooth_val == 'S') {
        flag = 1;
     }}}}

/***************Dot Matrix *****************/
// this function is used for dot matrix display 
void matrix_display(unsigned char matrix_value[])
{
  IIC_start();
  IIC_send(0xc0);                      //Choose address
  
  for(int i = 0; i < 16; i++)          //pattern data has 16 bits
  {
     IIC_send(matrix_value[i]);        //convey the pattern data
  }
  IIC_end();                           //end the transmission of pattern data
  IIC_start();
  IIC_send(0x8A);                      //display control, set pulse width to 4/16
  IIC_end();
}
//The condition starting to transmit data
void IIC_start()
{
  digitalWrite(SCL_Pin,HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin,HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin,LOW);
  delayMicroseconds(3);
}
//convey data
void IIC_send(unsigned char send_data)
{
  for(char i = 0; i < 8; i++)                //each byte has 8 bits
  {
      digitalWrite(SCL_Pin, LOW);             //pull down clock pin SCL Pin to change the signals of SDA
      delayMicroseconds(3);
      if(send_data & 0x01)                   //set high and low level of SDA_Pin according to 1 or 0 of every bit
      {
        digitalWrite(SDA_Pin, HIGH);
      }
      else
      {
        digitalWrite(SDA_Pin,LOW);
      }
      delayMicroseconds(3);
      digitalWrite(SCL_Pin,HIGH);            //pull up clock pin SCL_Pin to stop transmitting data
      delayMicroseconds(3);
      send_data = send_data >> 1;            // detect bit by bit, so move the data right by one
  }}

//The sign that data transmission ends
void IIC_end()
{
  digitalWrite(SCL_Pin,LOW);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin,LOW);
  delayMicroseconds(3);
  digitalWrite(SCL_Pin,HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin,HIGH);
  delayMicroseconds(3);
}

/*************Run motor*************/
void Car_front()
{
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,180);
  digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,180);
}
void Car_back()
{
  digitalWrite(MR_Ctrl,HIGH);
  analogWrite(MR_PWM,180);
  digitalWrite(ML_Ctrl,HIGH);
  analogWrite(ML_PWM,180);
}
void Car_left()
{
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,160);
  digitalWrite(ML_Ctrl,HIGH);
  analogWrite(ML_PWM,160);
}
void Car_right()
{
  digitalWrite(MR_Ctrl,HIGH);
  analogWrite(MR_PWM,160);
  digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,160);
}
void Car_Stop()
{
  digitalWrite(MR_Ctrl,LOW);
  analogWrite(MR_PWM,0);
  digitalWrite(ML_Ctrl,LOW);
  analogWrite(ML_PWM,0);
}
