#pragma once

#include <TinyUSB_Mouse_and_Keyboard.h>

#include "../common.h"

using keypad::Operation;

// -----------------------------------------------------------------------------

#define PR_KEY_LEFT_CTRL \
    { Operation::PRESS, KEY_LEFT_CTRL }
#define PR_KEY_LEFT_SHIFT \
    { Operation::PRESS, KEY_LEFT_SHIFT }
#define PR_KEY_LEFT_ALT \
    { Operation::PRESS, KEY_LEFT_ALT }
#define PR_KEY_LEFT_GUI \
    { Operation::PRESS, KEY_LEFT_GUI }
#define PR_KEY_RIGHT_CTRL \
    { Operation::PRESS, KEY_RIGHT_CTRL }
#define PR_KEY_RIGHT_SHIFT \
    { Operation::PRESS, KEY_RIGHT_SHIFT }
#define PR_KEY_RIGHT_ALT \
    { Operation::PRESS, KEY_RIGHT_ALT }
#define PR_KEY_RIGHT_GUI \
    { Operation::PRESS, KEY_RIGHT_GUI }

#define PR_KEY_UP_ARROW \
    { Operation::PRESS, KEY_UP_ARROW }
#define PR_KEY_DOWN_ARROW \
    { Operation::PRESS, KEY_DOWN_ARROW }
#define PR_KEY_LEFT_ARROW \
    { Operation::PRESS, KEY_LEFT_ARROW }
#define PR_KEY_RIGHT_ARROW \
    { Operation::PRESS, KEY_RIGHT_ARROW }
#define PR_KEY_BACKSPACE \
    { Operation::PRESS, KEY_BACKSPACE }
#define PR_KEY_TAB \
    { Operation::PRESS, KEY_TAB }
#define PR_KEY_RETURN \
    { Operation::PRESS, KEY_RETURN }
#define PR_KEY_ESC \
    { Operation::PRESS, KEY_ESC }
#define PR_KEY_INSERT \
    { Operation::PRESS, KEY_INSERT }
#define PR_KEY_DELETE \
    { Operation::PRESS, KEY_DELETE }
#define PR_KEY_PAGE_UP \
    { Operation::PRESS, KEY_PAGE_UP }
#define PR_KEY_PAGE_DOWN \
    { Operation::PRESS, KEY_PAGE_DOWN }
#define PR_KEY_HOME \
    { Operation::PRESS, KEY_HOME }
#define PR_KEY_END \
    { Operation::PRESS, KEY_END }
#define PR_KEY_CAPS_LOCK \
    { Operation::PRESS, KEY_CAPS_LOCK }
#define PR_KEY_F1 \
    { Operation::PRESS, KEY_F1 }
#define PR_KEY_F2 \
    { Operation::PRESS, KEY_F2 }
#define PR_KEY_F3 \
    { Operation::PRESS, KEY_F3 }
#define PR_KEY_F4 \
    { Operation::PRESS, KEY_F4 }
#define PR_KEY_F5 \
    { Operation::PRESS, KEY_F5 }
#define PR_KEY_F6 \
    { Operation::PRESS, KEY_F6 }
#define PR_KEY_F7 \
    { Operation::PRESS, KEY_F7 }
#define PR_KEY_F8 \
    { Operation::PRESS, KEY_F8 }
#define PR_KEY_F9 \
    { Operation::PRESS, KEY_F9 }
#define PR_KEY_F10 \
    { Operation::PRESS, KEY_F10 }
#define PR_KEY_F11 \
    { Operation::PRESS, KEY_F11 }
#define PR_KEY_F12 \
    { Operation::PRESS, KEY_F12 }
#define PR_KEY_F13 \
    { Operation::PRESS, KEY_F13 }
#define PR_KEY_F14 \
    { Operation::PRESS, KEY_F14 }
#define PR_KEY_F15 \
    { Operation::PRESS, KEY_F15 }
#define PR_KEY_F16 \
    { Operation::PRESS, KEY_F16 }
#define PR_KEY_F17 \
    { Operation::PRESS, KEY_F17 }
#define PR_KEY_F18 \
    { Operation::PRESS, KEY_F18 }
#define PR_KEY_F19 \
    { Operation::PRESS, KEY_F19 }
#define PR_KEY_F20 \
    { Operation::PRESS, KEY_F20 }
#define PR_KEY_F21 \
    { Operation::PRESS, KEY_F21 }
#define PR_KEY_F22 \
    { Operation::PRESS, KEY_F22 }
#define PR_KEY_F23 \
    { Operation::PRESS, KEY_F23 }
