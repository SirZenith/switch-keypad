#include "Keyboard.h"

// -----------------------------------------------------------------------------

void backend::Keyboard::Begin() {
    ::Keyboard.begin();
}

void backend::Keyboard::End() {
    ::Keyboard.end();
}

bool backend::Keyboard::Ready() {
    return true;
}

bool backend::Keyboard::Dirty() {
    return isDirty;
}

void backend::Keyboard::Send() {
    if (isDirty) {
        isDirty = false;
    }
}

// -----------------------------------------------------------------------------

void backend::Keyboard::Press(unsigned long param) {
    ::Keyboard.press(param);
    isDirty = true;
}

void backend::Keyboard::Release(unsigned long param) {
    ::Keyboard.release(param);
    isDirty = true;
}

// -----------------------------------------------------------------------------

void backend::Keyboard::OperationLog(const char *msg, const keypad::MacroRecord *re) {
}
