#ifndef AppleDarkClockFace_h
#define AppleDarkClockFace_h

#include <Adafruit_NeoPixel.h>
#include "ClockFace.h"

// Timed task to blink a LED.
class AppleDarkClockFace : public ClockFace {
public:
    // Create a new Clock for the specified pin and rate.
    AppleDarkClockFace(Adafruit_NeoPixel*);
    void updateFace(RTCTime*);
private:
    void setSecondForPixels(uint8_t);
    void setMinuteForPixels(uint8_t);
    void setHourForPixels(uint8_t);
    void setPulse(uint32_t);
};

#endif


