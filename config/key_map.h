#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::Record;

    Record *keyMap[] = {
        (Record[]){
            EMPTY, HAT_BTN_UP, TL(1),
            HAT_BTN_LEFT, HAT_BTN_DOWN, HAT_BTN_RIGHT,
        },
        (Record[]){
            BTN_X, BTN_A, TL(1),
            BTN_Y, BTN_B, EMPTY,
        },
    };
}
