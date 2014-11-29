#include "Blinker.h"

#include <Arduino.h>
#include <Task.h>

Blinker::Blinker(uint8_t _pin, uint32_t _rate)
: TimedTask(millis()),
  pin(_pin),
  rate(_rate),
  on(false)
{
    pinMode(pin, OUTPUT);     // Set pin for output.
}

void Blinker::run(uint32_t now)
{
    // If the LED is on, turn it off and remember the state.
    if (on) {
        digitalWrite(pin, LOW);
        on = false;
    // If the LED is off, turn it on and remember the state.
    } else {
        digitalWrite(pin, HIGH);
        on = true;
    }
    // Run again in the required number of milliseconds.
    incRunTime(rate);
}
