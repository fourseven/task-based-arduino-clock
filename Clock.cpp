#include "Clock.h"

#include <Arduino.h>
#include <Task.h>
#include <Adafruit_NeoPixel.h>

#include "StandardClockFace.h"
#include "AppleClockFace.h"
#include "AppleDarkClockFace.h"

#define NUMPIXELS 60
#define PIN        9


Clock::Clock(TimeReader* _timeReader, uint32_t _rate)
: TimedTask(millis()),
  timeReader(_timeReader),
  rate(_rate),
  pixels(new Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800))
{
    clockFace = new AppleClockFace(pixels);
    pixels->begin();
}

void Clock::run(uint32_t now) {

    RTCTime *time = timeReader->getTime();

    pixels->clear();

    clockFace->updateFace(time);

    reverse();


    pixels->show(); // This sends the updated pixel color to the hardware.

    // Run again in the required number of milliseconds.
    incRunTime(rate);
}

void Clock::reverse() {
    uint32_t tempColor;
    for (uint8_t i = 0; i < NUMPIXELS / 2; i++) {
      uint8_t topNumber = NUMPIXELS - i - 1;
      uint8_t bottomNumber = i;
      tempColor = pixels->getPixelColor(topNumber);
      pixels->setPixelColor(topNumber, pixels->getPixelColor(bottomNumber));
      pixels->setPixelColor(bottomNumber, tempColor);
    }
}
