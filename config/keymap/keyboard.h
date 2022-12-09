#pragma once

#include "../../src/common.h"
#include "../../src/keycode/common.h"
#include "../../src/keycode/keyboard.h"

namespace config::keyboard {
    using keypad::Record;

    const unsigned int defaultLayer = 0;

    const Record arrowKeyLayer[] = {
        ML(1)            , PR_KEY_UP_ARROW  , HANDLER(0)        ,
        PR_KEY_LEFT_ARROW, PR_KEY_DOWN_ARROW, PR_KEY_RIGHT_ARROW,
    };

    const Record letterLayer[] = {
        EMPTY   , PR_KEY_E, PR_KEY_R,
        PR_KEY_S, PR_KEY_D, PR_KEY_F,
    };

    const Record *keymap[] = {
        arrowKeyLayer,
        letterLayer,
        NULL,
    };
}