/*
 * Основные функции:
 * - Управление через пульт от Sony Playstation_2 (правый стик - привод) (левый стик - camera FPV)
 * - Измерение расстояния (HC-CR04) каждые 2 сек. и вывод на OLED 128x64
 * - Индикатор заряда аккумуляторов (3.7v (x2))
 * - Камера FPV питание от 3.3v на шилде
 * - Вентилятор охлаждения камеры питание 5v на шилде
*/

#define MIN_DUTY 120         // мин. сигнал, при котором мотор начинает вращение
#define MAX_CAM_SPEED 50     // скорость поворота серво привода                                                      

// датчик растоянния HC-SR04
#define HC_TRIG 6
#define HC_ECHO 7

// пределы поворота серво (+50\-50 градусов от начальной позиции в 90 градусов)
#define CAM_MIN 400                                                                 
#define CAM_MAX 1400                                                                

// пины драйвера и серво
#define MOT_RA 2
#define MOT_RB 3
#define MOT_LA 4
#define MOT_LB 5
#define SERVO_CAM 8                                                                

// пины ресивера ps2
#define PS2_DAT A0
#define PS2_CMD A1
#define PS2_SEL A2
#define PS2_CLK A3


#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#include <Servo.h>                                                               
Servo cam;                                                                       

#include <GyverMotor.h>
GMotor motorR(DRIVER2WIRE, MOT_RA, MOT_RB, HIGH);   // (тип, пин, ШИМ пин, уровень)
GMotor motorL(DRIVER2WIRE, MOT_LA, MOT_LB, HIGH);

#include <PS2X_lib.h>
PS2X ps2x;
                                                 
int camP = 900;                                     // позиция привода (градусы * 10)                                                             


void setup() {
  Serial.begin(9600);

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);        // подключаем OLED

  pinMode(HC_TRIG, OUTPUT);   
  pinMode(HC_ECHO, INPUT);
    
  cam.attach(SERVO_CAM);                            // подключаем серво                                 
  cam.write(camP);                                  // ставим на начальные позиции                      

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
    // таймер на 10 мс (100 раз в секунду)
    static uint32_t tmr;
    if (success && millis() - tmr >= 10) {
      tmr = millis();
      
    camP += map(ps2x.Analog(PSS_LX), 0, 255, MAX_CAM_SPEED, -MAX_CAM_SPEED);
    camP = constrain(camP, CAM_MIN, CAM_MAX);               
    //Serial.print(camP);                                    // вывести угол поворота серво привода
    cam.write(camP / 10);                                    // переводим в градусы и применяем
    }
    
    // преобразуем стики от 0..255 к -255, 255
    int RX = map(ps2x.Analog(PSS_RX), 255, 0, -255, 255); 
    int RY = map(ps2x.Analog(PSS_RY), 255, 0, -255, 255);  

   if (RX == -1 && RY == -1 ) {                              // Если едет правый борт (дефект джойстика)
     RX = 0;
     RY = 0;
    }

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

    
  // Получаем расстояние HC-CR04
  static uint32_t tmr1;
  if (millis() - tmr1 >= 2000) {
    tmr1 = millis();
    int dist = getDist();       // Получаем расстояние 
    
    display.display();
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(4);
    display.setCursor(14,2);
    display.print(dist);
    display.setTextSize(2);
    display.setCursor(93,16);
    display.print("cm");
  }
}

float getDist() {
  // Импульс 10 мкс
  digitalWrite(HC_TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(HC_TRIG, LOW);

  // Измеряем время ответного импульса
  uint32_t us = pulseIn(HC_ECHO, HIGH);

  // считаем растояние и возвращаем
  return (us / 58.2);
  
}      
