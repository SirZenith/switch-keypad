#include "KeyPad.h"

using namespace keypad;

KeyPad::KeyPad(
    int row, int col, int layer,
    int *rowPinList, int *colPinList,
    Record **keyMap, Record **macroList,
    int debounce, int holdThreshold,
    int clickDelay, int changeKeyDelay
) : row{row},
    col{col},
    layer{layer},
    rowPinList{rowPinList},
    colPinList{colPinList},
    keyMap{keyMap},
    macroList{macroList},
    debounce{debounce},
    holdThreshold{holdThreshold},
    clickDelay{clickDelay},
    keyEndDelay{keyEndDelay} {

    keyMatrix = new Key *[row];
    for (int r = 0; r < row; ++r) {
        keyMatrix[r] = new Key[col];
    }
}

KeyPad::~KeyPad() {
    for (int r = 0; r < row; ++r) {
        delete[] keyMatrix[r];
    }
    delete[] keyMatrix;
}

// ----------------------------------------------------------------------------

void KeyPad::Scan() {
    if (isScanning) {
        return;
    }

    isScanning = true;

    for (int r = 0; r < row; ++r) {
        digitalWrite(rowPinList[r], LOW);

        for (int c = 0; c < col; ++c) {
            int now = millis();
            Key k = keyMatrix[r][c];

            if (now - k.updatetime < debounce) {
                // pass
            } else if (CheckIsActive(c)) {
                OnKeyActive(r, c, now);
            } else {
                OnKeyInactive(r, c, now);
            }
        }

        digitalWrite(rowPinList[r], HIGH);
    }

    isScanning = false;
}

void KeyPad::Send() {
    SwitchControlLibrary().sendReport();
}

void KeyPad::PlayMacro() {
    if (!curMacro.isPlaying || curMacro.index == MacroRecord::NO_MACRO) {
        return;
    }

    Serial.println("+++ macro start +++");

    Record *r = macroList[curMacro.index];
    for (; r->type != Operation::END; ++r) {
        if (CheckIsActive(curMacro.row, curMacro.col)) {
            OnKeyActive(curMacro.row, curMacro.col, millis());
            break;
        }

        Serial.print("macro(");
        Serial.print(r->type);
        Serial.print(", ");
        Serial.print(r->param);
        Serial.println(")");

        switch (r->type) {
        case Operation::BTN:
            PressKey(r->param);
            break;
        case Operation::HAT_BTN:
            PressHat(r->param);
            break;
        case Operation::DELAY:
            delay(r->param);
            break;
        }
    }

    if (r->type == Operation::END && r->param == 0) {
        Serial.println("--- macro ends ---");
        curMacro.index = MacroRecord::NO_MACRO;
    }
}

// ----------------------------------------------------------------------------

bool KeyPad::CheckIsActive(int c) {
    int colPin = colPinList[c];

    bool isActive = digitalRead(colPin) == LOW;

    return isActive;
}

bool KeyPad::CheckIsActive(int r, int c) {
    int rowPin = rowPinList[r];
    int colPin = colPinList[c];

    digitalWrite(rowPin, LOW);
    bool isActive = digitalRead(colPin) == LOW;
    digitalWrite(rowPin, HIGH);

    return isActive;
}

void KeyPad::OnKeyActive(int r, int c, int now) {
    Key &k = keyMatrix[r][c];
    switch (k.state) {
    case Key::State::TRIGGERED:
        k.state = Key::State::PRESSED;
        OnKeyPressed(r, c);
        k.updatetime = now;
        break;
    case Key::State::PRESSED:
        if (now - k.updatetime > holdThreshold) {
            k.state = Key::State::HELD;
            OnKeyHeld(r, c);
            k.updatetime = now;
        }
        break;
    case Key::State::HELD:
        break;
    case Key::State::RELEASED:
        k.state = Key::State::TRIGGERED;
        k.updatetime = now;
        break;
    }
}

void KeyPad::OnKeyInactive(int r, int c, int now) {
    Key &k = keyMatrix[r][c];
    switch (k.state) {
    case Key::State::TRIGGERED:
        k.state = Key::State::RELEASED;
        k.updatetime = now;
        break;
    case Key::State::PRESSED:
        k.state = Key::State::RELEASED;
        OnKeyReleased(r, c);
        k.updatetime = now;
        break;
    case Key::State::HELD:
        k.state = Key::State::RELEASED;
        OnKeyReleased(r, c);
        k.updatetime = now;
        break;
    case Key::State::RELEASED:
        break;
    }
}

// ----------------------------------------------------------------------------

void KeyPad::OnKeyPressed(int r, int c) {
    Record &re = keyMap[curLayer][r * col + c];
    Serial.print("(");
    Serial.print(re.type);
    Serial.print(", ");
    Serial.print(re.param);
    Serial.println(")");

    switch (re.type) {
    case Operation::BTN:
        SwitchControlLibrary().pressButton(re.param);
        break;
    case Operation::HAT_BTN:
        SwitchControlLibrary().pressHatButton(re.param);
        break;
    case Operation::MACRO:
        curMacro.isPlaying = false;
        curMacro.index = curMacro.index == MacroRecord::NO_MACRO ? re.param : MacroRecord::NO_MACRO;
        curMacro.row = r;
        curMacro.col = c;
        break;
    }
}

void KeyPad::OnKeyHeld(int r, int c) {}

void KeyPad::OnKeyReleased(int r, int c) {
    Record &re = keyMap[curLayer][r * col + c];

    switch (re.type) {
    case Operation::BTN:
        SwitchControlLibrary().releaseButton(re.param);
        break;
    case Operation::HAT_BTN:
        SwitchControlLibrary().releaseHatButton(re.param);
        break;
    case Operation::MACRO:
        curMacro.isPlaying = true;
        break;
    }
}

// ----------------------------------------------------------------------------

void KeyPad::PressKey(uint16_t button) {
    SwitchControlLibrary().pressButton(button);
    SwitchControlLibrary().sendReport();
    delay(clickDelay);
    SwitchControlLibrary().releaseButton(button);
    SwitchControlLibrary().sendReport();
    delay(keyEndDelay);
}

void KeyPad::PressHat(uint8_t button) {
    SwitchControlLibrary().pressHatButton(button);
    SwitchControlLibrary().sendReport();
    delay(clickDelay);
    SwitchControlLibrary().releaseHatButton(button);
    SwitchControlLibrary().sendReport();
    delay(keyEndDelay);
}
