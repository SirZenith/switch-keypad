# pragma once

#include <SwitchController.h>

#include "../common.h"

// -----------------------------------------------------------------------------

#define PR_BTN_A \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_A }
#define PR_BTN_B \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_B }
#define PR_BTN_X \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_X }
#define PR_BTN_Y \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_Y }
#define PR_BTN_L \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_L }
#define PR_BTN_R \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_R }
#define PR_BTN_ZL \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_ZL }
#define PR_BTN_ZR \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_ZR }
#define PR_BTN_LCLICK \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_LCLICK }
#define PR_BTN_RCLICK \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_RCLICK }
#define PR_BTN_CAPTURE \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_CAPTURE }
#define PR_BTN_HOME \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_HOME }
#define PR_BTN_MINUS \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_MINUS }
#define PR_BTN_PLUS \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::BTN_PLUS }

#define PR_CROSS_NEUTRAL \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_NEUTRAL }
#define PR_CROSS_UP \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_UP }
#define PR_CROSS_DOWN \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN }
#define PR_CROSS_LEFT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_LEFT }
#define PR_CROSS_RIGHT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_RIGHT }
#define PR_CROSS_UP_LEFT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_UP_LEFT }
#define PR_CROSS_UP_RIGHT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_UP_RIGHT }
#define PR_CROSS_DOWN_LEFT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN_LEFT }
#define PR_CROSS_DOWN_RIGHT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN_RIGHT }

#define PR_CROSS_BTN_UP \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_UP }
#define PR_CROSS_BTN_DOWN \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_DOWN }
#define PR_CROSS_BTN_RIGHT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_RIGHT }
#define PR_CROSS_BTN_LEFT \
    { Operation::PRESS, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_LEFT }

#define PR_L_STICK_VALUE(x, y) (switch_controller::GenLeftStickKeyCode(x, y))

#define PR_L_STICK_UP \
    { Operation::PRESS, PR_L_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MAX) }
#define PR_L_STICK_DOWN \
    { Operation::PRESS, PR_L_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MIN) }
#define PR_L_STICK_LEFT \
    { Operation::PRESS, PR_L_STICK_VALUE(::switch_controller::Stick::MIN, ::switch_controller::Stick::NEUTRAL) }
#define PR_L_STICK_RIGHT \
    { Operation::PRESS, PR_L_STICK_VALUE(::switch_controller::Stick::MAX, ::switch_controller::Stick::NEUTRAL) }
#define PR_L_STICK_FREE(x, y) \
    { Operation::PRESS, PR_L_STICK_VALUE(x, y) }

#define PR_R_STICK_VALUE(x, y) (switch_controller::GenRightStickKeyCode(x, y))

#define PR_R_STICK_UP \
    { Operation::PRESS, PR_R_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MAX) }
#define PR_R_STICK_DOWN \
    { Operation::PRESS, PR_R_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MIN) }
#define PR_R_STICK_LEFT \
    { Operation::PRESS, PR_R_STICK_VALUE(::switch_controller::Stick::MIN, ::switch_controller::Stick::NEUTRAL) }
#define PR_R_STICK_RIGHT \
    { Operation::PRESS, PR_R_STICK_VALUE(::switch_controller::Stick::MAX, ::switch_controller::Stick::NEUTRAL) }
#define PR_R_STICK_FREE(x, y) \
    { Operation::PRESS, PR_R_STICK_VALUE(x, y) }

// -----------------------------------------------------------------------------

#define RE_BTN_A \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_A }
#define RE_BTN_B \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_B }
#define RE_BTN_X \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_X }
#define RE_BTN_Y \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_Y }
#define RE_BTN_L \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_L }
#define RE_BTN_R \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_R }
#define RE_BTN_ZL \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_ZL }
#define RE_BTN_ZR \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_ZR }
#define RE_BTN_LCLICK \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_LCLICK }
#define RE_BTN_RCLICK \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_RCLICK }
#define RE_BTN_CAPTURE \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_CAPTURE }
#define RE_BTN_HOME \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_HOME }
#define RE_BTN_MINUS \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_MINUS }
#define RE_BTN_PLUS \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::BTN_PLUS }

#define RE_CROSS_NEUTRAL \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_NEUTRAL }
#define RE_CROSS_UP \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_UP }
#define RE_CROSS_DOWN \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN }
#define RE_CROSS_LEFT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_LEFT }
#define RE_CROSS_RIGHT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_RIGHT }
#define RE_CROSS_UP_LEFT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_UP_LEFT }
#define RE_CROSS_UP_RIGHT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_UP_RIGHT }
#define RE_CROSS_DOWN_LEFT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN_LEFT }
#define RE_CROSS_DOWN_RIGHT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN_RIGHT }

#define RE_CROSS_BTN_UP \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_UP }
#define RE_CROSS_BTN_DOWN \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_DOWN }
#define RE_CROSS_BTN_RIGHT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_RIGHT }
#define RE_CROSS_BTN_LEFT \
    { Operation::RELEASE, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_LEFT }

#define RE_L_STICK_VALUE(x, y) (switch_controller::GenLeftStickKeyCode(x, y))

