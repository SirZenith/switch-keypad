#pragma once

#include "../../src/common.h"
#include "../../src/keycode/common.h"
#include "../../src/keycode/keyboard.h"

namespace config::keyboard {
    using keypad::Record;

    const unsigned int defaultLayer = 0;

    const Record arrowKeyLayer[] = {
        // row1
        ML(1),
        PR_KEY_UP_ARROW,
        HANDLER(0),
        // row2
        PR_KEY_LEFT_ARROW,
        PR_KEY_DOWN_ARROW,
        PR_KEY_RIGHT_ARROW,
    };

    const Record *keyMap[] = {
        arrowKeyLayer,
        NULL,
    };
}