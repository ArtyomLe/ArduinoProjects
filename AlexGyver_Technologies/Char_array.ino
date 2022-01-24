void setup() {
  Serial.begin(9600);
  char str[30] = "Hello World from Arduino";
  str[13] = '\0';                                // Указываем окончание (0) массива символов 
  Serial.println(str);
  Serial.println(strlen(str));
  Serial.println(sizeof(str));
  
}

void loop() {
  
}
//================================================================================================
void setup() {
  Serial.begin(9600);
  char str[30] = "Hello World from Arduino";
  str[11] = '\0';
  char* strP = str + 6;              // Выводим новый указатель(и получим строку начинающуюся с этой позиции)
  Serial.println(strP);
  Serial.println(strlen(strP));
  Serial.println(sizeof(strP));
  
}

void loop() {
  
}
//=================================================================================================
