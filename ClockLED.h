#ifndef ClockLED_h
#define ClockLED_h

#include <Task.h>
#include "TimeReader.h"
#include "Adafruit_NeoPixel.h"

// Timed task to blink a LED.
class ClockLED : public TimedTask
{
public:
    // Create a new ClockLED for the specified pin and rate.
    ClockLED(TimeReader*, uint32_t);
    virtual void run(uint32_t);
    void tween(uint16_t, uint32_t);
private:
    void setSecondForPixels(uint8_t, Adafruit_NeoPixel*);
    void setMinuteForPixels(uint8_t, Adafruit_NeoPixel*);
    void setHourForPixels(uint8_t, Adafruit_NeoPixel*);
    void setPulse(uint32_t, Adafruit_NeoPixel*);
    void setMillisForSecond(uint8_t, uint32_t);
    uint8_t pointFor(int8_t);
    uint8_t lastSecond;
    Adafruit_NeoPixel pixels;
    TimeReader* timeReader;
    uint32_t rate;    // Blink rate.
};

#endif
