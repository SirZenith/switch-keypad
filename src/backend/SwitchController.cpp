#include "SwitchController.h"

// -----------------------------------------------------------------------------

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
