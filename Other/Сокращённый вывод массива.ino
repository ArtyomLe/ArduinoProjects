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
