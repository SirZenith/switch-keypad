#include "KeyPad.h"

// -----------------------------------------------------------------------------

keypad::KeyPad::KeyPad(
    int row, int col, int layer,
    int *rowPinList, int *colPinList,
    unsigned long debounce, unsigned long holdThreshold,
    const Record **keyMap,
    MacroPlayer &macroPlayer,
    KeyHandler **handlers
) : row{row}, col{col}, layeringState{layer},
    rowPinList{rowPinList}, colPinList{colPinList},
    debounce{debounce}, holdThreshold{holdThreshold},
    keyMap{keyMap},
    macroPlayer{macroPlayer},
    handlers{handlers} {

    keyMatrix = new Key *[row];
    for (int r = 0; r < row; ++r) {
        Key *keyRow = new Key[col];
        keyMatrix[r] = keyRow;

        for (int c = 0; c < col; ++c) {
            keyRow[c].layer = LayeringState::NO_LAYER;
        }
    }

    handlerCnt = 0;
    for (KeyHandler *walk = handlers[0]; walk != nullptr; ++walk) {
        ++handlerCnt;
    }
}

keypad::KeyPad::~KeyPad() {
    for (int r = 0; r < row; ++r) {
        delete[] keyMatrix[r];
    }
    delete[] keyMatrix;
}

// -----------------------------------------------------------------------------

void keypad::KeyPad::SetLEDPin(int red, int orange, int yellow, int blue) {
    redLEDPin = red;
    orangeLEDPin = orange;
    yellowLEDPin = yellow;
    blueLEDPin = blue;
}

void keypad::KeyPad::SetHandler(uint index) {
    handler = index < handlerCnt ? handlers[index] : handler;
}

// -----------------------------------------------------------------------------

void keypad::KeyPad::Begin() {
    handler->Begin();
}

void keypad::KeyPad::End() {
    handler->End();
}

bool keypad::KeyPad::Ready() {
    return handler != nullptr && handler->Ready();
}

void keypad::KeyPad::Scan() {
    // If macro is playing, keyboard scan is locked, so that keyboard layer will
    // stay the same as when macro started.
    if (macroPlayer.CheckIsMacroPlaying()) {
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
    handler->Send();
}

void keypad::KeyPad::PlayMacro() {
    if (!macroPlayer.CheckIsMacroPlaying()) {
        return;
    } else if (CheckIsActive(macroPlayer.row, macroPlayer.col)) {
        // interrupt by key
        OnKeyActive(macroPlayer.row, macroPlayer.col, millis());
        return;
    } else if (macroPlayer.CheckIsIdle()) {
        // handling delay
        return;
    }

    const MacroRecord *re = macroPlayer.GetMacro();

    OperationLog(nullptr, re);

    switch (re->type) {
    case Operation::DELAY:
        macroPlayer.Delay(re->param);
        break;
    case Operation::CLICK_DELAY:
        macroPlayer.ClickDelay();
        break;
    case Operation::CLICK_END_DELAY:
        macroPlayer.ClickEndDelay();
        break;
    // -------------------------------------------------------------------------
    case Operation::END:
        if (re->param) {
            macroPlayer.Unbind();
        }
        break;
    // -------------------------------------------------------------------------
    case Operation::PRESS:
        handler->Press(re->param);
        break;
    case Operation::RELEASE:
        handler->Release(re->param);
        break;
    case Operation::CLICK:
        if (!macroPlayer.CheckNeedClick()) {
            handler->Press(re->param);
            macroPlayer.ClickDelay();
        } else {
            handler->Release(re->param);
            macroPlayer.ClickEndDelay();
        }
        break;

    default:
        break;
    }
}

void keypad::KeyPad::UpdateLEDs() {
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
        } else if (percentage > 0) {
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
        } else {
            redLEDState = LOW;
        }
    } else if (macroPlayer.CheckIsMacroPlaying()) {
        // playing macro
        if (deltaTime > BLINK_TIME) {
            blueLEDState = !blueLEDState;
        }
    } else if (handler->Dirty()) {
        // normal state
        yellowLEDState = HIGH;
    }

    UpdateLED(redLEDPin, redLEDState);
    UpdateLED(orangeLEDPin, orangeLEDState);
    UpdateLED(yellowLEDPin, yellowLEDState);
    UpdateLED(blueLEDPin, blueLEDState);

    lastLEDUpdateTime = now;
}

// -----------------------------------------------------------------------------

void keypad::KeyPad::OperationLog(const char *msg, const MacroRecord *re) {
#ifdef DEBUG
    handler->OperationLog(msg, re);
#endif
}

void keypad::KeyPad::UpdateLED(int pin, int value) {
    if (pin == NO_LED_PIN) {
        return;
    }

    digitalWrite(pin, value);
}

// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------

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

// -----------------------------------------------------------------------------

void keypad::KeyPad::DoKeyTap(Key &key, const Record &re, int r, int c, int layer) {
    switch (re.type) {
    case Operation::MACRO:
        macroPlayer.isPlaying = false;
        macroPlayer.ToggleIndex(re.param, r, c);
        break;
    case Operation::MACRO_RECORD:
        recorder.ToggleRecording(false);
        break;
    case Operation::MACRO_RECORD_LOOP:
        recorder.ToggleRecording(true);
        break;
    case Operation::MACRO_PLAY_RECORDED:
        macroPlayer.isPlaying = false;
        macroPlayer.ToggleMacro(recorder.GetMacro(), r, c);
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
    case Operation::CHANGE_HANDLER:
        SetHandler(re.param);
        break;
    // -------------------------------------------------------------------------
    case Operation::PRESS:
        handler->Press(re.param);
        recorder.TryRecord(re);
        break;
    case Operation::RELEASE:
        handler->Release(re.param);
        recorder.TryRecord(re);
        break;
    // -------------------------------------------------------------------------
    default:
        break;
    }
}

void keypad::KeyPad::DoKeyRelease(Key &key, const Record &re, int r, int c, int layer) {
    switch (re.type) {
    case Operation::MACRO:
    case Operation::MACRO_PLAY_RECORDED:
        macroPlayer.isPlaying = true;
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
        handler->Release(re.param);
        recorder.TryRecord(Record(Operation::RELEASE, re.param));
        break;
    // -------------------------------------------------------------------------
    default:
        break;
    }
}
