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

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}
bool flag = false;
uint32_t btnTimer = 0;
void loop() {
  // читаем инвертированное значение для удобства
  bool btnState = !digitalRead(3);
  if (btnState && !flag && millis() - btnTimer > 100) {
    flag = true;
    btnTimer = millis();
    Serial.println("press");
  }
  if (!btnState && flag && millis() - btnTimer > 100) {
    flag = false;
    btnTimer = millis();
    Serial.println("release");
  }
}

/******************************************************/


void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

bool flag = false;
uint32_t btnTimer = 0;
void loop() {
  // читаем инвертированное значение для удобства
  bool btnState = !digitalRead(3);
  if (btnState && !flag && millis() - btnTimer > 100) {
    flag = true;
    btnTimer = millis();
    Serial.println("press");
  }
  if (btnState && flag && millis() - btnTimer > 500) {
    btnTimer = millis();
    Serial.println("press hold");
  }
  if (!btnState && flag && millis() - btnTimer > 500) {
    flag = false;
    btnTimer = millis();
    Serial.println("release");
  }
}

/*******************************************************************/

boolean butt_flag = 0;           // Логическая переменная запоминающая последнее состояние кнопки
boolean butt;                    // Текущее значение кнопки
boolean led_flag = 0;            // Логическая переменная запоминающая последнее состояние светодиода
unsigned long last_press;        // Предотвращаем дребезг контакта  
byte LEDcounter = 4;

void setup() {
  Serial.begin(9600);
  
  pinMode(3, INPUT_PULLUP);      // Кнопка
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  
}

void loop() {
  butt = !digitalRead(3);              // Считать текущее состояние кнопки (1-нажата, 0-отпущена)
  
  if (butt == 1 && butt_flag == 0 && millis() - last_press >= 120) {
    butt_flag = 1;
    Serial.println("Button pressed");
    
    digitalWrite(LEDcounter, 1);        // Начинаем с 4 выхода подавать напряжение на светодиод
    LEDcounter ++;                      
    
    last_press = millis();
    
  }
  if (butt == 0 && butt_flag == 1 && millis() - last_press >= 120) {
    butt_flag = 0;
    last_press = millis();
    Serial.println("Button released");
  }
  
}

/**************************************************************************/

boolean butt_flag = 0;           // Логическая переменная запоминающая последнее состояние кнопки
boolean butt;                    // Текущее значение кнопки
boolean led_flag = 0;            // Логическая переменная запоминающая последнее состояние светодиода
unsigned long last_press;        // Предотвращаем дребезг контакта  
byte LEDcounter = 4;
byte BUTTcounter = 0;


void setup() {
  Serial.begin(9600);
  
  pinMode(3, INPUT_PULLUP);      // Кнопка
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  
  digitalWrite(4, 0);
  digitalWrite(5, 0);
  digitalWrite(6, 0);
  digitalWrite(7, 0);
  
}

void loop() {
  butt = !digitalRead(3);              // Считать текущее состояние кнопки (1-нажата, 0-отпущена)
  
  if (butt == 1 && butt_flag == 0 && millis() - last_press >= 120) {
    butt_flag = 1;
    Serial.println("Button pressed");

      if (BUTTcounter <= 3) {
        digitalWrite(LEDcounter, 1);            // Начинаем с 4 выхода подавать напряжение на светодиод
        LEDcounter ++;
      } else {
        LEDcounter --;
        digitalWrite(LEDcounter, 0);
        
    }
    BUTTcounter ++;
    last_press = millis();
    
  }
  if (butt == 0 && butt_flag == 1 && millis() - last_press >= 120) {
    butt_flag = 0;
    last_press = millis();
    Serial.println("Button released");
  }
  
}

/*********************************************************************************/

#define button_pin 3    // Пин кнопки
#define relay_pin 6     // Пин реле

boolean butt_flag = 0;  // Флаг нажатия кнопки
boolean butt;           // Переменная хранящая состояние кнопки
boolean flag = 0;       // Флаг режима
uint32_t last_press;    // Таймер для фильтра дребезга

void setup() {
   pinMode(button_pin, INPUT_PULLUP);  // Кнопка подтянута внутренним резистором
   pinMode(relay_pin, OUTPUT);         // Пин реле как выход
}

void loop() {
  butt = !digitalRead(button_pin);    // Считать текущее положение кнопки
  if (butt == 1 && butt_flag == 0 && millis() - last_press > 150) {
    butt_flag = 1;         // Запоминаем что нажимали кнопку
    flag = !flag;          // Инвертируем флажок (Первый проход меняет с 0 на 1 а второй с 1 на 0)
    last_press = millis(); // Сбрасываем счётчик

    digitalWrite(relay_pin, flag);    // Подаём сигнал на пин реле (
  }
  if (butt == 0 && butt_flag == 1) {  // Если кнопка опущенна и до этого была нажата
    butt_flag = 0;                    // Запоминаем что отпустили кнопку
  }
}

/***********************************************************************************/

#define button_pin 3    // Пин кнопки
#define relay_pin1 6     // Пин реле
#define relay_pin2 7

boolean butt_flag = 0;  // Флаг нажатия кнопки
boolean butt;           // Переменная хранящая состояние кнопки
boolean flag = 0;       // Флаг режима
uint32_t last_press;    // Таймер для фильтра дребезга

