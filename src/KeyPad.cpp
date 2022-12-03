#include "KeyPad.h"

// ----------------------------------------------------------------------------

bool keypad::MacroRecord::CheckIsMacroPlaying() {
    return isPlaying && index != MacroRecord::NO_MACRO;
}

// ----------------------------------------------------------------------------

keypad::Record::Record(Operation op, unsigned long param)
    : type{op},
      param{param},
      onHold{nullptr} {}

keypad::Record::Record(Record onTap, Record onHold)
    : type{onTap.type},
      param{onTap.param},
      onHold{new Record(onHold.type, onHold.param)} {}

keypad::Record::~Record() {
    if (onHold != nullptr) {
        delete onHold;
    }
}

void keypad::Record::SetOnHold(Record r) {
    onHold = new Record(r.type, r.param);
}

// ----------------------------------------------------------------------------

keypad::KeyPad::KeyPad(
    int row, int col, int layer,
    int *rowPinList, int *colPinList,
    const Record **keyMap, const Record **macroList,
    unsigned long debounce, unsigned long holdThreshold,
    unsigned long clickDelay, unsigned long clickEndDelay
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
    clickEndDelay{clickEndDelay} {

    keyMatrix = new Key *[row];
    for (int r = 0; r < row; ++r) {
        Key *keyRow = new Key[col];
        keyMatrix[r] = keyRow;

        for (int c = 0; c < col; ++c) {
            keyRow[c].layer = LayeringState::NO_LAYER;
        }
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
    if (curMacro.CheckIsMacroPlaying()) {
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
    if (isDirty) {
        SwitchController().SendReport();
        isDirty = false;
    }
}

void keypad::KeyPad::PlayMacro() {
    if (!curMacro.CheckIsMacroPlaying()) {
        return;
    }

    digitalWrite(LED_BUILTIN, HIGH);
    OperationLog("[macro]: start");

    const Record *re = macroList[curMacro.index];
    for (; re->type != Operation::END; ++re) {
        if (CheckIsActive(curMacro.row, curMacro.col)) {
            OperationLog("[macro]: end");
            OnKeyActive(curMacro.row, curMacro.col, millis());
            break;
        }

        OperationLog(nullptr, re);

        switch (re->type) {
        case Operation::DELAY:
            delay(re->param);
            break;
        case Operation::CLICK_DELAY:
            delay(clickDelay);
            break;
        case Operation::CLICK_END_DELAY:
            delay(clickEndDelay);
            break;
        // --------------------------------------------------------------------
        case Operation::PRESS:
            SwitchController().Press(re->param);
            SwitchController().SendReport();
            break;
        case Operation::RELEASE:
            SwitchController().Release(re->param);
            SwitchController().SendReport();
            break;
        case Operation::CLICK:
            SwitchController().Press(re->param);
            SwitchController().SendReport();
            delay(clickDelay);
            SwitchController().Release(re->param);
            SwitchController().SendReport();
            delay(clickEndDelay);

        default:
            break;
        }
    }

    if (re->type == Operation::END && re->param == 0) {
        curMacro.index = MacroRecord::NO_MACRO;
    }

    digitalWrite(LED_BUILTIN, LOW);
}

// ----------------------------------------------------------------------------

void keypad::KeyPad::OperationLog(const char *msg, const Record *re) {
    Serial.print(msg);

    if (re != nullptr) {
        const char *name = nullptr;
        unsigned long value = 0;

        switch (re->type) {
        case Operation::PRESS:
        case Operation::RELEASE:
        case Operation::CLICK:
            using switch_controller::KeyCode;

            name = switch_controller::GetNameOfKeyCode((KeyCode)re->param);
            value = switch_controller::GetValueInKeyCode((KeyCode)re->param);
            break;

        default:
            name = GetOperatioinName(re->type);
            value = re->param;
            break;
        }
        Serial.print(name);
        Serial.print("(");
        Serial.print(value);
        Serial.print(")");
    }

    Serial.print("\n");
#ifdef DEBUG
#endif
}

// ----------------------------------------------------------------------------

bool keypad::KeyPad::DebounceCheck(int r, int c, unsigned long now) {
    Key &k = keyMatrix[r][c];

    unsigned long duration = now >= k.updatetime
                                 ? now - k.updatetime
                                 : ULONG_MAX - k.updatetime + now;
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

    if (r == 1 && c == 2) {
        Serial.println(k.state);
    }
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
    const Record &re = keyMap[layer][r * col + c];

    if (layeringState.IsInOneShotState()) {
        layeringState.OneShotLayerOff();
    }

    if (re.onHold == nullptr) {
        OperationLog("press: ", &re);
        DoKeyTap(key, re, r, c, layer);
    }
}

void keypad::KeyPad::OnKeyHeld(int r, int c) {
    Key &key = keyMatrix[r][c];
    int layer = key.layer != LayeringState::NO_LAYER
                    ? key.layer
                    : layeringState.GetCurLayer();
    const Record &re = keyMap[layer][r * col + c];

    if (re.onHold != nullptr) {
        OperationLog("hold: ", re.onHold);
        key.isHoldTriggered = true;
        DoKeyTap(key, *re.onHold, r, c, layer);
    }
}

void keypad::KeyPad::OnKeyReleased(int r, int c) {
    Key &key = keyMatrix[r][c];
    int layer = key.layer != LayeringState::NO_LAYER
                    ? key.layer
                    : layeringState.GetCurLayer();
    const Record &re = keyMap[layer][r * col + c];

    if (re.onHold == nullptr) {
        DoKeyRelease(key, re, r, c, layer);
    } else if (key.isHoldTriggered) {
        key.isHoldTriggered = false;
        DoKeyRelease(key, *re.onHold, r, c, layer);
    } else {
        OperationLog("trigger: ", &re);
        DoKeyTap(key, re, r, c, layer);
        DoKeyRelease(key, re, r, c, layer);
    }
}

// ----------------------------------------------------------------------------

void keypad::KeyPad::DoKeyTap(Key &key, const Record &re, int r, int c, int layer) {
    isDirty = true;

    switch (re.type) {
    case Operation::MACRO:
        curMacro.isPlaying = false;
        curMacro.index = curMacro.index == MacroRecord::NO_MACRO
                             ? re.param
                             : MacroRecord::NO_MACRO;
        curMacro.row = r;
        curMacro.col = c;
        break;
    // ------------------------------------------------------------------------
    case Operation::MOMENT_LAYER:
        key.layer = layer;
        layeringState.ActivateLayer(re.param);
        break;
    case Operation::ONE_SHOT_LAYER:
        key.layer = layer;
        layeringState.OneShotLayerOn(re.param);
        break;
    case Operation::TOGGLE_LAYER:
        key.layer = layer;
        layeringState.ToggleLayer(re.param);
        break;
    case Operation::DEFAULT_LAYER:
        layeringState.SetDefaultLayer(re.param);
        break;
    // ------------------------------------------------------------------------
    case Operation::PRESS:
        SwitchController().Press(re.param);
        break;
    case Operation::RELEASE:
        SwitchController().Release(re.param);
        break;
    // ------------------------------------------------------------------------
    default:
        isDirty = false;
        break;
    }
}

void keypad::KeyPad::DoKeyRelease(Key &key, const Record &re, int r, int c, int layer) {
    isDirty = true;

    switch (re.type) {
    case Operation::MACRO:
        curMacro.isPlaying = true;
        break;
    // ------------------------------------------------------------------------
    case Operation::MOMENT_LAYER:
        key.layer = LayeringState::NO_LAYER;
        layeringState.DeactivateLayer(re.param);
        break;
    case Operation::ONE_SHOT_LAYER:
        key.layer = LayeringState::NO_LAYER;
        break;
    case Operation::TOGGLE_LAYER:
        key.layer = LayeringState::NO_LAYER;
        break;
    case Operation::DEFAULT_LAYER:
        break;
    // ------------------------------------------------------------------------
    case Operation::PRESS:
        SwitchController().Release(re.param);
        break;
    // ------------------------------------------------------------------------
    default:
        isDirty = false;
        break;
    }
}
