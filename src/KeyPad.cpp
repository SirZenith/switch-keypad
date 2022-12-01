#include "KeyPad.h"

// ----------------------------------------------------------------------------

keypad::KeyPad::KeyPad(
    int row, int col, int layer,
    int *rowPinList, int *colPinList,
    Record **keyMap, Record **macroList,
    unsigned long debounce, unsigned long holdThreshold,
    unsigned long clickDelay, unsigned long changeKeyDelay
) : row{row},
    col{col},
    // ------------------------------------------------------------------------
    rowPinList{rowPinList},
    colPinList{colPinList},
    keyMap{keyMap},
    macroList{macroList},
    // ------------------------------------------------------------------------
    debounce{debounce},
    holdThreshold{holdThreshold},
    clickDelay{clickDelay},
    keyEndDelay{keyEndDelay} {

    keyMatrix = new Key *[row];
    for (int r = 0; r < row; ++r) {
        keyMatrix[r] = new Key[col];
    }

    layeringState = LayeringState();
    layeringState.SetLayerCnt(layer);

    curMacro = MacroRecord();
}

keypad::KeyPad::~KeyPad() {
    for (int r = 0; r < row; ++r) {
        delete[] keyMatrix[r];
    }
    delete[] keyMatrix;
}

// ----------------------------------------------------------------------------

void keypad::KeyPad::Scan() {
    if (CheckIsMacroPlaying()) {
        return;
    }

    unsigned long now = micros();

    for (int r = 0; r < row; ++r) {
        digitalWrite(rowPinList[r], LOW);

        for (int c = 0; c < col; ++c) {
            if (!DebounceCheck(r, c, now)) {
                // pass
            } else if (CheckIsActive(c)) {
                OnKeyActive(r, c, now);
            } else {
                OnKeyInactive(r, c, now);
            }
        }

        digitalWrite(rowPinList[r], HIGH);
    }
}

void keypad::KeyPad::Send() {
    SwitchControlLibrary().sendReport();
}

void keypad::KeyPad::PlayMacro() {
    if (!CheckIsMacroPlaying()) {
        return;
    }

    digitalWrite(LED_BUILTIN, HIGH);

    Record *r = macroList[curMacro.index];
    for (; r->type != Operation::END; ++r) {
        if (CheckIsActive(curMacro.row, curMacro.col)) {
            OnKeyActive(curMacro.row, curMacro.col, millis());
            break;
        }

        OperationLog("macro", r);

        switch (r->type) {
        case Operation::BTN:
            SimPressKey(r->param);
            break;
        case Operation::HAT_BTN:
            SimPressHat(r->param);
            break;
        case Operation::DELAY:
            delay(r->param);
            break;
        }
    }

    if (r->type == Operation::END && r->param == 0) {
        curMacro.index = MacroRecord::NO_MACRO;
    }

    digitalWrite(LED_BUILTIN, LOW);
}

// ----------------------------------------------------------------------------

void keypad::KeyPad::OperationLog(const char *msg, Record *re) {
#ifdef DEBUG
    Serial.print(msg);
    if (re != nullptr) {
        Serial.print("(");
        Serial.print(re->type);
        Serial.print(", ");
        Serial.print(re->param);
        Serial.print(")");
    }

    Serial.print("\n");
#endif
}

// ----------------------------------------------------------------------------

bool keypad::KeyPad::CheckIsMacroPlaying() {
    return curMacro.isPlaying && curMacro.index != MacroRecord::NO_MACRO;
}

bool keypad::KeyPad::DebounceCheck(int r, int c, unsigned long now) {
    Key &k = keyMatrix[r][c];

    unsigned long duration = now >= k.updatetime
                                 ? now - k.updatetime
                                 : now + ULONG_MAX - k.updatetime;
    return duration >= debounce;
}

bool keypad::KeyPad::CheckIsActive(int c) {
    int colPin = colPinList[c];

    bool isActive = digitalRead(colPin) == LOW;

    return isActive;
}

bool keypad::KeyPad::CheckIsActive(int r, int c) {
    int rowPin = rowPinList[r];
    int colPin = colPinList[c];

    digitalWrite(rowPin, LOW);
    bool isActive = digitalRead(colPin) == LOW;
    digitalWrite(rowPin, HIGH);

    return isActive;
}

