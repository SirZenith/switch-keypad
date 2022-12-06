#include "KeyPad.h"

// ----------------------------------------------------------------------------

bool keypad::KeyPad::MacroTarget::CheckHasMacroBinded() {
    return macro != nullptr;
}

bool keypad::KeyPad::MacroTarget::CheckIsMacroPlaying() {
    return isPlaying && CheckHasMacroBinded();
}

void keypad::KeyPad::MacroTarget::ToggleMacro(const MacroRecord *macro, int r, int c) {
    row = r;
    col = c;
    macro = CheckHasMacroBinded() ? macro : nullptr;
}

void keypad::KeyPad::MacroTarget::UpdateMacroBinding(const MacroRecord **macroList, int index, int r, int c) {
    row = r;
    col = c;
    macro = CheckHasMacroBinded() ? macroList[index] : nullptr;
}

void keypad::KeyPad::MacroTarget::Unbind() {
    macro = nullptr;
}

// ----------------------------------------------------------------------------

keypad::KeyPad::KeyPad(
    int row, int col, int layer,
    int *rowPinList, int *colPinList,
    const Record **keyMap, const MacroRecord **macroList,
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

    curMacro = MacroTarget();
}

keypad::KeyPad::~KeyPad() {
    for (int r = 0; r < row; ++r) {
        delete[] keyMatrix[r];
    }
    delete[] keyMatrix;
}

// ----------------------------------------------------------------------------

void keypad::KeyPad::SetLEDPin(int red, int orange, int yellow, int blue) {
    redLEDPin = red;
    orangeLEDPin = orange;
    yellowLEDPin = yellow;
    blueLEDPin = blue;
}

void keypad::KeyPad::Begin() {
    switch_controller::controller.Begin();
}

void keypad::KeyPad::End() {
    switch_controller::controller.End();
}

bool keypad::KeyPad::Ready() {
    return switch_controller::controller.Ready();
}

void keypad::KeyPad::Scan() {
    // If macro is playing, keyboard scan is locked, so that keyboard layer will
    // stay the same as when macro started.
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

    UpdateLEDState();
}

void keypad::KeyPad::Send() {
    if (isDirty) {
        switch_controller::controller.SendReport();
        isDirty = false;
    }
}

void keypad::KeyPad::PlayMacro() {
    if (!curMacro.CheckIsMacroPlaying()) {
        return;
    }

    OperationLog("[macro]: start");

    const MacroRecord *re = curMacro.macro;
    for (; re->type != Operation::END; ++re) {
        if (CheckIsActive(curMacro.row, curMacro.col)) {
            OperationLog("[macro]: end");
            OnKeyActive(curMacro.row, curMacro.col, millis());
            break;
        }

        UpdateLEDState();
        OperationLog(nullptr, re);

        using switch_controller::controller;

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
            controller.Press(re->param);
            controller.SendReport();
            break;
        case Operation::RELEASE:
            controller.Release(re->param);
            controller.SendReport();
            break;
        case Operation::CLICK:
            controller.Press(re->param);
            controller.SendReport();
            delay(clickDelay);
            controller.Release(re->param);
            controller.SendReport();
            delay(clickEndDelay);

        default:
            break;
        }
    }

    if (re->type == Operation::END && re->param == 0) {
        curMacro.Unbind();
    }
}

// ----------------------------------------------------------------------------

void keypad::KeyPad::OperationLog(const char *msg, const MacroRecord *re) {
#ifdef DEBUG
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
#endif
}

void keypad::KeyPad::UpdateLEDState() {
    unsigned long now = millis();
    unsigned long deltaTime = now - lastLEDUpdateTime;

    if (deltaTime < MIN_LED_UPDATE_STEP) {
        return;
    }

    if (recorder.IsRecording()) {
        // recording macro
        unsigned int spareSpace = recorder.SpareSpace();
        unsigned int capacity = recorder.Capacity();
        float percentage = float(spareSpace) / float(capacity);

        if (percentage > 0.5) {
            redLEDPin = HIGH;
        } else {
            unsigned long gap = ULONG_MAX;
            if (percentage > 0.25) {
                gap = BLINK_TIME;
            } else if (percentage > 0.125) {
                gap = FAST_BLINK_TIME;
            } else if (percentage > 0) {
                gap = SUPER_FAST_BLINK_TIME;
            }

            if (deltaTime > gap) {
                redLEDState = !redLEDState;
            }
        }
    } else if (curMacro.CheckIsMacroPlaying()) {
        // playing macro
        if (deltaTime > BLINK_TIME) {
            blueLEDState = !blueLEDState;
        }
    } else if (isDirty) {
        // normal state
        yellowLEDState = HIGH;
    }

    UpdateLED(redLEDPin, redLEDState);
    UpdateLED(orangeLEDPin, orangeLEDState);
    UpdateLED(yellowLEDPin, yellowLEDState);
    UpdateLED(blueLEDPin, blueLEDState);

    lastLEDUpdateTime = now;
}

void keypad::KeyPad::UpdateLED(int pin, int value) {
    if (pin == NO_LED_PIN) {
        return;
    }

    digitalWrite(pin, value);
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
        curMacro.UpdateMacroBinding(macroList, re.param, r, c);
        break;
    case Operation::MACRO_RECORD:
        recorder.ToggleRecording(false);
        break;
    case Operation::MACRO_RECORD_LOOP:
        recorder.ToggleRecording(true);
        break;
    case Operation::MACRO_PLAY_RECORDED:
        curMacro.isPlaying = false;
        curMacro.ToggleMacro(recorder.GetMacro(), r, c);
        break;
    // -------------------------------------------------------------------------
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
    // -------------------------------------------------------------------------
    case Operation::PRESS:
        switch_controller::controller.Press(re.param);
        recorder.TryRecord(re);
        break;
    case Operation::RELEASE:
        switch_controller::controller.Release(re.param);
        recorder.TryRecord(re);
        break;
    // -------------------------------------------------------------------------
    default:
        isDirty = false;
        break;
    }
}

void keypad::KeyPad::DoKeyRelease(Key &key, const Record &re, int r, int c, int layer) {
    isDirty = true;

    switch (re.type) {
    case Operation::MACRO:
    case Operation::MACRO_PLAY_RECORDED:
        curMacro.isPlaying = true;
        break;
    // -------------------------------------------------------------------------
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
    // -------------------------------------------------------------------------
    case Operation::PRESS:
        switch_controller::controller.Release(re.param);
        recorder.TryRecord(Record(Operation::RELEASE, re.param));
        break;
    // -------------------------------------------------------------------------
    default:
        isDirty = false;
        break;
    }
}