#define RE_L_STICK_UP \
    { Operation::RELEASE, RE_L_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MAX) }
#define RE_L_STICK_DOWN \
    { Operation::RELEASE, RE_L_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MIN) }
#define RE_L_STICK_LEFT \
    { Operation::RELEASE, RE_L_STICK_VALUE(::switch_controller::Stick::MIN, ::switch_controller::Stick::NEUTRAL) }
#define RE_L_STICK_RIGHT \
    { Operation::RELEASE, RE_L_STICK_VALUE(::switch_controller::Stick::MAX, ::switch_controller::Stick::NEUTRAL) }
#define RE_L_STICK_FREE(x, y) \
    { Operation::RELEASE, RE_L_STICK_VALUE(x, y) }

#define RE_R_STICK_VALUE(x, y) (switch_controller::GenRightStickKeyCode(x, y))

#define RE_R_STICK_UP \
    { Operation::RELEASE, RE_R_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MAX) }
#define RE_R_STICK_DOWN \
    { Operation::RELEASE, RE_R_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MIN) }
#define RE_R_STICK_LEFT \
    { Operation::RELEASE, RE_R_STICK_VALUE(::switch_controller::Stick::MIN, ::switch_controller::Stick::NEUTRAL) }
#define RE_R_STICK_RIGHT \
    { Operation::RELEASE, RE_R_STICK_VALUE(::switch_controller::Stick::MAX, ::switch_controller::Stick::NEUTRAL) }
#define RE_R_STICK_FREE(x, y) \
    { Operation::RELEASE, RE_R_STICK_VALUE(x, y) }

// -----------------------------------------------------------------------------

#define CL_BTN_A \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_A }
#define CL_BTN_B \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_B }
#define CL_BTN_X \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_X }
#define CL_BTN_Y \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_Y }
#define CL_BTN_L \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_L }
#define CL_BTN_R \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_R }
#define CL_BTN_ZL \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_ZL }
#define CL_BTN_ZR \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_ZR }
#define CL_BTN_LCLICK \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_LCLICK }
#define CL_BTN_RCLICK \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_RCLICK }
#define CL_BTN_CAPTURE \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_CAPTURE }
#define CL_BTN_HOME \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_HOME }
#define CL_BTN_MINUS \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_MINUS }
#define CL_BTN_PLUS \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::BTN_PLUS }

#define CL_CROSS_NEUTRAL \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_NEUTRAL }
#define CL_CROSS_UP \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_UP }
#define CL_CROSS_DOWN \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN }
#define CL_CROSS_LEFT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_LEFT }
#define CL_CROSS_RIGHT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_RIGHT }
#define CL_CROSS_UP_LEFT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_UP_LEFT }
#define CL_CROSS_UP_RIGHT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_UP_RIGHT }
#define CL_CROSS_DOWN_LEFT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN_LEFT }
#define CL_CROSS_DOWN_RIGHT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_DOWN_RIGHT }

#define CL_CROSS_BTN_UP \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_UP }
#define CL_CROSS_BTN_DOWN \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_DOWN }
#define CL_CROSS_BTN_RIGHT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_RIGHT }
#define CL_CROSS_BTN_LEFT \
    { Operation::CLICK, (unsigned long)::switch_controller::KeyCode::CROSS_BTN_LEFT }

#define CL_L_STICK_VALUE(x, y) (switch_controller::GenLeftStickKeyCode(x, y))

#define CL_L_STICK_UP \
    { Operation::CLICK, CL_L_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MAX) }
#define CL_L_STICK_DOWN \
    { Operation::CLICK, CL_L_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MIN) }
#define CL_L_STICK_LEFT \
    { Operation::CLICK, CL_L_STICK_VALUE(::switch_controller::Stick::MIN, ::switch_controller::Stick::NEUTRAL) }
#define CL_L_STICK_RIGHT \
    { Operation::CLICK, CL_L_STICK_VALUE(::switch_controller::Stick::MAX, ::switch_controller::Stick::NEUTRAL) }
#define CL_L_STICK_CUSTOM(x, y) \
    { Operation::CLICK, CL_L_STICK_VALUE(x, y) }

#define CL_R_STICK_VALUE(x, y) (switch_controller::GenRightStickKeyCode(x, y))

#define CL_R_STICK_UP \
    { Operation::CLICK, CL_R_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MAX) }
#define CL_R_STICK_DOWN \
    { Operation::CLICK, CL_R_STICK_VALUE(::switch_controller::Stick::NEUTRAL, ::switch_controller::Stick::MIN) }
#define CL_R_STICK_LEFT \
    { Operation::CLICK, CL_R_STICK_VALUE(::switch_controller::Stick::MIN, ::switch_controller::Stick::NEUTRAL) }
#define CL_R_STICK_RIGHT \
    { Operation::CLICK, CL_R_STICK_VALUE(::switch_controller::Stick::MAX, ::switch_controller::Stick::NEUTRAL) }
#define CL_R_STICK_CUSTOM(x, y) \
    { Operation::CLICK, CL_R_STICK_VALUE(x, y) }
