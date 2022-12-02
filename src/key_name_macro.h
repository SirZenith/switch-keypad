#pragma once

#include "KeyPad.h"
#include <SwitchControlLibrary.h>

using keypad::Operation;
using keypad::Record;

#define HOLD(tap, hold) \
    { tap, hold }

#define EMPTY \
    { Operation::EMPTY, 0 }
#define DELAY(time) \
    { Operation::DELAY, time }
#define MACRO(index) \
    { Operation::MACRO, index }
#define END(isRepeat) \
    { Operation::END, isRepeat }

// ----------------------------------------------------------------------------

#define ML(layer) \
    { Operation::MOMENT_LAYER, layer }
#define OSL(layer) \
    { Operation::ONE_SHOT_LAYER, layer }
#define TL(layer) \
    { Operation::TOGGLE_LAYER, layer }
#define DFL(layer) \
    { Operation::DEFAULT_LAYER, layer }

// ----------------------------------------------------------------------------

#define BTN_A \
    { Operation::BTN, Button::A }
#define BTN_B \
    { Operation::BTN, Button::B }
#define BTN_X \
    { Operation::BTN, Button::X }
#define BTN_Y \
    { Operation::BTN, Button::Y }
#define BTN_L \
    { Operation::BTN, Button::L }
#define BTN_R \
    { Operation::BTN, Button::R }
#define BTN_ZL \
    { Operation::BTN, Button::ZL }
#define BTN_ZR \
    { Operation::BTN, Button::ZR }
#define BTN_LCLICK \
    { Operation::BTN, Button::LCLICK }
#define BTN_RCLICK \
    { Operation::BTN, Button::RCLICK }
#define BTN_CAPTURE \
    { Operation::BTN, Button::CAPTURE }
#define BTN_HOME \
    { Operation::BTN, Button::HOME }
#define BTN_MINUS \
    { Operation::BTN, Button::MINUS }
#define BTN_PLUS \
    { Operation::BTN, Button::PLUS }

#define HAT_NEUTRAL \
    { Operation::Hat, Hat::NEUTRAL }
#define HAT_UP \
    { Operation::HAT, Hat::UP }
#define HAT_DOWN \
    { Operation::HAT, Hat::DOWN }
#define HAT_LEFT \
    { Operation::HAT, Hat::LEFT }
#define HAT_RIGHT \
    { Operation::HAT, Hat::RIGHT }
#define HAT_UP_LEFT \
    { Operation::HAT, Hat::UP_LEFT }
#define HAT_UP_RIGHT \
    { Operation::HAT, Hat::UP_RIGHT }
#define HAT_DOWN_LEFT \
    { Operation::HAT, Hat::DOWN_LEFT }
#define HAT_DOWN_RIGHT \
    { Operation::HAT, Hat::DOWN_RIGHT }

#define HAT_BTN_UP \
    { Operation::HAT_BTN, HatButton::UP }
#define HAT_BTN_DOWN \
    { Operation::HAT_BTN, HatButton::DOWN }
#define HAT_BTN_RIGHT \
    { Operation::HAT_BTN, HatButton::RIGHT }
#define HAT_BTN_LEFT \
    { Operation::HAT_BTN, HatButton::LEFT }

#define STICK_VALUE(x, y) (x << sizeof(uint8_t) | y)

#define L_STICK_UP \
    { Operation::L_STICK, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define L_STICK_DOWN \
    { Operation::L_STICK, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define L_STICK_LEFT \
    { Operation::L_STICK, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define L_STICK_RIGHT \
    { Operation::L_STICK, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define L_STICK_FREE(x, y) \
    { Operation::L_STICK, STICK_VALUE(x, y) }

#define R_STICK_UP \
    { Operation::R_STICK, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define R_STICK_DOWN \
    { Operation::R_STICK, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define R_STICK_LEFT \
    { Operation::R_STICK, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define R_STICK_RIGHT \
    { Operation::R_STICK, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define R_STICK_FREE(x, y) \
    { Operation::R_STICK, STICK_VALUE(x, y) }
