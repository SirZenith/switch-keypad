#pragma once

#include "../common.h"

using keypad::Operation;

#define HOLD(tap, hold) \
    { tap, hold }

#define EMPTY \
    { Operation::EMPTY, 0 }

// -----------------------------------------------------------------------------

#define DELAY(time) \
    { Operation::DELAY, time }
#define CLICK_DELAY \
    { Operation::CLICK_DELAY, 0 }
#define CLICK_END_DELAY \
    { Operation::CLICK_END_DELAY, 0 }

// -----------------------------------------------------------------------------

#define MACRO(index) \
    { Operation::MACRO, index }
#define MACRO_RECORD \
    { Operation::MACRO_RECORD, 0 }
#define MACRO_RECORD_LOOP \
    { Operation::MACRO_RECORD_LOOP, 0 }
#define MACRO_PLAY_RECORDED \
    { Operation::MACRO_PLAY_RECORDED, 0 }
#define END(isRepeat) \
    { Operation::END, isRepeat }

// -----------------------------------------------------------------------------

#define ML(layer) \
    { Operation::MOMENT_LAYER, layer }
#define OSL(layer) \
    { Operation::ONE_SHOT_LAYER, layer }
#define TL(layer) \
    { Operation::TOGGLE_LAYER, layer }
#define DFL(layer) \
    { Operation::DEFAULT_LAYER, layer }

// -----------------------------------------------------------------------------

#define HANDLER(i) \
    { Operation::CHANGE_HANDLER, i }
