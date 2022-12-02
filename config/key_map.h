#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::Record;

    const Record layer1[] = {
        ML(2), HAT_BTN_UP, ML(1),
        HAT_BTN_LEFT, HAT_BTN_DOWN, HAT_BTN_RIGHT,
    };

    const Record layer2[] = {
        BTN_X, BTN_A, EMPTY,
        BTN_Y, BTN_B, HOLD(BTN_L, BTN_R),
    };
    const Record layer3[] = {
        EMPTY, MACRO(0), MACRO(1),
        EMPTY, BTN_L, BTN_R,
    };

    const Record *keyMap[] = {
        layer1,
        layer2,
        layer3,
    };
}
