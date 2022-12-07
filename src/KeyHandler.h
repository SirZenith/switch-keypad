#pragma once

#include "common.h"

namespace keypad {
    class KeyHandler {
    public:
        virtual void Begin() = 0;
        virtual void End() = 0;

        virtual bool Ready() = 0;
        virtual bool Dirty() = 0;

        virtual void Send() = 0;

        virtual void Press(unsigned long param) = 0;
        virtual void Release(unsigned long param) = 0;
    };
}
