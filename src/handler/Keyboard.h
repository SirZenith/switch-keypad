#pragma once

#include <TinyUSB_Mouse_and_Keyboard.h>

#include "../KeyHandler.h"

namespace handler {
    class Keyboard : keypad::KeyHandler {
    public:
        Keyboard(
            const keypad::Record **keyMap,
            const keypad::MacroRecord **macroList,
            unsigned int defaultLayer
        );

        void Begin();
        void End();

        bool Ready();
        bool Dirty();

        void Send();

        void Press(unsigned long param);
        void Release(unsigned long param);
        void ReleaseAll();

        const char *Name();
        void OperationLog(const char *msg, const keypad::MacroRecord *re);
    private:
        bool isDirty = false;
    };
}