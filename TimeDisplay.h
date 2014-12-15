#ifndef TimeDisplay_h
#define TimeDisplay_h

#include <Task.h>
#include <SoftI2C.h>
#include <RTC.h>
#include <DS3232RTC.h>

// Task to echo serial input.
class TimeDisplay : public TimedTask
{
public:
    TimeDisplay(uint32_t _rate);
    virtual void run(uint32_t now);
    RTCTime * getTime();
private:
    SoftI2C i2c;
    DS3232RTC rtc;
    RTCTime time;
    uint32_t rate;    // Blink rate.
};

#endif
