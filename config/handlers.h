#pragma once

#include "../src/KeyHandler.h"

#include "../src/handler/SwitchController.h"
#include "keymap/switch_controller.h"
#include "macro/switch_controller.h"

#include "../src/handler/Keyboard.h"
#include "keymap/keyboard.h"
#include "macro/keyboard.h"

namespace config {
#ifdef USE_SWITCH_CONTROLLER
    auto switchControllerHandler = handler::SwitchController(
        config::switch_controller::keymap,
        config::switch_controller::macroList,
        config::switch_controller::defaultLayer
    );
#endif

#ifdef USE_KEYBOARD
    auto keyboardHandler = handler::Keyboard(
        config::keyboard::keymap,
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