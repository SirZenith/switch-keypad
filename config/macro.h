#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::MacroRecord;
    using switch_controller::KeyCode;

    const unsigned long SMALL_DIALOG_DELAY = 100;
    const unsigned long MEDIUM_DIALOG_DELAY = 300;
    const unsigned long LARGE_DIALOG_DELAY = 600;
    const unsigned long MENU_LOAD_DELAY = 2500;

    const MacroRecord macroItemCopy[] = {
        CL_BTN_A,
        DELAY(SMALL_DIALOG_DELAY),

        CL_HAT_BTN_DOWN,
        CL_HAT_BTN_DOWN,
        CL_HAT_BTN_DOWN,
        CL_HAT_BTN_DOWN,
        DELAY(SMALL_DIALOG_DELAY),
        CL_HAT_BTN_DOWN,
        CL_BTN_A,
        DELAY(LARGE_DIALOG_DELAY),

        CL_BTN_A,
        CL_BTN_A,
        DELAY(MENU_LOAD_DELAY),

        CL_BTN_A,
        DELAY(SMALL_DIALOG_DELAY),

        CL_HAT_BTN_UP,
        CL_HAT_BTN_RIGHT,
        CL_HAT_BTN_DOWN,
        CL_HAT_BTN_DOWN,
        CL_BTN_A,

        DELAY(MENU_LOAD_DELAY),

        CL_BTN_X,
        CL_BTN_X,
        CL_BTN_L,

        CL_BTN_A,

        DELAY(SMALL_DIALOG_DELAY),

        CL_HAT_BTN_DOWN,
        CL_HAT_BTN_DOWN,
        CL_HAT_BTN_DOWN,
        CL_BTN_A,

        DELAY(MEDIUM_DIALOG_DELAY),

        CL_BTN_B,

        DELAY(MENU_LOAD_DELAY),

        CL_HAT_BTN_UP,
        CL_HAT_BTN_LEFT,
        CL_HAT_BTN_UP,
        CL_HAT_BTN_UP,

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
    };
}
