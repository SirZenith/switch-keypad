#include <Arduino.h>

#include "config/config.h"
#include "src/KeyPad.h"
#include "src/backend/SwitchController.h"
#include "src/backend/Keyboard.h"

using keypad::KeyHandler;

auto macroPlayer = keypad::MacroPlayer(config::macroList, config::clickDelay, config::clickEndDelay);

auto switchController = backend::SwitchController();
auto keyboard = backend::Keyboard();
KeyHandler *handlers[] = {
    (KeyHandler *)&switchController,
    (KeyHandler *)&keyboard,
    NULL,
};

auto pad = keypad::KeyPad(
    config::row, config::col, config::layer,
    config::rowPinList, config::colPinList,
    config::debounce, config::holdThreshold,
    config::keyMap,
    macroPlayer,
    handlers
);

void setup() {
#ifdef DEBUG
    Serial.begin(115200);
#endif

    pad.Begin();
    pad.SetHandler(0);

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
    pad.PlayMacro();

    pad.Send();
    pad.UpdateLEDs();
}