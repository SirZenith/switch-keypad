#include <Arduino.h>

#include "config/config.h"
#include "src/KeyPad.h"

auto macroPlayer = keypad::MacroPlayer(config::macroList, config::clickDelay, config::clickEndDelay);

auto pad = keypad::KeyPad(
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

    pad.SetHandler(0);
    pad.Begin();

#ifdef USE_LED
    pinMode(config::ledRedPin, OUTPUT);
    pinMode(config::ledOrnagePin, OUTPUT);
    pinMode(config::ledYellowPin, OUTPUT);
    pinMode(config::ledBluePin, OUTPUT);

    pad.SetLEDPin(
        config::ledRedPin,
        config::ledOrnagePin,
        config::ledYellowPin,
        config::ledBluePin
    );
#endif

    for (int *pin = config::rowPinList; *pin != keypad::NOT_A_PIN; ++pin) {
        pinMode(*pin, INPUT_PULLUP);
    }

    for (int *pin = config::colPinList; *pin != keypad::NOT_A_PIN; ++pin) {
        pinMode(*pin, OUTPUT);
        digitalWrite(*pin, HIGH);
    }

    while (!USBDevice.mounted()) {
        delay(1);
    }
}

void loop() {
    pad.Step();
}