#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"

namespace config {
    using keypad::Record;

    Record *keyMap[] = {
        (Record[]){
            ML(2)    , HAT_BTN_UP  , ML(1)       ,
            HAT_BTN_LEFT, HAT_BTN_DOWN, HAT_BTN_RIGHT,
        },
        (Record[]){
            BTN_X       , BTN_A       , EMPTY        ,
            BTN_Y       , BTN_B       , EMPTY        ,
        },
        (Record[]){
            EMPTY       , MACRO(0)    , MACRO(1)     ,
            EMPTY       , BTN_L       , BTN_R        ,
        }
    };
}
