
void setup() {
  
  // подрубаем геймпад
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);

}

void loop() {

  // читаем геймпад
  bool success = ps2x.read_gamepad(false, 0);               // читаем ресивер джойстика
  ps2x.reconfig_gamepad();
  
  // Show up stick values via Serial_print (при нажатии L1 или R1 выводятся состояния обоих аналоговых стиков.)
  if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1))            // print stick values if either is TRUE
  {
    Serial.print("Stick Values:");
    Serial.print(ps2x.Analog(PSS_LY), DEC);                  //Left stick, Y axis. Other options: LX, RY, RX  
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_LX), DEC); 
    Serial.print(",");
    Serial.print(ps2x.Analog(PSS_RY), DEC); 
    Serial.print(",");
    Serial.println(ps2x.Analog(PSS_RX), DEC); 
  }   
}