void keypad::KeyPad::OnKeyActive(int r, int c, unsigned long now) {
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

void keypad::KeyPad::OnKeyInactive(int r, int c, unsigned long now) {
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

void keypad::KeyPad::OnKeyPressed(int r, int c) {
    Key &key = keyMatrix[r][c];
    int layer = key.layer != LayeringState::NO_LAYER
                    ? key.layer
                    : layeringState.GetCurLayer();
    Record &re = keyMap[layer][r * col + c];

    OperationLog("press", &re);

    if (layeringState.IsInOneShotState()) {
        layeringState.OneShotLayerOff();
    }

    switch (re.type) {
    case Operation::MACRO:
        curMacro.isPlaying = false;
        curMacro.index = curMacro.index == MacroRecord::NO_MACRO
                             ? re.param
                             : MacroRecord::NO_MACRO;
        curMacro.row = r;
        curMacro.col = c;
        break;
    case Operation::MOMENT_LAYER:
        key.layer = layer;
        layeringState.ActivateLayer(re.param);
        break;
    case Operation::ONE_SHOT_LAYER:
        layeringState.OneShotLayerOn(re.param);
        break;
    case Operation::TOGGLE_LAYER:
        key.layer = layer;
        layeringState.ToggleLayer(re.param);
        break;
    case Operation::DEFAULT_LAYER:
        layeringState.SetDefaultLayer(re.param);
        break;
    case Operation::BTN:
        SwitchControlLibrary().pressButton(re.param);
        break;
    case Operation::HAT_BTN:
        SwitchControlLibrary().pressHatButton(re.param);
        break;
    case Operation::L_STICK:
        SwitchControlLibrary().moveLeftStick(
            (re.param >> sizeof(uint8_t)) & UINT8_MAX,
            re.param & UINT8_MAX
        );
        break;
    case Operation::R_STICK:
        SwitchControlLibrary().moveRightStick(
            (re.param >> sizeof(uint8_t)) & UINT8_MAX,
            re.param & UINT8_MAX
        );
        break;
    default:
        break;
    }
}

void keypad::KeyPad::OnKeyHeld(int r, int c) {
    Key &key = keyMatrix[r][c];
    int layer = key.layer != LayeringState::NO_LAYER
                    ? key.layer
                    : layeringState.GetCurLayer();
    Record &re = keyMap[layer][r * col + c];

    OperationLog("hold", &re);
}

void keypad::KeyPad::OnKeyReleased(int r, int c) {
    Key &key = keyMatrix[r][c];
    int layer = key.layer != LayeringState::NO_LAYER
                    ? key.layer
                    : layeringState.GetCurLayer();
    Record &re = keyMap[layer][r * col + c];

    switch (re.type) {
    case Operation::MACRO:
        curMacro.isPlaying = true;
        break;
    case Operation::MOMENT_LAYER:
        key.layer = LayeringState::NO_LAYER;
        layeringState.DeactivateLayer(re.param);
        break;
    case Operation::TOGGLE_LAYER:
        key.layer = LayeringState::NO_LAYER;
        break;
    case Operation::BTN:
        SwitchControlLibrary().releaseButton(re.param);
        break;
    case Operation::HAT_BTN:
        SwitchControlLibrary().releaseHatButton(re.param);
        break;
    case Operation::L_STICK:
        SwitchControlLibrary().moveLeftStick(Stick::NEUTRAL, Stick::NEUTRAL);
    case Operation::R_STICK:
        SwitchControlLibrary().moveRightStick(Stick::NEUTRAL, Stick::NEUTRAL);
    default:
        break;
    }
}

// ----------------------------------------------------------------------------

void keypad::KeyPad::SimPressKey(uint16_t button) {
    SwitchControlLibrary().pressButton(button);
    SwitchControlLibrary().sendReport();
    delay(clickDelay);
    SwitchControlLibrary().releaseButton(button);
    SwitchControlLibrary().sendReport();
    delay(keyEndDelay);
}

void keypad::KeyPad::SimPressHat(uint8_t button) {
    SwitchControlLibrary().pressHatButton(button);
    SwitchControlLibrary().sendReport();
    delay(clickDelay);
    SwitchControlLibrary().releaseHatButton(button);
    SwitchControlLibrary().sendReport();
    delay(keyEndDelay);
}