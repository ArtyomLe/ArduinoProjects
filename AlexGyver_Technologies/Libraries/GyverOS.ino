#include <GyverOS.h>
GyverOS<3> OS;           // кол-во подключаемых задач


void setup() {
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);

   OS.attach(0, task1, 500);
   OS.attach(1, task2, 100);
   OS.attach(2, task3, 2000);

// OS.stop(0);             // остановить задачу 0
// OS.start(1);            // перезапустить 1 
// OS.setPeriod(2, 1000);  // сменить период задачи
// OS.exec(0);             // вызвать задачу 0 вручную
}

void task1() {
  digitalWrite(10, !digitalRead(10));
}
void task2() {
  digitalWrite(9, !digitalRead(9));
}
void task3() {
  Serial.println(random(100));
}

void loop() {
  OS.tick();
}
/*****************Режим энергосбережения*****************/
