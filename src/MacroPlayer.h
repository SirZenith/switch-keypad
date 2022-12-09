#pragma once

#include "common.h"

namespace keypad {
    class MacroPlayer {
    public:
        bool isAllowedToPlay = false;
        // when macro is triggered, coordinate of trigger key will be recorded.
        int row = 0, col = 0;

        MacroPlayer(unsigned long clickDelay, unsigned long clickEndDelay);

        void Delay(unsigned long);
        void ClickDelay();
        void ClickEndDelay();
        bool CheckIsIdle();

        bool CheckNeedClick();

        const MacroRecord *GetMacro();
        bool CheckIsMacroPlaying();
        void Unbind();
        void ToggleIndex(int index, int r, int c);
        void ToggleMacro(const MacroRecord *m, int r, int c);

        const MacroRecord *Next();

    private:
        const MacroRecord *macro = nullptr;
        const MacroRecord *curPlaying = nullptr;

        int macroCnt = 0;

        unsigned long clickDelay = 0;
        unsigned long clickEndDelay = 0;

        bool isIdle = false;
        unsigned long delay = 0;
        unsigned long idleStartTime = 0;

        bool isNeedClick = false;

        bool CheckHasMacroBinded();
    };
}