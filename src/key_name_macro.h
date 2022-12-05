#pragma once

#include "KeyPad.h"

using keypad::Operation;
using switch_controller::KeyCode;
using switch_controller::Stick;

#define HOLD(tap, hold) \
    { tap, hold }

#define EMPTY \
    { Operation::EMPTY, 0 }

// ----------------------------------------------------------------------------

#define DELAY(time) \
    { Operation::DELAY, time }
#define CLICK_DELAY(time) \
    { Operation::CLICK_DELAY, 0 }
#define CLICK_END_DELAY(time) \
    { Operation::CLICK_END_DELAY, 0 }

//----------------------------------------------------------------------------

#define MACRO(index) \
    { Operation::MACRO, index }
#define MACRO_RECORD \
    { Operation::MACRO_RECORD, 0 }
#define MACRO_RECORD_LOOP \
    { Operation::MACRO_RECORD_LOOP, 0 }
#define MACRO_PLAY_RECORDED \
    { Operation::MACRO_PLAY_RECORDED, 0 }
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

#define PR_BTN_A \
    { Operation::PRESS, KeyCode::BTN_A }
#define PR_BTN_B \
    { Operation::PRESS, KeyCode::BTN_B }
#define PR_BTN_X \
    { Operation::PRESS, KeyCode::BTN_X }
#define PR_BTN_Y \
    { Operation::PRESS, KeyCode::BTN_Y }
#define PR_BTN_L \
    { Operation::PRESS, KeyCode::BTN_L }
#define PR_BTN_R \
    { Operation::PRESS, KeyCode::BTN_R }
#define PR_BTN_ZL \
    { Operation::PRESS, KeyCode::BTN_ZL }
#define PR_BTN_ZR \
    { Operation::PRESS, KeyCode::BTN_ZR }
#define PR_BTN_LCLICK \
    { Operation::PRESS, KeyCode::BTN_LCLICK }
#define PR_BTN_RCLICK \
    { Operation::PRESS, KeyCode::BTN_RCLICK }
#define PR_BTN_CAPTURE \
    { Operation::PRESS, KeyCode::BTN_CAPTURE }
#define PR_BTN_HOME \
    { Operation::PRESS, KeyCode::BTN_HOME }
#define PR_BTN_MINUS \
    { Operation::PRESS, KeyCode::BTN_MINUS }
#define PR_BTN_PLUS \
    { Operation::PRESS, KeyCode::BTN_PLUS }

#define PR_HAT_NEUTRAL \
    { Operation::PRESS, KeyCode::HAT_NEUTRAL }
#define PR_HAT_UP \
    { Operation::PRESS, KeyCode::HAT_UP }
#define PR_HAT_DOWN \
    { Operation::PRESS, KeyCode::HAT_DOWN }
#define PR_HAT_LEFT \
    { Operation::PRESS, KeyCode::HAT_LEFT }
#define PR_HAT_RIGHT \
    { Operation::PRESS, KeyCode::HAT_RIGHT }
#define PR_HAT_UP_LEFT \
    { Operation::PRESS, KeyCode::HAT_UP_LEFT }
#define PR_HAT_UP_RIGHT \
    { Operation::PRESS, KeyCode::HAT_UP_RIGHT }
#define PR_HAT_DOWN_LEFT \
    { Operation::PRESS, KeyCode::HAT_DOWN_LEFT }
#define PR_HAT_DOWN_RIGHT \
    { Operation::PRESS, KeyCode::HAT_DOWN_RIGHT }

#define PR_HAT_BTN_UP \
    { Operation::PRESS, KeyCode::HAT_BTN_UP }
#define PR_HAT_BTN_DOWN \
    { Operation::PRESS, KeyCode::HAT_BTN_DOWN }
#define PR_HAT_BTN_RIGHT \
    { Operation::PRESS, KeyCode::HAT_BTN_RIGHT }
#define PR_HAT_BTN_LEFT \
    { Operation::PRESS, KeyCode::HAT_BTN_LEFT }

#define PR_L_STICK_VALUE(x, y) (switch_controller::GenLeftStickKeyCode(x << sizeof(uint8_t) | y))

