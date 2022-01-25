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
void setup() {
  Serial.begin(9600);
  int val1 = 1234;
  int val2 = 5678;
  String str;
  str = str + "http://website.co.il/request?param1=" + val1 + "&param2=" + val2;
  Serial.println(str);
}

void loop() {
  
}
//===========================================СТРОКА================================================
void setup() {
  Serial.begin(9600);
  int val1 = 1234;
  int val2 = 5678;
  /*
  String str;
  str = str + "http://website.co.il/request?param1=" + val1 + "&param2=" + val2;
  Serial.println(str);
  */

  /*
   * strcat(str1, str2)
   * Прибавляет str2 к str1, при этом str1 должна иметь достаточный для этого размер. 
   * NULL первой строки заменяется на первый символ из str2
   *    *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
   * itoa(int_data, str, base) – записывает переменную типа int int_data в строку str с базисом* base.
   * ltoa (long_data, str, base) – записывает переменную типа long long_data в строку str с базисом* base.
   */
   
  char cstr[60] = "";
  strcat(cstr, "http://website.co.il/request?param1=");
  /* Вариант 1
   *  char cint[10];
   *  itoa(val1, cint, DEC);
   *  strcat(cstr, cint);
   *  Serial.println(cstr);
   */
  
  itoa(val1, cstr + strlen(cstr), DEC);   // Вариант 2 (короче, только одна строка)
  strcat(cstr, "&param2=");
  itoa(val2, cstr + strlen(cstr), DEC);
  // Вместо "cstr + strlen(cstr)" можно записать itoa(val2, strchr(cstr, NULL), DEC); Находим 0 окончание строки и добавляем значение
  Serial.println(cstr);
}

void loop() {
  
}
//=================================================Преобразование строки в число====================================
void setup() {
  Serial.begin(9600);
   
 char cstr[] = "12345";
 int val1 = atoi(cstr);
 Serial.println(val1);

// Выполняется в 2 раза дольше
 String str = "12346";
 int val2 = str.toInt();
 Serial.println(val2);
}

void loop() {
  
}
//=========================================================String str=====================================================
void setup() {
  Serial.begin(9600);

String str = "parameter, 3269";                            // Входящая строка которую нужно разделить
int comma = str.indexOf(',');                              // Находим позицию запятой
String namevalue = str.substring(0, comma);                // Создаём новую строку и присваиваем ей значение от 0 до ,
Serial.println(namevalue);                                 // Вывод в порт
int value = str.substring(comma+1, str.length()).toInt();  // Создаём доп. строку от 1 символа после , до конца строки и указываем что это число (.toInt)
Serial.println(value);                                     // Вывод в порт

}
void loop() {
}
//===========================================================Char cstr===================================================
void setup() {
  Serial.begin(9600);
// strchr(str, symb)         "Ищет символ symb в строке str и возвращает указатель на первое совпадение."
// strncpy(str1, str2, num)  "Копирует num символов из начала str2 в начало str1"

char cstr[] = "parameter, 3269";
char* comma = strchr(cstr, ',');       // Указатель на первую попавшуюся , в строке
char namevalue[10] = "";               // Создаём новую строку
strncpy(namevalue, cstr, comma-cstr);  // Разность между указателем на запятую и на начало строки (в данном случае 9)
int valuenum = atoi(++comma);          // Получаем значение(число) один символ после запятой 
Serial.println(namevalue);
Serial.println(valuenum);

}
void loop() {
}
//=================================================================================================================
void setup() {
  Serial.begin(9600);
// strchr(str, symb)         "Ищет символ symb в строке str и возвращает указатель на первое совпадение."
// strncpy(str1, str2, num)  "Копирует num символов из начала str2 в начало str1"

/*
char cstr[] = "parameter, 3269";
char* comma = strchr(cstr, ',');       // Указатель на первую попавшуюся , в строке
char namevalue[10] = "";               // Создаём новую строку
strncpy(namevalue, cstr, comma-cstr);  // Разность между указателем на запятую и на начало строки (в данном случае 9)
int valuenum = atoi(++comma);          // Получаем значение(число) один символ после запятой 
Serial.println(namevalue);
Serial.println(valuenum);
*/

//Замена запятой на NULL и получение указателя на начало числа (способ 2)
char cstr[] = "parameter, 3269";
char* comma = strchr(cstr, ',');        // Указатель на первую попавшуюся , в строке
comma[0] = NULL;                        // Указываем что строка заканчивается на том месте где раньше была запятая
int valuenum = atoi(++comma);           // Получаем значение(число) один символ после запятой
Serial.println(cstr);
Serial.println(valuenum);

}
void loop() {
}
