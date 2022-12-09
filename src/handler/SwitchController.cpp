#include "SwitchController.h"

// -----------------------------------------------------------------------------

backend::SwitchController::SwitchController(
    const keypad::Record **keyMap,
    const keypad::MacroRecord **macroList,
    unsigned int defaultLayer
) : KeyHandler(keyMap, macroList, defaultLayer) {}

void backend::SwitchController::Begin() {
    switch_controller::controller.Begin();
}

void backend::SwitchController::End() {
    switch_controller::controller.End();
}

bool backend::SwitchController::Ready() {
    return switch_controller::controller.Ready();
}

bool backend::SwitchController::Dirty() {
    return isDirty;
}

void backend::SwitchController::Send() {
    if (isDirty) {
        switch_controller::controller.SendReport();
        isDirty = false;
    }
}

// -----------------------------------------------------------------------------

void backend::SwitchController::Press(unsigned long param) {
    switch_controller::controller.Press((switch_controller::KeyCode)param);
    isDirty = true;
}

void backend::SwitchController::Release(unsigned long param) {
    switch_controller::controller.Release((switch_controller::KeyCode)param);
    isDirty = true;
}

// -----------------------------------------------------------------------------

const char *backend::SwitchController::Name() {
    return "Switch Controller";
}

void backend::SwitchController::OperationLog(const char *msg, const keypad::MacroRecord *re) {
    Serial.print(msg);

    if (re != nullptr) {
        const char *name = nullptr;
        unsigned long value = 0;

        using keypad::Operation;

        switch (re->type) {
        case Operation::PRESS:
        case Operation::RELEASE:
        case Operation::CLICK:
            using switch_controller::KeyCode;

            name = switch_controller::GetNameOfKeyCode((KeyCode)re->param);
            value = switch_controller::GetValueInKeyCode((KeyCode)re->param);
            break;

        default:
            name = keypad::GetOperatioinName(re->type);
            value = re->param;
            break;
        }
        Serial.print(name);
        Serial.print("(");
        Serial.print(value);
        Serial.print(")");
    }

    Serial.print("\n");
}
