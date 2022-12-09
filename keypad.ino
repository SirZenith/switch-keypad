#include <Arduino.h>

#include "config/config.h"
#include "src/KeyPad.h"

auto macroPlayer = keypad::MacroPlayer(config::clickDelay, config::clickEndDelay);

auto pad = keypad::KeyPad(
    config::rowPinList, config::colPinList,
    config::debounce, config::holdThreshold,
    macroPlayer,
    config::handlers
);

void setup() {
#ifdef DEBUG
    Serial.begin(115200);
#endif

    pad.SetHandler(0);

#ifdef USE_LED
    pinMode(config::ledRedPin, OUTPUT);
    pinMode(config::ledOrnagePin, OUTPUT);
    pinMode(config::ledYellowPin, OUTPUT);
    pinMode(config::ledBluePin, OUTPUT);

    digitalWrite(config::ledRedPin, HIGH);
    digitalWrite(config::ledOrnagePin, HIGH);
    digitalWrite(config::ledYellowPin, HIGH);
    digitalWrite(config::ledBluePin, HIGH);

    pad.SetLEDPin(
        config::ledRedPin,
        config::ledOrnagePin,
        config::ledYellowPin,
        config::ledBluePin
    );
#else
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, HIGH);
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