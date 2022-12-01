#pragma once

#include "../src/KeyPad.h"
#include "../src/key_name_macro.h"
#include "key_map.h"
#include "macro.h"
#include <SwitchControlLibrary.h>

namespace config {
    const int row = 2;
    const int col = 3;
    const int layer = 7;
    int rowPinList[] = {1, 0};
    int colPinList[] = {2, 3, 4};

    const unsigned long DEBOUNCE = 50UL;
    const unsigned long HOLD_THRESHOLD = 500UL * 1000UL;

    const unsigned long CLICK_DELAY = 80UL;
    const unsigned long KEY_END_DELAY = 80UL;
}