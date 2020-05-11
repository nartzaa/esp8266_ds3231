// Set date and time using a DS1307 RTC connected via I2C
/*
  esp8266
    D1 > SCL
    D2 > SDA
*/


#include <Wire.h>
#include <SPI.h>  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"

RTC_DS3231 RTC;     // Setup an instance of DS1307 naming it RTC

void setup () {
  Serial.begin(115200); // Set serial port speed
  Wire.begin(); // Start the I2C
  RTC.begin();  // Init RTC
  //RTC.adjust(DateTime(__DATE__, __TIME__));  // Time and date is expanded to date and time on your computer at compiletime
  Serial.print('Time and date set');
}

void loop () {
  DateTime now = RTC.now();
  float temp = RTC.getTemperature();

  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.print(", ");
  Serial.print(temp);
  Serial.println();

  delay(3000);
}