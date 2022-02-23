#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

#include <Wire.h>
#include <BMx280I2C.h>
BMx280I2C bmx280(0x76);


#define debug true// вывод отладочных сообщений
#define postingInterval  300000 // интервал между отправками данных в миллисекундах (5 минут)

unsigned long lastConnectionTime = 0;           // время последней передачи данных
String Hostname; //имя железки - выглядит как ESPAABBCCDDEEFF т.е. ESP+mac адрес.
int i;
void wifimanstart() { // Волшебная процедура начального подключения к Wifi.
  // Если не знает к чему подцепить - создает точку доступа ESP8266 и настроечную таблицу http://192.168.4.1
  // Подробнее: https://github.com/tzapu/WiFiManager
  WiFiManager wifiManager;
  wifiManager.setDebugOutput(debug);
  wifiManager.setMinimumSignalQuality();
  if (!wifiManager.autoConnect("ESP8266")) {
    if (debug) Serial.println("failed to connect and hit timeout");
    //  delay(3000);
    //reset and try again, or maybe put it to deep sleep
    ESP.deepSleep(330e6);//СПИМ 5 МИНУТ
   // ESP.reset();
  }
  //    delay(5000); }
  if (debug) Serial.println("connected...");
}

void setup() {
  Serial.begin(115200);
  Wire.begin();
  if (!bmx280.begin()) {
    Serial.println("begin() failed. check your BMx280 Interface and I2C Address.");
    while (1);
  }
  if (bmx280.isBME280())Serial.println("sensor is a BME280"); else Serial.println("sensor is a BMP280");
  bmx280.resetToDefaults();  //reset sensor to default parameters.
  bmx280.writeOversamplingPressure(BMx280MI::OSRS_P_x16);
  bmx280.writeOversamplingTemperature(BMx280MI::OSRS_T_x16);
  if (bmx280.isBME280()) bmx280.writeOversamplingHumidity(BMx280MI::OSRS_H_x16);//Для BME
  while (!bmx280.measure()) {
    delay(1000); // Ждем измерение
  }
  while (!bmx280.hasValue()) {
    delay (100);
  }
  Hostname = "ESP" + WiFi.macAddress();
  Hostname.replace(":", "");

  WiFi.hostname(Hostname);
  wifimanstart();
  Serial.println(WiFi.localIP()); Serial.println(WiFi.macAddress()); Serial.print("Narodmon ID: "); Serial.println(Hostname);
  lastConnectionTime = millis() - postingInterval + 15000; //первая передача на народный мониторинг через 15 сек.
}

bool SendToNarodmon() { // Собственно формирование пакета и отправка.
  bmx280.measure();
  WiFiClient client;
  String buf;
  buf = "#" + Hostname + "\r\n"; //mac адрес для авторизации датчика
  while (!bmx280.hasValue()) {
    delay (5);
  }
  buf = buf + "#TEMPC#" + String(bmx280.getTemperature()) + "#Датчик температуры\r\n"; //показания температуры
  if (bmx280.isBME280()) buf = buf + "#HUMID#" + String(bmx280.getHumidity()) + "#Датчик влажности\r\n"; //показания влажности
  buf = buf + "#PRESS#" + String(bmx280.getPressure64()) + "#Датчик давления\r\n"; //показания давления
  buf = buf + "##\r\n"; //окончание передачи


  // попытка подключения
  if (!client.connect("narodmon.ru", 8283)) {
    Serial.println("connection failed"); return false; // не удалось;
  }
  else  {
    client.print(buf); // и отправляем данные
    if (debug) Serial.print(buf);

    while (client.available()) {
      String line = client.readStringUntil('\r'); // если что-то в ответ будет - все в Serial
      Serial.print(line);
    }
  }
  return true; //ушло
}

void loop() {
  yield();
  if (i == 2) {Serial.print (millis()); ESP.deepSleep(330e6);}//уходим в мертвый сон на 330 секунд (+- 30 сек) как раз получается чуть больше 5 минут. 
  if (WiFi.status() == WL_CONNECTED) { // ну конечно если подключены
    if (SendToNarodmon()) i++;
  }
  yield();
}
