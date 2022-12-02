#include "common.h"

const char *keypad::GetOperatioinName(Operation type) {
    const char *name = nullptr;

    switch (type) {
    case EMPTY:
        name = "empty";
        break;
    case DELAY:
        name = "delay";
        break;
    case END:
        name = "end";
        break;
    case MACRO:
        name = "macro";
        break;
    
    case MOMENT_LAYER:
        name = "goto-layer";
        break;
    case ONE_SHOT_LAYER:
        name = "one-shot-layer";
        break;
    case TOGGLE_LAYER:
        name = "toggle-layer";
        break;
    case DEFAULT_LAYER:
        name = "default-layer";
        break;
    
    case BTN:
        name = "btn";
        break;
    case HAT:
        name = "hat";
        break;
    case HAT_BTN:
        name = "hat-btn";
        break;
    case L_STICK:
        name = "stick-L";
        break;
    case R_STICK:
        name = "stick-R";
        break;

    default:
        name = "unknown";
        break;
    }

    return name;
}