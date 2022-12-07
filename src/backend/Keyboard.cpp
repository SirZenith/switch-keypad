#include "Keyboard.h"

// -----------------------------------------------------------------------------

void backend::Keyboard::Begin() {
    keyboard.begin();
}

void backend::Keyboard::End() {
    keyboard.end();
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
    keyboard.press(param);
    isDirty = true;
}

void backend::Keyboard::Release(unsigned long param) {
    keyboard.release(param);
    isDirty = true;
}

// -----------------------------------------------------------------------------

void backend::Keyboard::OperationLog(const char *msg, const keypad::MacroRecord *re) {
}
