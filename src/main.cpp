/** @brief Test realtime clock on M5Stack Core2
 * @author Louis Bertrand <louis@bertrandtech.ca>
 * 
 * Based on PCF8563_Alarms example in RTC by Michael Miller
*/


#include <M5Core2.h>
#include "I2C_BM8563.h"

// RTC BM8563 I2C port
// I2C pin definition for M5Stack Core2
#define BM8563_I2C_SDA 21
#define BM8563_I2C_SCL 22
I2C_BM8563 rtc(I2C_BM8563_DEFAULT_ADDRESS, Wire1);


// Declare test functions


void setup()
{
  Serial.begin(115200);
  Serial.println("Hello M5Stack");
  /// Hardware configurations
  M5.begin();

  // Init I2C
  Wire1.begin(BM8563_I2C_SDA, BM8563_I2C_SCL);
  // Init RTC
  rtc.begin();

  M5.Lcd.clear();
  M5.lcd.setRotation(3);
  M5.Lcd.setTextFont(1);
  M5.Lcd.setTextColor(TFT_WHITE, TFT_BLACK);
  M5.Lcd.setCursor(0, 10);

  /* The very first test would be to read the RTC to see if
     it's initialized when the Core2 is first received.
  */

  I2C_BM8563_DateTypeDef dateStruct;
  I2C_BM8563_TimeTypeDef timeStruct;

  // Get RTC
  rtc.getDate(&dateStruct);
  rtc.getTime(&timeStruct);

  // Print RTC
  Serial.printf("%04d/%02d/%02d %02d:%02d:%02d\n",
                dateStruct.year,
                dateStruct.month,
                dateStruct.date,
                timeStruct.hours,
                timeStruct.minutes,
                timeStruct.seconds
               );

  M5.Lcd.printf("%04d/%02d/%02d %02d:%02d:%02d\n",
                dateStruct.year,
                dateStruct.month,
                dateStruct.date,
                timeStruct.hours,
                timeStruct.minutes,
                timeStruct.seconds
               );


}

// Do nothing after tests are done
void loop()
{
    Serial.println("Idle");
    delay(2000);
}

