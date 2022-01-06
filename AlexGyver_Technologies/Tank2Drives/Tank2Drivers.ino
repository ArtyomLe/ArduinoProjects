// мин. сигнал, при котором мотор начинает вращение
#define MIN_DUTY 120
#define MAX_CAM_SPEED 40                                                           // ===============

// пределы поворота
#define CAM_MIN 20                                                                 // ===============
#define CAM_MAX 160                                                                // ===============

// пины драйвера и серво
#define MOT_RA 2
#define MOT_RB 3
#define MOT_LA 4
#define MOT_LB 5
#define SERVO_CAM 9                                                                // ===============

// пины ресивера ps2
#define PS2_DAT A0
#define PS2_CMD A1
#define PS2_SEL A2
#define PS2_CLK A3

// ===========================
#include <Servo.h>                                                                // ===============
Servo cam;                                                                        // ===============

#include <GyverMotor.h>
// (тип, пин, ШИМ пин, уровень)
GMotor motorR(DRIVER2WIRE, MOT_RA, MOT_RB, HIGH);
GMotor motorL(DRIVER2WIRE, MOT_LA, MOT_LB, HIGH);

#include <PS2X_lib.h>
PS2X ps2x;

// позиция привода (градусы * 10)                                                 // ===============
int camP = 0;                                                                     // ===============

void setup() {
  Serial.begin(9600);
  
  cam.attach(SERVO_CAM);      // подключаем серво                                 // ================
  cam.write(camP);            // ставим на начальные позиции                      // ================

  motorR.setMode(AUTO);
  motorL.setMode(AUTO);

  // НАПРАВЛЕНИЕ ГУСЕНИЦ (зависит от подключения)
  motorR.setDirection(REVERSE);
  motorL.setDirection(NORMAL);

  // мин. сигнал вращения
  motorR.setMinDuty(MIN_DUTY);
  motorL.setMinDuty(MIN_DUTY);

  // плавность скорости моторов
  motorR.setSmoothSpeed(80);
  motorL.setSmoothSpeed(80);

  // подрубаем геймпад
  ps2x.config_gamepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, false, false);

}

void loop() {
 
  // читаем геймпад
  bool success = ps2x.read_gamepad(false, 0);               // читаем ресивер джойстика
  ps2x.reconfig_gamepad();                                  // костыль https://stackoverflow.com/questions/46493222/why-arduino-needs-to-be-restarted-after-ps2-controller-communication-in-arduino
  
  if (success) {
  //===================================================== 
    // таймер на 30 мс (30 раз в секунду)
    static uint32_t tmr;
    if (success && millis() - tmr >= 30) {
      tmr = millis();
      
    camP += map(ps2x.Analog(PSS_LX), 0, 255, MAX_CAM_SPEED, -MAX_CAM_SPEED);
    camP = constrain(camP, CAM_MIN, CAM_MAX);                // ограничиваем скорость
    Serial.print(camP);
    cam.write(camP / 10);                                    // переводим в градусы и применяем
    }
  //=====================================================
    // преобразуем стики от 0..255 к -255, 255
    int RX = map(ps2x.Analog(PSS_RX), 255, 0, -255, 255); 
    int RY = map(ps2x.Analog(PSS_RY), 255, 0, -255, 255);  

   if (RX == -1 && RY == -1 ) {                              // Если едет правый борт 
     RX = 0;
     RY = 0;
    }
  //======================================================    
  
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
 //=======================================================
    // танковая схема
    int dutyR = RY + RX;
    int dutyL = RY - RX;
    dutyR = constrain(dutyR, -255, 255);
    dutyL = constrain(dutyL, -255, 255);

    // задаём целевую скорость
    motorR.smoothTick(dutyR);
    motorL.smoothTick(dutyL);
  } else {
    // проблема с геймпадом - остановка
    motorR.setSpeed(0);
    motorL.setSpeed(0);
  }
}
