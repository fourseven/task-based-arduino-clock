#include "StandardClockFace.h"

StandardClockFace::StandardClockFace(Adafruit_NeoPixel* pixels) : ClockFace(pixels) {}

void StandardClockFace::updateFace(RTCTime* time) {
    setSecondForPixels(time->second);
    setMinuteForPixels(time->minute);
    setHourForPixels(time->hour);
    // setPulse(millis());
}

void StandardClockFace::setSecondForPixels(uint8_t second) {
    tween(second, pixels->Color(0,50,0));
}

void StandardClockFace::setMinuteForPixels(uint8_t minute) {
    tween(minute, pixels->Color(50,0,0));
    for (uint8_t i = 1; i < 2; i ++) {
        tween(pointFor(minute - i), pixels->Color(10,0,0));
        tween(pointFor(minute + i), pixels->Color(10,0,0));
    }
}

void StandardClockFace::setHourForPixels(uint8_t hour) {
    int8_t idx = (hour % 12) * 5;
    tween(idx, pixels->Color(0,0,40));
    for (uint8_t i = 1; i < 3; i ++) {
        tween(pointFor(idx - i), pixels->Color(0,0,10));
        tween(pointFor(idx + i), pixels->Color(0,0,10));
    }
}

void StandardClockFace::setPulse(uint32_t now) {
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
