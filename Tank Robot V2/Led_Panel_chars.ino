//Array, used to store the data of the pattern, can be calculated by yourself or obtained from the modulus tool
//Чем длиннее пульс, тем ярче (1/16 - 14/16) 4/16 = 0x8a (http://dotmatrixtool.com/)

unsigned char start01[] = {0x01,0x02,0x04,0x08,0x10,0x20,0x40,0x80,0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
unsigned char front[] =   {0x00,0x00,0x00,0x00,0x00,0x24,0x12,0x09,0x12,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char back[] =    {0x00,0x00,0x00,0x00,0x00,0x24,0x48,0x90,0x48,0x24,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char left[] =    {0x00,0x00,0x00,0x00,0x00,0x00,0x44,0x28,0x10,0x44,0x28,0x10,0x44,0x28,0x10,0x00};
unsigned char right[] =   {0x00,0x10,0x28,0x44,0x10,0x28,0x44,0x10,0x28,0x44,0x00,0x00,0x00,0x00,0x00,0x00};
unsigned char STOP01[] =  {0x2E,0x2A,0x3A,0x00,0x02,0x3E,0x02,0x00,0x3E,0x22,0x3E,0x00,0x3E,0x0A,0x0E,0x00};
unsigned char clear[] =   {0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};

#define SCL_Pin  A5         //Set clock pin to A5
#define SDA_Pin  A4         //Set data pin to A4


void setup(){ 
                           
  pinMode(SCL_Pin,OUTPUT);
  pinMode(SDA_Pin,OUTPUT);
                      
  matrix_display(clear);    //Clear the display
}


void loop(){

  matrix_display(start01);  // Display start pattern
  delay(2000);
  matrix_display(front);    //Front pattern
  delay(2000);
  matrix_display(back);     //Back pattern
  delay(2000);
  matrix_display(left);     //Left parrent
  delay(2000);
  matrix_display(right);    //Right parrent
  delay(2000);
  matrix_display(STOP01);   //Stop pattern
  delay(2000);
  matrix_display(clear);    //Clear the display Clear the screen
  delay(2000);
}


void matrix_display(unsigned char matrix_value[]) //This function is used to display of dot matrix
{
  IIC_start();                      //call the function that data transmission start  
  IIC_send(0xc0);                   //Choose address (начинаем сдвигать вправо >> из нулевого столбца)
      
  for(int i = 0; i < 16; i++)       //pattern data has 16 bits
  {
     IIC_send(matrix_value[i]);     //data to convey patterns 
  }
  IIC_end();                        //end the transmission of pattern dataEnd
  IIC_start();  
  IIC_send(0x8a);                   //display control(brightness setting), set pulse width to 4/16                  
  IIC_end();
}



void IIC_start()                          //The condition starting to transmit data
{
  digitalWrite(SCL_Pin,HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin,HIGH);
  delayMicroseconds(3);
  digitalWrite(SDA_Pin,LOW);
  delayMicroseconds(3);
}


void IIC_send(unsigned char send_data)     //Convey data 
{
  for(char i = 0; i < 8; i++)              //Each byte has 8 bits
  {
      digitalWrite(SCL_Pin,LOW);           //pull down clock pin SCL Pin to change the signals of SDA      
      delayMicroseconds(3);
      if(send_data & 0x01)                 //set high and low level of SDA_Pin according to 1 or 0 of every bit
      {
          digitalWrite(SDA_Pin,HIGH);
      }
      else
      {
          digitalWrite(SDA_Pin,LOW);
      }
          delayMicroseconds(3);
      digitalWrite(SCL_Pin,HIGH);          //pull up clock pin SCL_Pin to stop transmitting data
      delayMicroseconds(3);
   send_data = send_data >> 1;             //detect bit by bit, so shift the data right by one
  }}



void IIC_end()                             //The sign that data transmission ends
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
