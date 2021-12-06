#include <IRremoteTank.h>
int RECV_PIN = A0;                                // define the pin of IR receiver as A0
int LED_PIN = 10;                                 // define the pin of LED
int a = 0;

IRrecv irrecv(RECV_PIN);
decode_results results;

void setup()
{
    Serial.begin(9600);
    irrecv.enableIRIn();                          // initialize the IR receiver
    pinMode(LED_PIN, OUTPUT);                     // set LED_PIN to OUTPUT
}

void loop()
{
    if (irrecv.decode(&results))
    {
        if (results.value == 0xFF629D & a == 0)   // according to chart, press "UP" button on remote control, LED will be controled   
        {
            digitalWrite(LED_PIN, HIGH);          // LED will be on
            a = 1;
        }
        else if (results.value == 0xFFA857 & a == 1) // press "DOWN" button 
        {
            digitalWrite(LED_PIN, LOW);           // LED will go off
      a = 0;   
        }
         
        irrecv.resume();                          // recieve the next value
    }   
}
