#include "Echoer.h"
#include <Arduino.h>
#include <Task.h>

Echoer::Echoer()
: Task()
{
    Serial.begin(9600);
}

bool Echoer::canRun(uint32_t now)
{
    return Serial.available() > 0;
}

void Echoer::run(uint32_t now)
{
    while (Serial.available() > 0) {
        int byte = Serial.read();
        Serial.write(byte);
        if (byte == '\r') {
            Serial.write('\n');
        }
    }
}
