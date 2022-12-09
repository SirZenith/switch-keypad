#pragma once

#include <SwitchController.h>

#include "../KeyHandler.h"

namespace handler {
    class SwitchController : keypad::KeyHandler {
    public:
        SwitchController(
            const keypad::Record **keyMap,
            const keypad::MacroRecord **macroList,
            unsigned int defaultLayer
        );

        void Begin();
        void End();

        bool Ready();
        bool Dirty();
        // unsigned int 

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
