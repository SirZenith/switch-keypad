#include "Keyboard.h"

// -----------------------------------------------------------------------------

backend::Keyboard::Keyboard(unsigned int defaultLayer)
    : KeyHandler(defaultLayer) {}

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

const char *backend::Keyboard::Name() {
    return "Keyboard";
}

void backend::Keyboard::OperationLog(const char *msg, const keypad::MacroRecord *re) {
    Serial.print(msg);
    if (re != nullptr) {
        Serial.print(keypad::GetOperatioinName(re->type));
        Serial.print("(");
        Serial.print(re->param);
        Serial.print(")");
    }
    Serial.print("\n");
}
