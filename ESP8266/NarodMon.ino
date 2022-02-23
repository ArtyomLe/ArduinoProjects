
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Ticker.h>

ESP8266WiFiMulti WiFiMulti;
Ticker sender;
bool sendtonm;
OneWire oneWire(2); // DS18B20 подключен по схеме https://goo.gl/HJ9TB9 Зеленый проводок подключен к GPIO2
DallasTemperature sensors(&oneWire);

void setup() {
  WiFi.mode(WIFI_STA); // Режим станции
  // Здесь настройки ВАШЕГО WIFI
  WiFiMulti.addAP("Shelly&Ella", "326910734"); // Данные вашего WiFi <<<<< ---------------  ОБРАТИТЕ ВНИМАНИЕ.
  // Здесь настройки ВАШЕГО WIFI
  sender.attach(305, STM); // Создаем событие отправки данных каждые 305 сек (5 мин + 5 сек, чтобы народный мониторинг не ругался если мы на секунду раньше отправили)
  sensors.begin(); //Запуск DS18B20
}

void STM() {
  sendtonm = true; // Отправка данных разрешена
}

void loop() {
  if ((WiFiMulti.run() == WL_CONNECTED)) {
    if (sendtonm) { // Если прошло 5 минут, и можно отправлять - работаем.
      sendtonm = false; // отключаем флаг отправки данных
      sensors.requestTemperatures();                                          // Команда на замер температуры.
      delay(1000);                                                            // Задержка для того чтобы датчик успел провести замер.
      DeviceAddress tempDeviceAddress;                                        // Переменная для получения адреса датчика
      String buf;                                                             // Буфер для отправки на NarodMon
      buf = "#ESP" + WiFi.macAddress() + "\r\n"; buf.replace(":", "");        //формируем заголовок
      sensors.getAddress(tempDeviceAddress, 0);                               // Получаем уникальный адрес датчика
      buf = buf + "#";
      for (uint8_t i = 0; i < 8; i++) {
        if (tempDeviceAddress[i] < 16) buf = buf + "0";                       // адрес датчика в буфер
        buf = buf + String(tempDeviceAddress[i], HEX);
      }
      buf = buf + "#" + String(sensors.getTempCByIndex(0)) + "\r\n";          //и температура
      buf = buf + "##\r\n";                                                    // закрываем пакет
      WiFiClient client;
      client.connect("narodmon.ru", 8283);                                     //Подключаемся
      client.print(buf);                                                      // И отправляем данные
    }
  }
}
