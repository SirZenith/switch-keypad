#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::Record;

    const Record layer1[] = {
        // row1
        ML(2),
        PR_CROSS_BTN_UP,
        ML(1),
        // row2
        PR_CROSS_BTN_LEFT,
        PR_CROSS_BTN_DOWN,
        PR_CROSS_BTN_RIGHT,
    };

    const Record layer2[] = {
        // row1
        PR_BTN_X,
        PR_BTN_A,
        EMPTY,
        // row2
        PR_BTN_Y,
        PR_BTN_B,
        HOLD(PR_BTN_L, PR_BTN_R),
    };
    const Record layer3[] = {
        // row1
        EMPTY,
        MACRO(0),
        MACRO(1),
        // row2
        EMPTY,
        HOLD(MACRO_RECORD, MACRO_RECORD_LOOP),
        MACRO_PLAY_RECORDED,
    };

    const Record *keyMap[] = {
        layer1,
        layer2,
        layer3,
    };
}
