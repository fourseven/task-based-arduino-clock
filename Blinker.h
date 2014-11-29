#ifndef Blinker_H
#define Blinker_H

#include <Task.h>

// Timed task to blink a LED.
class Blinker : public TimedTask
{
public:
    // Create a new blinker for the specified pin and rate.
    Blinker(uint8_t _pin, uint32_t _rate);
    virtual void run(uint32_t now);
private:
    uint8_t pin;      // LED pin.
    uint32_t rate;    // Blink rate.
    bool on;          // Current state of the LED.
};

#endif
