#ifndef ClockLED_h
#define ClockLED_h

#include <Task.h>
#include "TimeDisplay.h"
#include "Adafruit_NeoPixel.h"

// Timed task to blink a LED.
class ClockLED : public TimedTask
{
public:
    // Create a new ClockLED for the specified pin and rate.
    ClockLED(TimeDisplay* _timeDisplay, uint32_t _rate);
    virtual void run(uint32_t now);
    void tween(uint16_t idx, uint32_t color);
private:
    uint8_t pin;
    Adafruit_NeoPixel pixels;
    TimeDisplay* timeDisplay;
    uint32_t rate;    // Blink rate.
};

#endif
