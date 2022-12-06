#include "MacroRecorder.h"

keypad::MacroRecorder::MacroRecorder() {
    records = new MacroRecord[capacity];
}

keypad::MacroRecorder::MacroRecorder(unsigned cap) : capacity{cap} {
    records = cap > 0 ? new MacroRecord[cap] : nullptr;
}

keypad::MacroRecorder::~MacroRecorder() {
    if (records != nullptr) {
        delete[] records;
    }
}

// ----------------------------------------------------------------------------

bool keypad::MacroRecorder::IsRecording() {
    return isRecording;
}

unsigned keypad::MacroRecorder::SpareSpace() {
    // save 1 slot for Operation::END record, that's what "-1" for.
    return capacity - size - 1;
}

unsigned keypad::MacroRecorder::Capacity() {
    return capacity;
}

// ----------------------------------------------------------------------------

void keypad::MacroRecorder::ToggleRecording(bool isLoop) {
    if (IsRecording()) {
        EndRecording(isLoop);
    } else {
        StartRecording();
    }
}

void keypad::MacroRecorder::StartRecording() {
    Clear();
    isRecording = true;
    lastRecordTime = 0;
}

void keypad::MacroRecorder::EndRecording(bool isLoop) {
    bool ok = TryRecord(Record(Operation::END, 0));

    if (!ok) {
        MacroRecord &target = records[size];
        target.type = Operation::END;
        target.param = (unsigned long)isLoop;
        ++size;
    }
}

// ----------------------------------------------------------------------------

void keypad::MacroRecorder::Clear() {
    if (capacity == 0) {
        return;
    }

    size = 0;
    MacroRecord &target = records[0];
    target.type = Operation::END;
    target.param = (unsigned long)false;
}

bool keypad::MacroRecorder::TryRecord(const Record &re) {
    if (!isRecording || SpareSpace() == 0) {
        return false;
    }

    unsigned long now = millis();
    if (lastRecordTime != 0) {
        Push(Operation::DELAY, now - lastRecordTime);
    }
    lastRecordTime = now;

    Push(re.type, re.param);

    return true;
}

// ----------------------------------------------------------------------------

const keypad::MacroRecord *keypad::MacroRecorder::GetMacro() {
    return records;
}

// ----------------------------------------------------------------------------

void keypad::MacroRecorder::Push(Operation type, unsigned long param) {
    MacroRecord &target = records[size];
    target.type = type;
    target.param = param;
    ++size;
}