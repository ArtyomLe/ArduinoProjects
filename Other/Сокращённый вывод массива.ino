  int vals[] = {10, 11, 12, 13, 14};

void setup() {
  Serial.begin(9600);

       for (int i = 0; i < sizeof(vals); i++) {
       Serial.println(vals[i]);  
       }
}

void loop() {

}
/*
 * Сокращённая версия вывода массива:
 * 
 *   int vals[] = {10, 11, 12, 13, 14};

void setup() {
  Serial.begin(9600);

       for (int val : vals) {
       Serial.println(val);  
       }
}

void loop() {

}

 */
/********************Предоставление доступа через & с последующим обнулением*********/

int vals[] = {10, 11, 12, 13, 14};

void setup() {
  Serial.begin(9600);
  for (int &val : vals) {
    val = 0;
    Serial.println(val);
  }

}

void loop() {
  
}
/***************Забиваем массив от 0 - 90 с шагом 10*****************/
int vals[10];
int count = 0;

void setup() {
  Serial.begin(9600);
  for (int &val : vals) {
    val = count * 10;
    count++;
    Serial.println(val);
  }

}
void loop() {
 
}
/***********************Выведет первых 5 значений и остановится*********************************/
int myArray[100];

void setup() {
  Serial.begin(9600);
  for(int i = 0; i < 100; i++) {
        if (i == 5) break;
    myArray[i] = 25;
    Serial.println(myArray[i]);

  }
}

void loop() {
  
}
/*************************************************************************************/
