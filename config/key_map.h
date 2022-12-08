#pragma once

#include "../src/common.h"
#include "../src/keycode/common.h"

#ifdef USE_SWITCH_CONTROLLER
#include "../src/keycode/switch.h"
#endif

#ifdef USE_KEYBOARD
#include "../src/keycode/keyboard.h"
#endif

namespace config {
    using keypad::Record;

    unsigned int switchControllerDFL = 0;
    unsigned int keyboardDFL = 0;

    const Record baseLayer[] = {
        // row1
        ML(2),
        PR_CROSS_BTN_UP,
        ML(1),
        // row2
        PR_CROSS_BTN_LEFT,
        PR_CROSS_BTN_DOWN,
        PR_CROSS_BTN_RIGHT,
    };

    const Record functionKeyLayer[] = {
        // row1
        PR_BTN_X,
        PR_BTN_A,
        EMPTY,
        // row2
        PR_BTN_Y,
        PR_BTN_B,
        HOLD(PR_BTN_L, PR_BTN_R),
    };

    const Record macroLayer[] = {
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
        baseLayer,
        functionKeyLayer,
        macroLayer,
        NULL,
    };
}
