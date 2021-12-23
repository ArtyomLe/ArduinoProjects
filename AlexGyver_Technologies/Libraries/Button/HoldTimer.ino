#include "GyverButton.h"
GButton myButt(3, HIGH_PULL, NORM_OPEN);

void setup() {
   Serial.begin(9600);
   myButt.setDebounce(1000);
   myButt.setTimeout(2000);
}

void loop() {
   myButt.tick();
   if(myButt.isHolded()) {
   Serial.preintln("hold!");
  }
}
