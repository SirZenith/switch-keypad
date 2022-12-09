#pragma once

#include "../../src/common.h"
#include "../../src/keycode/common.h"
#include "../../src/keycode/switch.h"

namespace config::switch_controller {
    using keypad::Record;

    const unsigned int defaultLayer = 0;

    const Record baseLayer[] = {
        ML(2)            , PR_CROSS_BTN_UP  , ML(1)             ,
        PR_CROSS_BTN_LEFT, PR_CROSS_BTN_DOWN, PR_CROSS_BTN_RIGHT,
    };

    const Record functionKeyLayer[] = {
        PR_BTN_X, PR_BTN_A, EMPTY                   ,
        PR_BTN_Y, PR_BTN_B, HOLD(PR_BTN_L, PR_BTN_R),
    };

    const Record macroLayer[] = {
        EMPTY     , MACRO(0)                             , MACRO(1)           ,
        HANDLER(1), HOLD(MACRO_RECORD, MACRO_RECORD_LOOP), MACRO_PLAY_RECORDED,
    };

    const Record *keymap[] = {
        baseLayer,
        functionKeyLayer,
        macroLayer,
        NULL,
    };
}
