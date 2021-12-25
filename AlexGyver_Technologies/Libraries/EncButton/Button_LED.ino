#include <EncButton.h>
EncButton<EB_TICK, 3> btn1(INPUT_PULLUP);  // Используем внутреннюю подтяжку

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  btn1.tick();
  if(btn1.isClick()) digitalWrite(13, !digitalRead(13));
}

/*******************TWO BUTTONS**************************/
#include <EncButton.h>
EncButton<EB_TICK, 2> btn1(INPUT_PULLUP);
EncButton<EB_TICK, 3> btn2(INPUT_PULLUP);

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  btn1.tick();
  btn2.tick();

  if(btn1.isClick()) Serial.println("btn 1 is clicked!");
  if(btn1.isHolded()) Serial.println("btn 1 is holded!");

  if(btn2.isClick()) digitalWrite(13, !digitalRead(13)),
  Serial.println("btn 2 switch LED");
}
/**************************************************/
