#include "ClockLED.h"

#include <Arduino.h>
#include <Task.h>

#include "Adafruit_NeoPixel.h"

#define NUMPIXELS 60
#define PIN        9


ClockLED::ClockLED(TimeDisplay* _timeDisplay, uint32_t _rate)
: TimedTask(millis()),
  timeDisplay(_timeDisplay),
  rate(_rate),
  pixels(Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800))
{
    pixels.begin();
}

void ClockLED::tween(uint16_t idx, uint32_t color) {
    uint32_t temp_color = pixels.getPixelColor(idx);
    pixels.setPixelColor(idx, color | temp_color);
}

void ClockLED::run(uint32_t now)
{

    RTCTime *time = timeDisplay->getTime();
    uint8_t i;
    uint16_t idx;

    uint16_t subtime = now % 60;

    // Serial.print(time->hour, DEC);
    // Serial.write(':');
    // Serial.print(time->minute, DEC);
    // Serial.write(':');
    // Serial.print(time->second, DEC);
    // Serial.write('\n');
    pixels.clear();

    for (i = 0; i < 2; i ++) {
      pixels.setPixelColor((subtime - i) % 60, pixels.Color(1,1,1));
    }

    tween(time->second, pixels.Color(0,50,0));
    tween(time->minute, pixels.Color(50,0,0));
    for (i = 1; i < 2; i ++) {
      tween((time->minute - i) % 60, pixels.Color(10,0,0));
      tween((time->minute + i) % 60, pixels.Color(10,0,0));
    }
    idx = (time->hour % 12) *5 % 60;
    tween(idx, pixels.Color(0,0,40));
    for (i = 1; i < 3; i ++) {
      tween((idx - i) % 60, pixels.Color(0,0,10));
      tween((idx + i) % 60, pixels.Color(0,0,10));
    }
    pixels.show(); // This sends the updated pixel color to the hardware.

    // Run again in the required number of milliseconds.
    incRunTime(rate);
}
