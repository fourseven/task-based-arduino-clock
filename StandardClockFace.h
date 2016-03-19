#ifndef StandardClockFace_h
#define StandardClockFace_h

#include "ClockFace.h"
#include "Adafruit_NeoPixel.h"

// Timed task to blink a LED.
class StandardClockFace : public ClockFace {
public:
    // Create a new Clock for the specified pin and rate.
    StandardClockFace(Adafruit_NeoPixel*);
    void updateFace(RTCTime*);
private:
    void setSecondForPixels(uint8_t);
    void setMinuteForPixels(uint8_t);
    void setHourForPixels(uint8_t);
    // void setPulse(uint32_t);
};

#endif


