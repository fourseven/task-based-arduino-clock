#include "TimeDisplay.h"
#include <Arduino.h>
#include <Task.h>

TimeDisplay::TimeDisplay(uint32_t _rate)
: TimedTask(millis()),
    i2c(A4, A5),
    rtc(i2c),
    rate(_rate)
{
   time.hour   = 21;
   time.minute = 45;
   time.second = 00;
   rtc.writeTime(&time);
}

RTCTime * TimeDisplay::getTime()
{
  return &time;
}

void TimeDisplay::run(uint32_t now)
{
    rtc.readTime(&time);

    // Serial.print(time.hour, DEC);
    // Serial.write(':');
    // Serial.print(time.minute, DEC);
    // Serial.write(':');
    // Serial.print(time.second, DEC);
    // Serial.write('\n');

    incRunTime(100);
}

