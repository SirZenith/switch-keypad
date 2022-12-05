#pragma once

#include <Arduino.h>

namespace keypad {
    enum class Operation : uint8_t {
        EMPTY,
        // --------------------------------------------------------------------
        // delay
        DELAY,
        CLICK_DELAY,
        CLICK_END_DELAY,
        // --------------------------------------------------------------------
        // macro releated
        MACRO,
        MACRO_RECORD,
        MACRO_RECORD_LOOP,
        MACRO_PLAY_RECORDED,
        END,
        // --------------------------------------------------------------------
        // layering
        MOMENT_LAYER,
        ONE_SHOT_LAYER,
        TOGGLE_LAYER,
        DEFAULT_LAYER,
        // --------------------------------------------------------------------
        // button operation
        PRESS,
        RELEASE,
        CLICK
    };

    const char *GetOperatioinName(Operation type);

    struct MacroRecord {
        Operation type;
        unsigned long param;
    };

    struct Record : MacroRecord {
        Operation type;
        unsigned long param;
        Record *onHold = nullptr;

        Record(Operation op, unsigned long param);
        Record(Record onTap, Record onHold);
        ~Record();

        void SetOnHold(MacroRecord r);
    };

    struct Key {
        enum State {
            TRIGGERED,
            PRESSED,
            HELD,
            RELEASED,
        };

        State state = State::RELEASED;
        unsigned long updatetime = 0;
        bool isHoldTriggered = false;
        // if layer will change after this key is pressed
        // then we should remember on which layer we pressed this key on,
        // so that we can release it on the same layer,
        // but not releasing another key code on changed layer.
        int layer;
    };
}
