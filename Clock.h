#ifndef Clock_h
#define Clock_h

#include <Task.h>
#include "TimeReader.h"
#include "Adafruit_NeoPixel.h"
#include "ClockFace.h"

// Timed task to blink a LED.
class Clock : public TimedTask
{
public:
    // Create a new Clock for the specified pin and rate.
    Clock(TimeReader*, uint32_t);
    virtual void run(uint32_t);
    void tween(uint16_t, uint32_t);
private:
    void reverse();
    ClockFace* clockFace;
    Adafruit_NeoPixel* pixels;
    TimeReader* timeReader;
    uint32_t rate;    // Blink rate.
};

#endif
