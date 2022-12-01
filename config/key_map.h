#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::Record;

    Record *keyMap[] = {
        (Record[]){
            MACRO(1)    , HAT_BTN_UP  , OSL(1)       ,
            HAT_BTN_LEFT, HAT_BTN_DOWN, HAT_BTN_RIGHT,
        },
        (Record[]){
            BTN_X       , BTN_A       , EMPTY        ,
            BTN_Y       , BTN_B       , TL(2)        ,
        },
        (Record[]){
            MACRO(0)    , EMPTY       , TL(2)        ,
            EMPTY       , EMPTY       , DFL(1)       ,
        }
    };
}
