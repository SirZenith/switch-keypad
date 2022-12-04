#pragma once

#include "common.h"
#include <Arduino.h>

namespace keypad {
    class MacroRecorder {
    public:
        const unsigned MAX_RECORD_CAPABILITY = 200;

        MacroRecorder();
        MacroRecorder(unsigned cap);
        ~MacroRecorder();

        bool IsRecording();
        unsigned SpareSpace();

        void ToggleRecording(bool isLoop = false);
        void StartRecording();
        void EndRecording(bool isLoop);

        void Clear();
        bool TryRecord(const Record &re);

        const Record *GetMacro();

    private:
        bool isRecording = false;
        unsigned size = 0;
        unsigned capability = MAX_RECORD_CAPABILITY;
        unsigned long lastRecordTime = 0;
        Record *records;

        void Push(Operation type, unsigned long param);
    };
}
