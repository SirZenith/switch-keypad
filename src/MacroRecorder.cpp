#include "MacroRecorder.h"

keypad::MacroRecorder::MacroRecorder() {
    records = new Record[capability];
}

keypad::MacroRecorder::MacroRecorder(unsigned cap) : capability{cap} {
    records = cap > 0 ? new Record[cap] : nullptr;
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
    return capability - size - 1;
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
    Record &target = records[size];
    target.type = Operation::END;
    target.param = (unsigned long)isLoop;
    ++size;
}

// ----------------------------------------------------------------------------

void keypad::MacroRecorder::Clear() {
    if (capability == 0) {
        return;
    }

    size = 0;
    Record &target = records[0];
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

const keypad::Record *keypad::MacroRecorder::GetMacro() {
    return records;
}

// ----------------------------------------------------------------------------

void keypad::MacroRecorder::Push(Operation type, unsigned long param) {
    Record &target = records[size];
    target.type = type;
    target.param = param;
    ++size;
}