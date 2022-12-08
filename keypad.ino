#include <Arduino.h>

#include "config/config.h"
#include "src/KeyPad.h"

auto macroPlayer = keypad::MacroPlayer(config::macroList, config::clickDelay, config::clickEndDelay);

auto pad = keypad::KeyPad(
    config::row, config::col,
    config::rowPinList, config::colPinList,
    config::debounce, config::holdThreshold,
    config::keyMap,
    macroPlayer,
    config::handlers
);

void setup() {
#ifdef DEBUG
    Serial.begin(115200);
#endif

    pad.Begin();
    pad.SetHandler(0);
#ifdef USE_LED
    pad.SetLEDPin(
        config::ledRedPin,
        config::ledOrnagePin,
        config::ledYellowPin,
        config::ledBluePin
    );
#endif

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
    pad.Step();
}