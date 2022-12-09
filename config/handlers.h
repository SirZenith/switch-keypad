#pragma once

#include "../src/KeyHandler.h"

#include "../src/handler/SwitchController.h"
#include "key_map/switch_controller.h"
#include "macro/switch_controller.h"

#include "../src/handler/Keyboard.h"
#include "key_map/keyboard.h"
#include "macro/keyboard.h"

namespace config {
#ifdef USE_SWITCH_CONTROLLER
    auto switchControllerHandler = backend::SwitchController(
        config::switch_controller::keyMap,
        config::switch_controller::macroList,
        config::switch_controller::defaultLayer
    );
#endif

#ifdef USE_KEYBOARD
    auto keyboardHandler = backend::Keyboard(
        config::keyboard::keyMap,
        config::keyboard::macroList,
        config::keyboard::defaultLayer
    );
#endif

    using keypad::KeyHandler;
    KeyHandler *handlers[] = {

#ifdef USE_SWITCH_CONTROLLER
        (KeyHandler *)&switchControllerHandler,
#endif

#ifdef USE_KEYBOARD
        (KeyHandler *)&keyboardHandler,
#endif

        NULL,
    };
}