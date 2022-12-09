#include "Keyboard.h"

// -----------------------------------------------------------------------------

handler::Keyboard::Keyboard(
    const keypad::Record **keyMap,
    const keypad::MacroRecord **macroList,
    unsigned int defaultLayer
) : KeyHandler(keyMap, macroList, defaultLayer) {}

void handler::Keyboard::Begin() {
    ::Keyboard.begin();
}

void handler::Keyboard::End() {
    ::Keyboard.end();
}

bool handler::Keyboard::Ready() {
    return true;
}

bool handler::Keyboard::Dirty() {
    return isDirty;
}

void handler::Keyboard::Send() {
    if (isDirty) {
        isDirty = false;
    }
}

// -----------------------------------------------------------------------------

void handler::Keyboard::Press(unsigned long param) {
    ::Keyboard.press(param);
    isDirty = true;
}

void handler::Keyboard::Release(unsigned long param) {
    ::Keyboard.release(param);
    isDirty = true;
}

void handler::Keyboard::ReleaseAll() {
    ::Keyboard.releaseAll();
}

// -----------------------------------------------------------------------------

const char *handler::Keyboard::Name() {
    return "Keyboard";
}

void handler::Keyboard::OperationLog(const char *msg, const keypad::MacroRecord *re) {
    Serial.print(msg);
    if (re != nullptr) {
        Serial.print(keypad::GetOperatioinName(re->type));
        Serial.print("(");
        Serial.print(re->param);
        Serial.print(")");
    }
    Serial.print("\n");
}
