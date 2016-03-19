#include "AppleClockFace.h"

AppleClockFace::AppleClockFace(Adafruit_NeoPixel* pixels) : ClockFace(pixels) {}

void AppleClockFace::updateFace(RTCTime* time) {
    setSecondForPixels(time->second);
    setMinuteForPixels(time->minute);
    setHourForPixels(time->hour);
}

void AppleClockFace::setSecondForPixels(uint8_t second) {
    for (uint8_t i = 0; i < second; i ++) {
        tween(i, pixels->Color(0,50,0));
    }
}

void AppleClockFace::setMinuteForPixels(uint8_t minute) {
    for (uint8_t i = 0; i < minute; i ++) {
        tween(i, pixels->Color(50,0,0));
    }
}

void AppleClockFace::setHourForPixels(uint8_t hour) {
    int8_t convertedHour = (hour % 12) * 5;
    for (uint8_t i = 0; i < convertedHour; i ++) {
        tween(i, pixels->Color(0,0,40));
    }
}

void AppleClockFace::setPulse(uint32_t now) {
    uint16_t millisecond = now % 1000;
    static uint8_t output = 0;
    uint8_t actualOutput = 0;
    if (millisecond <= 10 || millisecond >= 989)  {
      output = 0;
    } else if (millisecond < 500) {
      output += 1;
    }
    else {
      output -= 1;
    }

    actualOutput = output >> 4;

    for (uint8_t i = 0; i < pixels->numPixels(); i++) {
        tween(i, pixels->Color(actualOutput,actualOutput,actualOutput));
    }
}
