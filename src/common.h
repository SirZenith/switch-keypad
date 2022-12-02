#pragma once

namespace keypad {
    enum DelayType {
        CLICK_DELAY = -1,
        KEY_END_DELAY = -2
    };

    enum Operation {
        EMPTY,
        DELAY,
        END,
        MACRO,
        // --------------------------------------------------------------------
        MOMENT_LAYER,
        ONE_SHOT_LAYER,
        TOGGLE_LAYER,
        DEFAULT_LAYER,
        // --------------------------------------------------------------------
        BTN,
        HAT,
        HAT_BTN,
        L_STICK,
        R_STICK
    };

    const char *GetOperatioinName(Operation type);

    struct Record {
        Operation type;
        unsigned long param;
        Record *onHold = nullptr;

        Record(Operation op, unsigned long param);
        Record(Record onTap, Record onHold);
        ~Record();

        void SetOnHold(Record r);
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
