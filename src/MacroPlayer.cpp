#include "MacroPlayer.h"

keypad::MacroPlayer::MacroPlayer(
    const MacroRecord **macroList,
    unsigned long clickDelay, unsigned long clickEndDelay
) : macroList{macroList},
    clickDelay{clickDelay},
    clickEndDelay{clickEndDelay} {

    for (macroCnt = 0; macroList[macroCnt] != nullptr; ++macroCnt) {
    }
}

// ----------------------------------------------------------------------------

void keypad::MacroPlayer::Delay(unsigned long duration) {
    delay = duration;
    idleStartTime = millis();
    isIdle = true;
}

void keypad::MacroPlayer::ClickDelay() {
    Delay(clickDelay);
}

void keypad::MacroPlayer::ClickEndDelay() {
    Delay(clickEndDelay);
}

bool keypad::MacroPlayer::CheckIsIdle() {
    if (!isIdle) {
        return false;
    }

    unsigned long now = millis();
    if (now < idleStartTime) {
        isIdle = delay > (ULONG_MAX - idleStartTime + now);
    } else {
        isIdle = delay > now - idleStartTime;
    }

    return isIdle;
}

bool keypad::MacroPlayer::CheckNeedClick() {
    return isNeedClick;
}

// -----------------------------------------------------------------------------

const keypad::MacroRecord *keypad::MacroPlayer::GetMacro() {
    return macro;
}

bool keypad::MacroPlayer::CheckIsMacroPlaying() {
    return isAllowedToPlay && CheckHasMacroBinded();
}

void keypad::MacroPlayer::Unbind() {
    macro = nullptr;
    curPlaying = nullptr;
}

void keypad::MacroPlayer::ToggleIndex(int index, int r, int c) {
    row = r;
    col = c;
    macro = !CheckHasMacroBinded() && index < macroCnt
                ? macroList[index]
                : nullptr;
    curPlaying = nullptr;
}

void keypad::MacroPlayer::ToggleMacro(const MacroRecord *macro, int r, int c) {
    row = r;
    col = c;
    macro = !CheckHasMacroBinded() ? macro : nullptr;
    curPlaying = nullptr;
}

const keypad::MacroRecord *keypad::MacroPlayer::Next() {
    if (curPlaying == nullptr || curPlaying->type == Operation::END) {
        curPlaying = macro;
    } else if (isNeedClick) {
        isNeedClick = false;
    } else {
        ++curPlaying;

        if (curPlaying->type == Operation::CLICK) {
            isNeedClick = true;
        }
    }

    return curPlaying;
}

// -----------------------------------------------------------------------------

bool keypad::MacroPlayer::CheckHasMacroBinded() {
    return macro != nullptr;
}
