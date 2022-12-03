#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::Record;

    const Record layer1[] = {
        ML(2), PR_HAT_BTN_UP, ML(1),
        PR_HAT_BTN_LEFT, PR_HAT_BTN_DOWN, PR_HAT_BTN_RIGHT,
    };

    const Record layer2[] = {
        PR_BTN_X, PR_BTN_A, EMPTY,
        PR_BTN_Y, PR_BTN_B, HOLD(PR_BTN_L, PR_BTN_R),
    };
    const Record layer3[] = {
        EMPTY, MACRO(0), MACRO(1),
        EMPTY, PR_BTN_L, PR_BTN_R,
    };

    const Record *keyMap[] = {
        layer1,
        layer2,
        layer3,
    };
}
