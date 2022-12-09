#pragma once

#include "../../src/common.h"
#include "../../src/keycode/common.h"
#include "../../src/keycode/switch.h"
#include "../../src/keycode/keyboard.h"

namespace config::switch_controller {
    using keypad::MacroRecord;

    const unsigned long SMALL_DIALOG_DELAY = 100;
    const unsigned long MEDIUM_DIALOG_DELAY = 300;
    const unsigned long LARGE_DIALOG_DELAY = 600;
    const unsigned long MENU_LOAD_DELAY = 2500;

    const MacroRecord macroItemCopy[] = {
        CL_BTN_A,
        DELAY(SMALL_DIALOG_DELAY),

        CL_CROSS_BTN_DOWN,
        CL_CROSS_BTN_DOWN,
        CL_CROSS_BTN_DOWN,
        CL_CROSS_BTN_DOWN,
        DELAY(SMALL_DIALOG_DELAY),
        CL_CROSS_BTN_DOWN,
        CL_BTN_A,
        DELAY(LARGE_DIALOG_DELAY),

        CL_BTN_A,
        CL_BTN_A,
        DELAY(MENU_LOAD_DELAY),

        CL_BTN_A,
        DELAY(SMALL_DIALOG_DELAY),

        CL_CROSS_BTN_UP,
        CL_CROSS_BTN_RIGHT,
        CL_CROSS_BTN_DOWN,
        CL_CROSS_BTN_DOWN,
        CL_BTN_A,

        DELAY(MENU_LOAD_DELAY),

        CL_BTN_X,
        CL_BTN_X,
        CL_BTN_L,

        CL_BTN_A,

        DELAY(SMALL_DIALOG_DELAY),

        CL_CROSS_BTN_DOWN,
        CL_CROSS_BTN_DOWN,
        CL_CROSS_BTN_DOWN,
        CL_BTN_A,

        DELAY(MEDIUM_DIALOG_DELAY),

        CL_BTN_B,

        DELAY(MENU_LOAD_DELAY),

        CL_CROSS_BTN_UP,
        CL_CROSS_BTN_LEFT,
        CL_CROSS_BTN_UP,
        CL_CROSS_BTN_UP,

        END(true),
    };

    const MacroRecord macroSendToBoxBugTrigger[] = {
        CL_BTN_A,
        CL_BTN_B,
        END(false),
    };

    const MacroRecord *macroList[] = {
        macroItemCopy,
        macroSendToBoxBugTrigger,
        NULL,
    };
}
