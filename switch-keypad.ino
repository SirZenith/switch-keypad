#include "config/config.h"
#include "src/KeyPad.h"

auto pad = keypad::KeyPad(
    config::row, config::col, config::layer,
    config::rowPinList, config::colPinList,
    config::keyMap, config::macroList,
    config::DEBOUNCE, config::HOLD_THRESHOLD,
    config::CLICK_DELAY, config::KEY_END_DELAY
);

void setup() {
    SwitchControlLibrary();

#ifdef DEBUG
    Serial.begin(115200);
#endif

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
}

void loop() {
    pad.Scan();
    pad.Send();
    pad.PlayMacro();
}