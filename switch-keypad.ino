#include <Arduino.h>

#include "config/config.h"
#include "src/KeyPad.h"

auto pad = keypad::KeyPad(
    config::row, config::col, config::layer,
    config::rowPinList, config::colPinList,
    config::keyMap, config::macroList,
    config::debounce, config::holdThreshold,
    config::clickDelay, config::clickEndDelay
);

void setup() {
#ifdef DEBUG
    Serial.begin(115200);
#endif

    pad.Begin();

    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LOW);

    for (int r = 0; r < config::row; ++r) {
        int rowPin = config::rowPinList[r];
        pinMode(rowPin, OUTPUT);
        digitalWrite(rowPin, HIGH);
    }

    for (int c = 0; c < config::col; ++c) {
        int colPin = config::colPinList[c];
        pinMode(colPin, INPUT_PULLUP);
    }

    while (!USBDevice.mounted()) {
        delay(1);
    }
}

void loop() {
    if (!pad.Ready()) {
        return;
    }

    pad.Scan();
    pad.Send();
    pad.PlayMacro();
}