#include "TimeReader.h"
#include <Arduino.h>
#include <Task.h>

TimeReader::TimeReader(uint32_t _rate)
: TimedTask(millis()),
    i2c(A4, A5),
    rtc(i2c),
    rate(_rate)
{
   time.hour   = 19;
   time.minute = 03;
   time.second = 30;
   rtc.writeTime(&time);
}

RTCTime * TimeReader::getTime()
{
  return &time;
}

void TimeReader::run(uint32_t now)
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

