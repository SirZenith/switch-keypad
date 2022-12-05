#include "common.h"

const char *keypad::GetOperatioinName(Operation type) {
    const char *name = nullptr;

    switch (type) {
    case Operation::EMPTY:
        name = "empty";
        break;
    // ----------------------------------------------------------------------------
    case Operation::DELAY:
        name = "delay";
        break;
    case Operation::CLICK_DELAY:
        name = "click-delay";
        break;
    case Operation::CLICK_END_DELAY:
        name = "click-end-delay";
        break;
    // ----------------------------------------------------------------------------
    case Operation::MACRO:
        name = "macro";
        break;
    case Operation::END:
        name = "end";
        break;
    // ----------------------------------------------------------------------------
    case Operation::MOMENT_LAYER:
        name = "goto-layer";
        break;
    case Operation::ONE_SHOT_LAYER:
        name = "one-shot-layer";
        break;
    case Operation::TOGGLE_LAYER:
        name = "toggle-layer";
        break;
    case Operation::DEFAULT_LAYER:
        name = "default-layer";
        break;
    // ----------------------------------------------------------------------------
    case Operation::PRESS:
        name = "press";
        break;
    case Operation::RELEASE:
        name = "release";
        break;
    case Operation::CLICK:
        name = "click";
        break;

    default:
        name = "unknown";
        break;
    }

    return name;
}

// ----------------------------------------------------------------------------

keypad::MacroRecord::MacroRecord() = default;

keypad::MacroRecord::MacroRecord(Operation op, unsigned long param)
    : type{op},
      param{param} {}

// ----------------------------------------------------------------------------

keypad::Record::Record(Operation op, unsigned long param)
    : MacroRecord(op, param),
      onHold{nullptr} {}

keypad::Record::Record(Record onTap, Record onHold)
    : MacroRecord(onTap.type, onTap.param),
      onHold{new Record(onHold.type, onHold.param)} {}

keypad::Record::~Record() {
    if (onHold != nullptr) {
        delete onHold;
    }
}

void keypad::Record::SetOnHold(MacroRecord r) {
    onHold = new Record(r.type, r.param);
}
