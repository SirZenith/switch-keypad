#pragma once

#include "common.h"
#include <Arduino.h>

namespace keypad {
    class MacroRecorder {
    public:
        static const unsigned DEFAULT_RECORD_CAPABILITY = 100;

        MacroRecorder();
        MacroRecorder(unsigned cap);
        ~MacroRecorder();

        bool IsRecording();
        unsigned SpareSpace();
        unsigned Capacity();

        void ToggleRecording(bool isLoop = false);
        void StartRecording();
        void EndRecording(bool isLoop);

        void Clear();
        bool TryRecord(const Record &re);

        const MacroRecord *GetMacro();

    private:
        bool isRecording = false;
        unsigned size = 0;
        unsigned capacity = DEFAULT_RECORD_CAPABILITY;
        unsigned long lastRecordTime = 0;
        MacroRecord *records;

        void Push(Operation type, unsigned long param);
    };
}
