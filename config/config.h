#pragma once

// -----------------------------------------------------------------------------

#define USE_SWITCH_CONTROLLER 1
// #define USE_KEYBOARD 1
// #define USE_LED 1

// -----------------------------------------------------------------------------

#include "../src/KeyPad.h"
#include "key_map.h"
#include "macro.h"
#include "handlers.h"

namespace config {
    int rowPinList[] = {0, 1, keypad::NOT_A_PIN};
    int colPinList[] = {4, 3, 2, keypad::NOT_A_PIN};

    // debounce threshold for switch, in microsecond.
    const unsigned long debounce = 700UL;
    // when a key press last longer then this amount of time, hold mapping for
    // this key will be triggered if exists, in microsecond.
    const unsigned long holdThreshold = 500UL * 1000UL;

    // how long should a CL command key press last, in millisecond.
    const unsigned long clickDelay = 80UL;
    // how long should keypad idle after an CL command key release, in millisecond.
    const unsigned long clickEndDelay = 80UL;

    int ledRedPin = 10;
    int ledOrnagePin = 9;
    int ledYellowPin = 8;
    int ledBluePin = 7;
}