#define PR_L_STICK_UP \
    { Operation::PRESS, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define PR_L_STICK_DOWN \
    { Operation::PRESS, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define PR_L_STICK_LEFT \
    { Operation::PRESS, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define PR_L_STICK_RIGHT \
    { Operation::PRESS, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define PR_L_STICK_FREE(x, y) \
    { Operation::PRESS, STICK_VALUE(x, y) }

#define PR_R_STICK_VALUE(x, y) (switch_controller::GenRightStickKeyCode(x << sizeof(uint8_t) | y))

#define PR_R_STICK_UP \
    { Operation::PRESS, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define PR_R_STICK_DOWN \
    { Operation::PRESS, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define PR_R_STICK_LEFT \
    { Operation::PRESS, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define PR_R_STICK_RIGHT \
    { Operation::PRESS, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define PR_R_STICK_FREE(x, y) \
    { Operation::PRESS, STICK_VALUE(x, y) }

// ----------------------------------------------------------------------------

#define RE_BTN_A \
    { Operation::RELEASE, KeyCode::BTN_A }
#define RE_BTN_B \
    { Operation::RELEASE, KeyCode::BTN_B }
#define RE_BTN_X \
    { Operation::RELEASE, KeyCode::BTN_X }
#define RE_BTN_Y \
    { Operation::RELEASE, KeyCode::BTN_Y }
#define RE_BTN_L \
    { Operation::RELEASE, KeyCode::BTN_L }
#define RE_BTN_R \
    { Operation::RELEASE, KeyCode::BTN_R }
#define RE_BTN_ZL \
    { Operation::RELEASE, KeyCode::BTN_ZL }
#define RE_BTN_ZR \
    { Operation::RELEASE, KeyCode::BTN_ZR }
#define RE_BTN_LCLICK \
    { Operation::RELEASE, KeyCode::BTN_LCLICK }
#define RE_BTN_RCLICK \
    { Operation::RELEASE, KeyCode::BTN_RCLICK }
#define RE_BTN_CAPTURE \
    { Operation::RELEASE, KeyCode::BTN_CAPTURE }
#define RE_BTN_HOME \
    { Operation::RELEASE, KeyCode::BTN_HOME }
#define RE_BTN_MINUS \
    { Operation::RELEASE, KeyCode::BTN_MINUS }
#define RE_BTN_PLUS \
    { Operation::RELEASE, KeyCode::BTN_PLUS }

#define RE_HAT_NEUTRAL \
    { Operation::RELEASE, KeyCode::HAT_NEUTRAL }
#define RE_HAT_UP \
    { Operation::RELEASE, KeyCode::HAT_UP }
#define RE_HAT_DOWN \
    { Operation::RELEASE, KeyCode::HAT_DOWN }
#define RE_HAT_LEFT \
    { Operation::RELEASE, KeyCode::HAT_LEFT }
#define RE_HAT_RIGHT \
    { Operation::RELEASE, KeyCode::HAT_RIGHT }
#define RE_HAT_UP_LEFT \
    { Operation::RELEASE, KeyCode::HAT_UP_LEFT }
#define RE_HAT_UP_RIGHT \
    { Operation::RELEASE, KeyCode::HAT_UP_RIGHT }
#define RE_HAT_DOWN_LEFT \
    { Operation::RELEASE, KeyCode::HAT_DOWN_LEFT }
#define RE_HAT_DOWN_RIGHT \
    { Operation::RELEASE, KeyCode::HAT_DOWN_RIGHT }

#define RE_HAT_BTN_UP \
    { Operation::RELEASE, KeyCode::HAT_BTN_UP }
#define RE_HAT_BTN_DOWN \
    { Operation::RELEASE, KeyCode::HAT_BTN_DOWN }
#define RE_HAT_BTN_RIGHT \
    { Operation::RELEASE, KeyCode::HAT_BTN_RIGHT }
#define RE_HAT_BTN_LEFT \
    { Operation::RELEASE, KeyCode::HAT_BTN_LEFT }

#define RE_L_STICK_VALUE(x, y) (switch_controller::GenLeftStickKeyCode(x << sizeof(uint8_t) | y))

#define RE_L_STICK_UP \
    { Operation::RELEASE, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define RE_L_STICK_DOWN \
    { Operation::RELEASE, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define RE_L_STICK_LEFT \
    { Operation::RELEASE, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define RE_L_STICK_RIGHT \
    { Operation::RELEASE, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define RE_L_STICK_FREE(x, y) \
    { Operation::RELEASE, STICK_VALUE(x, y) }

#define RE_R_STICK_VALUE(x, y) (switch_controller::GenRightStickKeyCode(x << sizeof(uint8_t) | y))

#define RE_R_STICK_UP \
    { Operation::RELEASE, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define RE_R_STICK_DOWN \
    { Operation::RELEASE, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define RE_R_STICK_LEFT \
    { Operation::RELEASE, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define RE_R_STICK_RIGHT \
    { Operation::RELEASE, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define RE_R_STICK_FREE(x, y) \
    { Operation::RELEASE, STICK_VALUE(x, y) }

// ----------------------------------------------------------------------------

#define CL_BTN_A \
    { Operation::CLICK, KeyCode::BTN_A }
#define CL_BTN_B \
    { Operation::CLICK, KeyCode::BTN_B }
#define CL_BTN_X \
    { Operation::CLICK, KeyCode::BTN_X }
#define CL_BTN_Y \
    { Operation::CLICK, KeyCode::BTN_Y }
#define CL_BTN_L \
    { Operation::CLICK, KeyCode::BTN_L }
#define CL_BTN_R \
    { Operation::CLICK, KeyCode::BTN_R }
#define CL_BTN_ZL \
    { Operation::CLICK, KeyCode::BTN_ZL }
#define CL_BTN_ZR \
    { Operation::CLICK, KeyCode::BTN_ZR }
#define CL_BTN_LCLICK \
    { Operation::CLICK, KeyCode::BTN_LCLICK }
#define CL_BTN_RCLICK \
    { Operation::CLICK, KeyCode::BTN_RCLICK }
#define CL_BTN_CAPTURE \
    { Operation::CLICK, KeyCode::BTN_CAPTURE }
#define CL_BTN_HOME \
    { Operation::CLICK, KeyCode::BTN_HOME }
#define CL_BTN_MINUS \
    { Operation::CLICK, KeyCode::BTN_MINUS }
#define CL_BTN_PLUS \
    { Operation::CLICK, KeyCode::BTN_PLUS }

#define CL_HAT_NEUTRAL \
    { Operation::CLICK, KeyCode::HAT_NEUTRAL }
#define CL_HAT_UP \
    { Operation::CLICK, KeyCode::HAT_UP }
#define CL_HAT_DOWN \
    { Operation::CLICK, KeyCode::HAT_DOWN }
#define CL_HAT_LEFT \
    { Operation::CLICK, KeyCode::HAT_LEFT }
#define CL_HAT_RIGHT \
    { Operation::CLICK, KeyCode::HAT_RIGHT }
#define CL_HAT_UP_LEFT \
    { Operation::CLICK, KeyCode::HAT_UP_LEFT }
#define CL_HAT_UP_RIGHT \
    { Operation::CLICK, KeyCode::HAT_UP_RIGHT }
#define CL_HAT_DOWN_LEFT \
    { Operation::CLICK, KeyCode::HAT_DOWN_LEFT }
#define CL_HAT_DOWN_RIGHT \
    { Operation::CLICK, KeyCode::HAT_DOWN_RIGHT }

#define CL_HAT_BTN_UP \
    { Operation::CLICK, KeyCode::HAT_BTN_UP }
#define CL_HAT_BTN_DOWN \
    { Operation::CLICK, KeyCode::HAT_BTN_DOWN }
#define CL_HAT_BTN_RIGHT \
    { Operation::CLICK, KeyCode::HAT_BTN_RIGHT }
#define CL_HAT_BTN_LEFT \
    { Operation::CLICK, KeyCode::HAT_BTN_LEFT }

#define CL_L_STICK_VALUE(x, y) (switch_controller::GenLeftStickKeyCode(x << sizeof(uint8_t) | y))

#define CL_L_STICK_UP \
    { Operation::CLICK, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define CL_L_STICK_DOWN \
    { Operation::CLICK, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define CL_L_STICK_LEFT \
    { Operation::CLICK, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define CL_L_STICK_RIGHT \
    { Operation::CLICK, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define CL_L_STICK_CUSTOM(x, y) \
    { Operation::CLICK, STICK_VALUE(x, y) }

#define CL_R_STICK_VALUE(x, y) (switch_controller::GenRightStickKeyCode(x << sizeof(uint8_t) | y))

#define CL_R_STICK_UP \
    { Operation::CLICK, STICK_VALUE(Stick::NEUTRAL, Stick::MAX) }
#define CL_R_STICK_DOWN \
    { Operation::CLICK, STICK_VALUE(Stick::NEUTRAL, Stick::MIN) }
#define CL_R_STICK_LEFT \
    { Operation::CLICK, STICK_VALUE(Stick::MIN, Stick::NEUTRAL) }
#define CL_R_STICK_RIGHT \
    { Operation::CLICK, STICK_VALUE(Stick::MAX, Stick::NEUTRAL) }
#define CL_R_STICK_CUSTOM(x, y) \
    { Operation::CLICK, STICK_VALUE(x, y) }
