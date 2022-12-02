#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::Record;

    const unsigned long SMALL_DIALOG_DELAY = 250;
    const unsigned long MEDIUM_DIALOG_DELAY = 500;
    const unsigned long LARGE_DIALOG_DELAY = 800;
    const unsigned long MENU_LOAD_DELAY = 2800;

    const Record macroItemCopy[] = {
        BTN_A,
        DELAY(SMALL_DIALOG_DELAY),

        HAT_BTN_DOWN,
        HAT_BTN_DOWN,
        HAT_BTN_DOWN,
        HAT_BTN_DOWN,
        HAT_BTN_DOWN,
        BTN_A,
        DELAY(LARGE_DIALOG_DELAY),

        BTN_A,
        BTN_A,
        DELAY(MENU_LOAD_DELAY),

        BTN_A,
        HAT_BTN_UP,
        HAT_BTN_RIGHT,
        HAT_BTN_DOWN,
        HAT_BTN_DOWN,
        BTN_A,

        DELAY(MENU_LOAD_DELAY),

        BTN_X,
        BTN_X,
        BTN_L,

        BTN_A,

        DELAY(SMALL_DIALOG_DELAY),

        HAT_BTN_DOWN,
        HAT_BTN_DOWN,
        HAT_BTN_DOWN,
        BTN_A,

        DELAY(MEDIUM_DIALOG_DELAY),

        BTN_B,

        DELAY(MENU_LOAD_DELAY),

        HAT_BTN_UP,
        HAT_BTN_LEFT,
        HAT_BTN_UP,
        HAT_BTN_UP,

        END(true),
    };

    const Record macroSendToBoxBugTrigger[] = {
        BTN_A,
        BTN_B,
        END(false),
    };

    const Record *macroList[] = {
        macroItemCopy,
        macroSendToBoxBugTrigger,
    };
}
