#include <EncButton.h>
EncButton<EB_TICK, 3> btn1(INPUT_PULLUP);

void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  btn1.tick();
  if(btn1.isClick()) digitalWrite(13, !digitalRead(13));
}