#define PR_KEY_F24 \
    { Operation::PRESS, KEY_F2 }

// -----------------------------------------------------------------------------

#define RE_KEY_LEFT_CTRL \
    { Operation::RELEASE, KEY_LEFT_CTRL }
#define RE_KEY_LEFT_SHIFT \
    { Operation::RELEASE, KEY_LEFT_SHIFT }
#define RE_KEY_LEFT_ALT \
    { Operation::RELEASE, KEY_LEFT_ALT }
#define RE_KEY_LEFT_GUI \
    { Operation::RELEASE, KEY_LEFT_GUI }
#define RE_KEY_RIGHT_CTRL \
    { Operation::RELEASE, KEY_RIGHT_CTRL }
#define RE_KEY_RIGHT_SHIFT \
    { Operation::RELEASE, KEY_RIGHT_SHIFT }
#define RE_KEY_RIGHT_ALT \
    { Operation::RELEASE, KEY_RIGHT_ALT }
#define RE_KEY_RIGHT_GUI \
    { Operation::RELEASE, KEY_RIGHT_GUI }

#define RE_KEY_UP_ARROW \
    { Operation::RELEASE, KEY_UP_ARROW }
#define RE_KEY_DOWN_ARROW \
    { Operation::RELEASE, KEY_DOWN_ARROW }
#define RE_KEY_LEFT_ARROW \
    { Operation::RELEASE, KEY_LEFT_ARROW }
#define RE_KEY_RIGHT_ARROW \
    { Operation::RELEASE, KEY_RIGHT_ARROW }
#define RE_KEY_BACKSPACE \
    { Operation::RELEASE, KEY_BACKSPACE }
#define RE_KEY_TAB \
    { Operation::RELEASE, KEY_TAB }
#define RE_KEY_RETURN \
    { Operation::RELEASE, KEY_RETURN }
#define RE_KEY_ESC \
    { Operation::RELEASE, KEY_ESC }
#define RE_KEY_INSERT \
    { Operation::RELEASE, KEY_INSERT }
#define RE_KEY_DELETE \
    { Operation::RELEASE, KEY_DELETE }
#define RE_KEY_PAGE_UP \
    { Operation::RELEASE, KEY_PAGE_UP }
#define RE_KEY_PAGE_DOWN \
    { Operation::RELEASE, KEY_PAGE_DOWN }
#define RE_KEY_HOME \
    { Operation::RELEASE, KEY_HOME }
#define RE_KEY_END \
    { Operation::RELEASE, KEY_END }
#define RE_KEY_CAPS_LOCK \
    { Operation::RELEASE, KEY_CAPS_LOCK }
#define RE_KEY_F1 \
    { Operation::RELEASE, KEY_F1 }
#define RE_KEY_F2 \
    { Operation::RELEASE, KEY_F2 }
#define RE_KEY_F3 \
    { Operation::RELEASE, KEY_F3 }
#define RE_KEY_F4 \
    { Operation::RELEASE, KEY_F4 }
#define RE_KEY_F5 \
    { Operation::RELEASE, KEY_F5 }
#define RE_KEY_F6 \
    { Operation::RELEASE, KEY_F6 }
#define RE_KEY_F7 \
    { Operation::RELEASE, KEY_F7 }
#define RE_KEY_F8 \
    { Operation::RELEASE, KEY_F8 }
#define RE_KEY_F9 \
    { Operation::RELEASE, KEY_F9 }
#define RE_KEY_F10 \
    { Operation::RELEASE, KEY_F10 }
#define RE_KEY_F11 \
    { Operation::RELEASE, KEY_F11 }
#define RE_KEY_F12 \
    { Operation::RELEASE, KEY_F12 }
#define RE_KEY_F13 \
    { Operation::RELEASE, KEY_F13 }
#define RE_KEY_F14 \
    { Operation::RELEASE, KEY_F14 }
#define RE_KEY_F15 \
    { Operation::RELEASE, KEY_F15 }
#define RE_KEY_F16 \
    { Operation::RELEASE, KEY_F16 }
#define RE_KEY_F17 \
    { Operation::RELEASE, KEY_F17 }
#define RE_KEY_F18 \
    { Operation::RELEASE, KEY_F18 }
#define RE_KEY_F19 \
    { Operation::RELEASE, KEY_F19 }
#define RE_KEY_F20 \
    { Operation::RELEASE, KEY_F20 }
#define RE_KEY_F21 \
    { Operation::RELEASE, KEY_F21 }
#define RE_KEY_F22 \
    { Operation::RELEASE, KEY_F22 }
#define RE_KEY_F23 \
    { Operation::RELEASE, KEY_F23 }
