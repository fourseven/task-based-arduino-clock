#include "ClockLED.h"

#include <Arduino.h>
#include <Task.h>

#include "Adafruit_NeoPixel.h"

#define NUMPIXELS 60
#define PIN        9


ClockLED::ClockLED(TimeReader* _timeReader, uint32_t _rate)
: TimedTask(millis()),
  timeReader(_timeReader),
  rate(_rate),
  pixels(Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800))
{
    pixels.begin();
}

void ClockLED::tween(uint16_t idx, uint32_t color) {
    uint32_t temp_color = pixels.getPixelColor(idx);
    pixels.setPixelColor(idx, color | temp_color);
}

void ClockLED::run(uint32_t now) {

    RTCTime *time = timeReader->getTime();

    pixels.clear();

    // setMillisForSecond(time->second, now);

    setSecondForPixels(time->second, &pixels);
    setMinuteForPixels(time->minute, &pixels);
    setHourForPixels(time->hour, &pixels);

    // setPulse(now, &pixels);

    pixels.show(); // This sends the updated pixel color to the hardware.

    // Run again in the required number of milliseconds.
    incRunTime(rate);
}

// Takes what could be a negative number and returns the index on the neopixels array.
uint8_t ClockLED::pointFor(int8_t index) {
    return (index + NUMPIXELS) % NUMPIXELS;
}

void ClockLED::setSecondForPixels(uint8_t second, Adafruit_NeoPixel* pixels) {
    tween(second, pixels->Color(0,50,0));
}

void ClockLED::setMinuteForPixels(uint8_t minute, Adafruit_NeoPixel* pixels) {
    tween(minute, pixels->Color(50,0,0));
    for (uint8_t i = 1; i < 2; i ++) {
        tween(pointFor(minute - i), pixels->Color(10,0,0));
        tween(pointFor(minute + i), pixels->Color(10,0,0));
    }
}

void ClockLED::setHourForPixels(uint8_t hour, Adafruit_NeoPixel* pixels) {
    int8_t idx = (hour % 12) * 5;
    tween(idx, pixels->Color(0,0,40));
    for (uint8_t i = 1; i < 3; i ++) {
        tween(pointFor(idx - i), pixels->Color(0,0,10));
        tween(pointFor(idx + i), pixels->Color(0,0,10));
    }
}

void ClockLED::setPulse(uint32_t now, Adafruit_NeoPixel* pixels) {
    uint16_t millisecond = now % 1000;
    static uint8_t output = 0;
    uint8_t actualOutput = 0;
    if (millisecond < 500) {
      output += 1;
    }
    else {
      output -= 1;
    }
    Serial.println(millisecond, DEC);
    actualOutput = output >> 4;

    for (uint8_t i = 0; i < pixels->numPixels(); i++) {
        tween(i, pixels->Color(actualOutput,actualOutput,actualOutput));
    }
}

void ClockLED::setMillisForSecond(uint8_t second, uint32_t now) {
    // if (second > lastSecond) {
    //     millisOnSecondChange = now % 1000;
    //     lastSecond = second;
    // }
}
