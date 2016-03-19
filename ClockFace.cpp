#include "ClockFace.h"

ClockFace::ClockFace(Adafruit_NeoPixel* pixels) : pixels(pixels) {

}

void ClockFace::tween(uint16_t idx, uint32_t color) {
    uint32_t temp_color = pixels->getPixelColor(idx);
    pixels->setPixelColor(idx, color | temp_color);
}

// Takes what could be a negative number and returns the index on the neopixels array.
uint8_t ClockFace::pointFor(int8_t index) {
    return (index + pixels->numPixels()) % pixels->numPixels();
}
