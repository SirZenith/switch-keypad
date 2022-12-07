#include "KeyboardHandler.h"

// -----------------------------------------------------------------------------

void backend::Keyboard::Begin() {
}

void backend::Keyboard::End() {
}

bool backend::Keyboard::Ready() {
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
    isDirty = true;
}

void backend::Keyboard::Release(unsigned long param) {
    isDirty = true;
}
