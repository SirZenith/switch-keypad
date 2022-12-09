#include "MacroPlayer.h"

keypad::MacroPlayer::MacroPlayer(unsigned long clickDelay, unsigned long clickEndDelay)
    : clickDelay{clickDelay},
      clickEndDelay{clickEndDelay} {}

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

void keypad::MacroPlayer::ToggleMacro(const MacroRecord *m, int r, int c) {
    row = r;
    col = c;
    macro = !CheckHasMacroBinded() ? m : nullptr;
    curPlaying = nullptr;

    if (macro != nullptr) {
        int cnt = 0;
        for (; m[cnt].type != Operation::END; ++cnt) {
        }
        Serial.print("record length: ");
        Serial.print(cnt);
        Serial.print("\n");
    }
}

const keypad::MacroRecord *keypad::MacroPlayer::Next() {
    if (isNeedClick) {
        isNeedClick = false;
        return curPlaying;
    }

    if (curPlaying == nullptr || curPlaying->type == Operation::END) {
        curPlaying = macro;
    } else {
        ++curPlaying;
    }

    if (curPlaying->type == Operation::CLICK) {
        isNeedClick = true;
    }

    return curPlaying;
}

// -----------------------------------------------------------------------------

bool keypad::MacroPlayer::CheckHasMacroBinded() {
    return macro != nullptr;
}
