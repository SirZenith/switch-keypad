#pragma once

#include "../src/KeyHandler.h"

namespace config {
#ifdef USE_SWITCH_CONTROLLER
#include "../src/backend/SwitchController.h"
    auto switchController = backend::SwitchController(config::switchControllerDFL);
#endif

#ifdef USE_KEYBOARD
#include "../src/backend/Keyboard.h"
    auto keyboard = backend::Keyboard(config::keyboardDFL);
#endif

    using keypad::KeyHandler;
    KeyHandler *handlers[] = {
#ifdef USE_SWITCH_CONTROLLER
        (KeyHandler *)&switchController,
#endif
#ifdef USE_KEYBOARD
        (KeyHandler *)&keyboard,
#endif
        NULL,
    };
}