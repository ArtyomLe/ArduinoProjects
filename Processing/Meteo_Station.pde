import processing.serial.*;  // Подключаем библиотеку serial 
Serial serial;               //  Называем её serial

void setup() {
  size(400, 200);                // Размеры основного рабочего окна
  String str[] = Serial.list();  // Вывести доступные рабочие порты(получаем массив строк)
  print(str[0]);
}

void draw() {
}
//==============================================================================================
