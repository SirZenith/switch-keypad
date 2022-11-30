#pragma once

#include "KeyPad.h"
#include "key_name_macro.h"
#include <SwitchControlLibrary.h>

namespace config {
    using keypad::Operation;
    using keypad::Record;

    const int row = 2;
    const int col = 3;
    const int layer = 3;
    int rowPinList[] = {1, 0};
    int colPinList[] = {2, 3, 4};

    Record *keyMap[6] = {
        (Record[]){
            // row 1
            BTN_A, HAT_BTN_UP, MACRO(0),
            // row 2
            BTN_B, HAT_BTN_DOWN, MACRO(1),
        },
    };

    const int DEBOUNCE = 1;
    const int HOLD_THRESHOLD = 500;

    const int CLICK_DELAY = 80;
    const int KEY_END_DELAY = 80;
    const int SMALL_DIALOG_DELAY = 250;
    const int MEDIUM_DIALOG_DELAY = 500;
    const int LARGE_DIALOG_DELAY = 800;
    const int MENU_LOAD_DELAY = 2800;

    Record *macroList[] = {
        (Record[]){
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
        },
        (Record[]){
            BTN_A,
            BTN_B,
            END(false),
        }};
};