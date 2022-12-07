#pragma once

// #include "Keyboard.h"

#include "../KeyHandler.h"

namespace backend {
    class Keyboard : keypad::KeyHandler {
    public:
        void Begin();
        void End();

        bool Ready();
        bool Dirty();

        void Send();

        void Press(unsigned long param);
        void Release(unsigned long param);

    private:
        bool isDirty = false;
    };
}