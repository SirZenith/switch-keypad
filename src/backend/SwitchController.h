#pragma once

#include <SwitchController.h>

#include "../KeyHandler.h"

namespace backend {
    class SwitchController : keypad::KeyHandler {
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