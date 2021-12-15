void setup() {
  Serial.begin(9600);
  Serial.print("HELLO, WORLD! ");Serial.print(10);Serial.println(" How arre you today?");
  Serial.print("HELLO, WORLD! ");Serial.print(12);Serial.println(" How arre you today?");
  String mystring = "KEK";
  Serial.println(mystring);
  float pi = 3.141592653;
  Serial.println(pi, 3);

  int newVal = 3442;
  Serial.println(newVal, DEC);
  Serial.println(newVal, HEX);
  Serial.println(newVal, OCT);
  Serial.println(newVal, BIN);
}

void loop() {

  //put code here
}

/***************************************************/

byte val;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {              // Проверка на ввод данных в порт 
    val = Serial.parseInt();             // Прочитать число целиком
    if (val == 1 || val == 5) {          // 1 ИЛИ 5 
      Serial.println("Вы ввели 1 или 5");
    } else {
      Serial.println("Мимо!");
    }    
  }
}

/*******************************************************/

byte val;

void setup() {
  Serial.begin(9600);
}

void loop () {
  if (Serial.available()) {
    val = Serial.parseInt();
    if (val == 1) {
      Serial.println("Вы ввели 1");
    } else if (val == 2) {
      Serial.println("Вы ввели 2");
    } else if (val == 3) {
      Serial.println("Вы ввели 3");
    } else {
      Serial.println("Мимо");
    }
  }
}

/********************************************************************/

byte val;

void setup() {
  Serial.begin(9600);
}

void loop () {
  if (Serial.available()) {
    val = Serial.parseInt();
    switch (val) {
      case 1: Serial.println("Вы ввели 1");
       break;
      case 2: Serial.println("Вы ввели 2");
       break;
      case 3: Serial.println("Вы ввели 3");
       break;
      default: Serial.print("Мимо!");
    }
    }
}

