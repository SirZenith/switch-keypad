#pragma once

#include "common.h"

namespace keypad {
    class MacroPlayer {
    public:
        bool isPlaying = false;
        // when macro is triggered, coordinate of trigger key will be recorded.
        int row = 0, col = 0;

        MacroPlayer(
            const MacroRecord **macroList,
            unsigned long clickDelay, unsigned long clickEndDelay
        );

        void Delay(unsigned long);
        void ClickDelay();
        void ClickEndDelay();
        bool CheckIsIdle();

        bool CheckNeedClick();

        const MacroRecord *GetMacro();
        bool CheckIsMacroPlaying();
        void Unbind();
        void ToggleIndex(int index, int r, int c);
        void ToggleMacro(const MacroRecord *macro, int r, int c);

        const MacroRecord *Next();
    private:
        const MacroRecord **macroList = nullptr;
        const MacroRecord *macro = nullptr;
        const MacroRecord *curPlaying = nullptr;

        unsigned long clickDelay = 0;
        unsigned long clickEndDelay = 0;

        bool isIdle = false;
        unsigned long delay = 0;
        unsigned long idleStartTime = 0;

        bool isNeedClick = false;

        bool CheckHasMacroBinded();
    };
}