void setup() {
   pinMode(button_pin, INPUT_PULLUP);  // Кнопка подтянута внутренним резистором
   pinMode(relay_pin1, OUTPUT);         // Пин реле как выход
   pinMode(relay_pin2, OUTPUT);
}

void loop() {
  butt = !digitalRead(button_pin);    // Считать текущее положение кнопки
  if (butt == 1 && butt_flag == 0 && millis() - last_press > 150) {
    butt_flag = 1;         // Запоминаем что нажимали кнопку
    flag = !flag;          // Инвертируем флажок (Первый проход меняет с 0 на 1 а второй с 1 на 0)
    last_press = millis(); // Сбрасываем счётчик

    digitalWrite(relay_pin1, flag);    // Подаём сигнал на пин реле
    digitalWrite(relay_pin2, !flag);
  }
  if (butt == 0 && butt_flag == 1) {  // Если кнопка опущенна и до этого была нажата
    butt_flag = 0;                    // Запоминаем что отпустили кнопку
  }
}

/*******************************************Среднее значение****************************************************/

byte myVals[] = {5, 60, 214, 36, 98, 156};
int sum = 0;

void setup() {
  Serial.begin(9600);
    for (int i = 0; i < 6; i++) {
    sum += myVals[i];
  }
  sum /= 6;
  Serial.println(sum);
}

void loop() {

}

/******************************************Сокращения****************************************************************/


int i = 0;

void setup() {
  Serial.begin(9600);
    for (; i < 60; i += 10) { 
      Serial.println(i);
}

}
void loop() {

}
// 0, 10, 20, 30, 40, 50 Получаем
/*********************************2 значения***************************************.


void setup() {
  Serial.begin(9600);
    for (byte i = 0, j = 0; i < 10; i++, j += 2) { 
      Serial.println(j);
      
}

}
void loop() {


  // тут i меняется от 0 до 9
  // и j меняется от 0 до 18
/*******************************Функции*******************************************/

int potA, potB;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potA = analogRead(0);
  potB = analogRead(1);
  myFunction(potA, potB);
}

void myFunction(int valA, int valB) {
  long SUM = valA + valB;
  Serial.print(valA); Serial.print(" "); Serial.println(valB);
  Serial.println(SUM);
  delay(100);
}
/*******************************************************************************************/

int potA, potB;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potA = analogRead(0);
  potB = analogRead(1);
  Serial.println(myFunction(potA, potB));
  delay(100);
}

long myFunction(int valA, int valB) {
  return valA * valB;
}
/***********************************Перегруженные функции************************************/
int c;
int a;
float d;

void setup() {
  float af = 5.5;
  float bf = 0.25;

  Serial.begin(9600);

  a = sumFunction(10, 20);
  c = sumFunction(10, 20, 30);
  d = sumFunction(af, bf);
  Serial.println(a);
  Serial.println(c);
  Serial.println(d);
}

void loop() {
}

int sumFunction(int paramA, int paramB) {
  return (paramA + paramB); 
}

int sumFunction(int paramA, int paramB, int paramC) {
  return (paramA + paramB + paramC);
}

float sumFunction(float paramA, float paramB) {
  return (paramA + paramB);
}
/**********************Возвращение нескольких значений******************************/

struct MyStruct {
  int valSum;
  int valSub;
  int valMul;
};

void setup() {
  Serial.begin(9600);
  MyStruct str;
  str = compute(3, 4);
  Serial.println(str.valSum);
  Serial.println(str.valSub);
  Serial.println(str.valMul);
}

void loop() {
}

MyStruct compute(int val1, int val2) {
  MyStruct str;
  str.valSum = val1 + val2;
  str.valSub = val1 - val2;
  str.valMul = val1 * val2;
  return str;
}
/**************************Генератор случайных чисел через наводку с A0******************************************************/
void setup() {
  Serial.begin(9600);
 randomSeed(analogRead(0));  // С какого числа начинать отсчитывать случайные числа
 pinMode(13, OUTPUT);
}


void loop() {
digitalWrite(13, HIGH);
delay(random(100, 600));
digitalWrite(13, LOW);
delay(random(100, 600));
}
/********************Генератор случайных чисел из таблицы ANSI**********************/

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(A0));
}
void loop() {
  for(int i = 0; i < random(3, 8); i++) {
    Serial.write(random(58, 63)); 
  }
  Serial.println();
  delay(300);
}

/********************************Массивы***************************************/
// указываем количество ячеек и всё, дальше можно с ними работать
int myInts[6];
// указываем содержимое ячеек, компилятор сам посчитает их количество
int myPins[] = {2, 4, 8, 3, 6};
// указываем и то и то, количество ячеек в [ ] должно совпадать с { } или быть больше!
float Sens[3] = {0.2, 0.4, -8.5};
// храним символы
char message[6] = "hello";

/*****************************Прерывания******************************/
volatile byte count;

void setup() {
   Serial.begin(9600);
   pinMode(3, INPUT_PULLUP);
   attachInterrupt(1, myInterrupt, FALLING);     // Подключить прерывание
     
}

void loop() {
  Serial.println(count);
  delay(500);
}

void myInterrupt() {
    count++;
}
/***********************************************************/
