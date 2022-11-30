#include <SwitchControlLibrary.h>

namespace config {
    enum Operation {
        EMPTY,
        DELAY,
        KEY,
        HAT,
        MACRO,
        END,
    };

    struct Record {
        Operation type;
        int param;
    };

    const int row = 2;
    const int col = 3;
    const int layer = 3;
    int rowPinList[] = {1, 0};
    int colPinList[] = {2, 3, 4};

    Record *keyMap[6] = {
        (Record[]){
            {Operation::KEY, Button::A},
            {Operation::HAT, HatButton::UP},
            {Operation::MACRO, 0},
            // -------------------------
            {Operation::KEY, Button::B},
            {Operation::HAT, HatButton::DOWN},
            {Operation::MACRO, 1},
        },
    };

    const int CLICK_DELAY = 80;
    const int CHANGE_KEY_DELAY = 80;
    const int SMALL_DIALOG_DELAY = 250;
    const int MEDIUM_DIALOG_DELAY = 500;
    const int LARGE_DIALOG_DELAY = 800;
    const int MENU_LOAD_DELAY = 2800;

    Record *macroList[] = {
        (Record[]){
            {Operation::KEY, Button::A},
            {Operation::DELAY, SMALL_DIALOG_DELAY},

            {Operation::HAT, HatButton::DOWN},
            {Operation::HAT, HatButton::DOWN},
            {Operation::HAT, HatButton::DOWN},
            {Operation::HAT, HatButton::DOWN},
            {Operation::HAT, HatButton::DOWN},
            {Operation::KEY, Button::A},
            {Operation::DELAY, LARGE_DIALOG_DELAY},

            {Operation::KEY, Button::A},
            {Operation::KEY, Button::A},
            {Operation::DELAY, MENU_LOAD_DELAY},

            {Operation::KEY, Button::A},
            {Operation::HAT, HatButton::UP},
            {Operation::HAT, HatButton::RIGHT},
            {Operation::HAT, HatButton::DOWN},
            {Operation::HAT, HatButton::DOWN},
            {Operation::KEY, Button::A},

            {Operation::DELAY, MENU_LOAD_DELAY},

            {Operation::KEY, Button::X},
            {Operation::KEY, Button::X},
            {Operation::KEY, Button::L},

            {Operation::KEY, Button::A},

            {Operation::DELAY, SMALL_DIALOG_DELAY},

            {Operation::HAT, HatButton::DOWN},
            {Operation::HAT, HatButton::DOWN},
            {Operation::HAT, HatButton::DOWN},
            {Operation::KEY, Button::A},

            {Operation::DELAY, MEDIUM_DIALOG_DELAY},

            {Operation::KEY, Button::B},

            {Operation::DELAY, MENU_LOAD_DELAY},

            {Operation::HAT, HatButton::UP},
            {Operation::HAT, HatButton::LEFT},
            {Operation::HAT, HatButton::UP},
            {Operation::HAT, HatButton::UP},

            {Operation::END, 1},
        },
        (Record[]){
            {Operation::KEY, Button::A},
            {Operation::KEY, Button::B},
            {Operation::END, 0},
        }
    };
};