#define RE_KEY_F24 \
    { Operation::RELEASE, KEY_F2 }

// -----------------------------------------------------------------------------

#define CL_KEY_LEFT_CTRL \
    { Operation::CLICK, KEY_LEFT_CTRL }
#define CL_KEY_LEFT_SHIFT \
    { Operation::CLICK, KEY_LEFT_SHIFT }
#define CL_KEY_LEFT_ALT \
    { Operation::CLICK, KEY_LEFT_ALT }
#define CL_KEY_LEFT_GUI \
    { Operation::CLICK, KEY_LEFT_GUI }
#define CL_KEY_RIGHT_CTRL \
    { Operation::CLICK, KEY_RIGHT_CTRL }
#define CL_KEY_RIGHT_SHIFT \
    { Operation::CLICK, KEY_RIGHT_SHIFT }
#define CL_KEY_RIGHT_ALT \
    { Operation::CLICK, KEY_RIGHT_ALT }
#define CL_KEY_RIGHT_GUI \
    { Operation::CLICK, KEY_RIGHT_GUI }

#define CL_KEY_UP_ARROW \
    { Operation::CLICK, KEY_UP_ARROW }
#define CL_KEY_DOWN_ARROW \
    { Operation::CLICK, KEY_DOWN_ARROW }
#define CL_KEY_LEFT_ARROW \
    { Operation::CLICK, KEY_LEFT_ARROW }
#define CL_KEY_RIGHT_ARROW \
    { Operation::CLICK, KEY_RIGHT_ARROW }
#define CL_KEY_BACKSPACE \
    { Operation::CLICK, KEY_BACKSPACE }
#define CL_KEY_TAB \
    { Operation::CLICK, KEY_TAB }
#define CL_KEY_RETURN \
    { Operation::CLICK, KEY_RETURN }
#define CL_KEY_ESC \
    { Operation::CLICK, KEY_ESC }
#define CL_KEY_INSERT \
    { Operation::CLICK, KEY_INSERT }
#define CL_KEY_DELETE \
    { Operation::CLICK, KEY_DELETE }
#define CL_KEY_PAGE_UP \
    { Operation::CLICK, KEY_PAGE_UP }
#define CL_KEY_PAGE_DOWN \
    { Operation::CLICK, KEY_PAGE_DOWN }
#define CL_KEY_HOME \
    { Operation::CLICK, KEY_HOME }
#define CL_KEY_END \
    { Operation::CLICK, KEY_END }
#define CL_KEY_CAPS_LOCK \
    { Operation::CLICK, KEY_CAPS_LOCK }
#define CL_KEY_F1 \
    { Operation::CLICK, KEY_F1 }
#define CL_KEY_F2 \
    { Operation::CLICK, KEY_F2 }
#define CL_KEY_F3 \
    { Operation::CLICK, KEY_F3 }
#define CL_KEY_F4 \
    { Operation::CLICK, KEY_F4 }
#define CL_KEY_F5 \
    { Operation::CLICK, KEY_F5 }
#define CL_KEY_F6 \
    { Operation::CLICK, KEY_F6 }
#define CL_KEY_F7 \
    { Operation::CLICK, KEY_F7 }
#define CL_KEY_F8 \
    { Operation::CLICK, KEY_F8 }
#define CL_KEY_F9 \
    { Operation::CLICK, KEY_F9 }
#define CL_KEY_F10 \
    { Operation::CLICK, KEY_F10 }
#define CL_KEY_F11 \
    { Operation::CLICK, KEY_F11 }
#define CL_KEY_F12 \
    { Operation::CLICK, KEY_F12 }
#define CL_KEY_F13 \
    { Operation::CLICK, KEY_F13 }
#define CL_KEY_F14 \
    { Operation::CLICK, KEY_F14 }
#define CL_KEY_F15 \
    { Operation::CLICK, KEY_F15 }
#define CL_KEY_F16 \
    { Operation::CLICK, KEY_F16 }
#define CL_KEY_F17 \
    { Operation::CLICK, KEY_F17 }
#define CL_KEY_F18 \
    { Operation::CLICK, KEY_F18 }
#define CL_KEY_F19 \
    { Operation::CLICK, KEY_F19 }
#define CL_KEY_F20 \
    { Operation::CLICK, KEY_F20 }
#define CL_KEY_F21 \
    { Operation::CLICK, KEY_F21 }
#define CL_KEY_F22 \
    { Operation::CLICK, KEY_F22 }
#define CL_KEY_F23 \
    { Operation::CLICK, KEY_F23 }
#define CL_KEY_F24 \
    { Operation::CLICK, KEY_F2 }
