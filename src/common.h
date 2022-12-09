#pragma once

#include <Arduino.h>

namespace keypad {
    static const int NOT_A_PIN = -1;

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
        // -----------------------------------------------------------------------------
        // handler
        CHANGE_HANDLER,
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

        MacroRecord();
        MacroRecord(Operation op, unsigned long param);
    };

    struct Record : MacroRecord {
        Record *onHold = nullptr;

        Record(Operation op, unsigned long param);
        Record(Record onTap, Record onHold);
        ~Record();

        void SetOnHold(MacroRecord r);
    };
}
