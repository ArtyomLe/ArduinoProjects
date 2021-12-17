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

/**************** Delay без прекращения процессов *******************/
unsigned long last_time;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - last_time > 500) {
    last_time = millis();
    Serial.println("0.5 sec");
  }
}

/********************Раз в 23 дня*********************/

unsigned long last_time;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (millis() - last_time > (unsigned long) 23 * 24 * 60 * 60 * 1000) {
    last_time = millis();
    Serial.println("0.5 sec");
  }
}

/********************************************************/


void setup() {
  pinMode(A5, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

  digitalWrite(13, HIGH);
  digitalWrite(12, 1);
  digitalWrite(A5, 0);
}

void loop() {

  
}
/******************************************************/

void setup() {
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(A5, INPUT);

  Serial.begin(9600);
  
}

void loop() {
  boolean button1 = digitalRead(A5);
  boolean button2 = digitalRead(13);

  Serial.print("Button1: ");Serial.print(button1);
  Serial.print(", Button2: ");Serial.println(button2);
}
/***************************************************************/

void setup() {
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(A5, INPUT_PULLUP);

  Serial.begin(9600);
  
}

void loop() {
  boolean button1 = !digitalRead(A5); // Инвертируем сигнал
  boolean button2 = digitalRead(13);

  Serial.print("Button1: ");Serial.print(button1);
  Serial.print(", Button2: ");Serial.println(button2);
}

/**********************************************************************/

void setup() {
  pinMode(A5, INPUT_PULLUP);
  pinMode(13, OUTPUT);         // Встроенный светодиод  

  Serial.begin(9600);
  
}

void loop() {
  boolean button1 = !digitalRead(A5); // Инвертируем сигнал
  boolean button2 = digitalRead(13);

  if (button1 == 1) digitalWrite(13, HIGH); // Включить светодиод
  else digitalWrite(13, LOW);               // Выключить светодиод

  Serial.print("Button1: ");Serial.print(button1);
  Serial.print(", Button2: ");Serial.println(button2);
}

/***********************************************************************/

boolean butt_flag = 0;           // Логическая переменная запоминающая последнее состояние кнопки
boolean butt;                    // Текущее значение кнопки
  
void setup() {
  pinMode(3, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  butt = !digitalRead(3);       // Считать текущее состояние кнопки (1-нажата, 0-отпущена)
  
  if (butt == 1 && butt_flag == 0) {
    butt_flag = 1;
    Serial.println("Button pressed");
    Serial.println(butt);
  }
  if (butt == 0 && butt_flag == 1) {
    butt_flag = 0;
    Serial.println("Button released");
    Serial.println(butt);
  }
  
}

/**************************************************************/
boolean butt_flag = 0;           // Логическая переменная запоминающая последнее состояние кнопки
boolean butt;                    // Текущее значение кнопки
boolean led_flag = 0;            // Логическая переменная запоминающая последнее состояние светодиода
  
void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  butt = !digitalRead(3);              // Считать текущее состояние кнопки (1-нажата, 0-отпущена)
  
  if (butt == 1 && butt_flag == 0) {
    butt_flag = 1;
    led_flag = !led_flag;
    digitalWrite(13, led_flag);        // Состояние светодиода будет меняться при каждом нажатии на кнопку
    Serial.println("Button pressed");
  }
  if (butt == 0 && butt_flag == 1) {
    butt_flag = 0;
    Serial.println("Button released");
  }
  
}

/*****************************************************************/

boolean butt_flag = 0;           // Логическая переменная запоминающая последнее состояние кнопки
boolean butt;                    // Текущее значение кнопки
boolean led_flag = 0;            // Логическая переменная запоминающая последнее состояние светодиода
unsigned long last_press;        // Предотвращаем дребезг контакта  

void setup() {
  pinMode(3, INPUT_PULLUP);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  butt = !digitalRead(3);              // Считать текущее состояние кнопки (1-нажата, 0-отпущена)
  
  if (butt == 1 && butt_flag == 0 && millis() - last_press >= 50) {
    butt_flag = 1;
    led_flag = !led_flag;
    digitalWrite(13, led_flag);        // Состояние светодиода будет меняться при каждом нажатии на кнопку
    last_press = millis();
    Serial.println("Button pressed");
  }
  if (butt == 0 && butt_flag == 1) {
    butt_flag = 0;
    Serial.println("Button released");
  }
  
}

/******************************************************************************************/

