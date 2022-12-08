#pragma once

#include "../src/KeyHandler.h"
#include "../src/backend/Keyboard.h"
#include "../src/backend/SwitchController.h"
#include "key_map.h"

namespace config {
#ifdef USE_SWITCH_CONTROLLER
    auto switchController = backend::SwitchController(config::switchControllerDFL);
#endif

#ifdef USE_KEYBOARD
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