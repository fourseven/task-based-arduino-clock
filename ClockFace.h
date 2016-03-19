#ifndef ClockFace_h
#define ClockFace_h

#include <Adafruit_NeoPixel.h>
#include "RTC.h"

// Timed task to blink a LED.
class ClockFace {
public:
    // Create a new Clock for the specified pin and rate.
    ClockFace(Adafruit_NeoPixel*);
    virtual void updateFace(RTCTime*) = 0;
protected:
    void tween(uint16_t, uint32_t);

    Adafruit_NeoPixel* pixels;
    uint8_t pointFor(int8_t);
};

#endif
