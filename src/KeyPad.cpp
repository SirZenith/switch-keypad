#include "KeyPad.h"

// -----------------------------------------------------------------------------

keypad::KeyPad::KeyPad(
    int *rowPinList, int *colPinList,
    unsigned long debounce, unsigned long holdThreshold,
    MacroPlayer &macroPlayer,
    KeyHandler **handlers
) : rowPinList{rowPinList}, colPinList{colPinList},
    debounce{debounce}, holdThreshold{holdThreshold},
    macroPlayer{macroPlayer},
    handlers{handlers} {

    for (row = 0; rowPinList[row] != NOT_A_PIN; ++row) {
    }
    for (col = 0; colPinList[col] != NOT_A_PIN; ++col) {
    }

    keyMatrix = new Key *[row];
    for (int r = 0; r < row; ++r) {
        Key *keyRow = new Key[col];
        keyMatrix[r] = keyRow;

        for (int c = 0; c < col; ++c) {
            keyRow[c].layer = LayeringState::NO_LAYER;
        }
    }

    for (handlerCnt = 0; handlers[handlerCnt] != nullptr; ++handlerCnt) {
    }
}

keypad::KeyPad::~KeyPad() {
    for (int r = 0; r < row; ++r) {
        delete[] keyMatrix[r];
    }
    delete[] keyMatrix;
}

// -----------------------------------------------------------------------------

void keypad::KeyPad::LogState() {
#ifdef DEBUG
    Serial.println("---------- State Log ----------");

    Serial.print("row: ");
    Serial.print(row);
    Serial.print("\n");

    Serial.print("col: ");
    Serial.print(col);
    Serial.print("\n");

    Serial.print("layers: ");
    Serial.print(layeringState.GetCurLayer() + 1);
    Serial.print("/");
    Serial.print(layeringState.GetLayerCnt());
    Serial.print("\n");

    Serial.print("handlers: ");
    Serial.print(handlerCnt);
    if (handler != nullptr) {
        Serial.print(" - ");
        Serial.print(handler->Name());
    }
    Serial.print("\n");

    Serial.println("-------------------------------");
#endif
}

// -----------------------------------------------------------------------------

void keypad::KeyPad::SetLEDPin(int red, int orange, int yellow, int blue) {
    redLEDPin = red;
    orangeLEDPin = orange;
    yellowLEDPin = yellow;
    blueLEDPin = blue;

    digitalWrite(red, LOW);
    digitalWrite(orange, LOW);
    digitalWrite(yellow, LOW);
    digitalWrite(blue, LOW);
}

void keypad::KeyPad::SetHandler(int index) {
    if (index < 0 || index >= handlerCnt) {
        return;
    }

    KeyHandler *newHandler = handlers[index];

    if (handler == newHandler || newHandler == nullptr) {
        return;
    }

    if (handler != nullptr) {
        handler->End();
    }

    handler = newHandler;
    handler->Begin();

    layeringState.Reset();
    layeringState.SetDefaultLayer(handler->DefaultLayer());
    layeringState.SetLayerCnt(handler->LayerCnt());

    macroPlayer.Unbind();

    changeHandlerLEDBlinkCnt = CHANGE_HANDLER_LED_BLINK_CNT;
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

    for (int c = 0; c < col; ++c) {
        digitalWrite(colPinList[c], LOW);

        for (int r = 0; r < row; ++r) {
            if (!DebounceCheck(r, c, now)) {
                // pass
            } else if (CheckIsActive(r)) {
                OnKeyActive(r, c, now);
            } else {
                OnKeyInactive(r, c, now);
            }
        }

        digitalWrite(colPinList[c], HIGH);
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

    const MacroRecord *re = macroPlayer.Next();

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
        if (!re->param) {
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
    unsigned long deltaTime = now > lastLEDUpdateTime
                                  ? now - lastLEDUpdateTime
                                  : ULONG_MAX - lastLEDUpdateTime + now;

    if (deltaTime < MIN_LED_UPDATE_STEP) {
        return;
    }

#ifdef USE_LED
    // -------------------------------------------------------------------------
    // Red
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
    }
    UpdateLED(redLEDPin, redLEDState);

    // -------------------------------------------------------------------------
    // Orange
    if (changeHandlerLEDBlinkCnt > 0) {
        orangeLEDState = !orangeLEDState;
        if (!orangeLEDState) {
            --changeHandlerLEDBlinkCnt;
        }
    }
    UpdateLED(orangeLEDPin, orangeLEDState);

    // -------------------------------------------------------------------------
    // Yellow
    if (handler->Dirty()) {
        // normal state
        yellowLEDState = HIGH;
    }
    UpdateLED(yellowLEDPin, yellowLEDState);

    // -------------------------------------------------------------------------
    // Blue
    if (macroPlayer.CheckIsMacroPlaying()) {
        // playing macro
        if (deltaTime > BLINK_TIME) {
            blueLEDState = !blueLEDState;
        }
    }
    UpdateLED(blueLEDPin, blueLEDState);
#else
    if (recorder.IsRecording()) {
        // recording macro
        unsigned int spareSpace = recorder.SpareSpace();
        unsigned int capacity = recorder.Capacity();
        float percentage = float(spareSpace) / float(capacity);

        if (percentage > 0.5) {
            builtInLEDState = LOW;
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
                builtInLEDState = !builtInLEDState;
            }
        } else {
            builtInLEDState = HIGH;
        }
    } else if (changeHandlerLEDBlinkCnt > 0) {
        builtInLEDState = !builtInLEDState;
        if (!orangeLEDState) {
            --changeHandlerLEDBlinkCnt;
        }
    } else if (handler->Dirty()) {
        // normal state
        builtInLEDState = LOW;
    } else if (macroPlayer.CheckIsMacroPlaying()) {
        // playing macro
        if (deltaTime > BLINK_TIME) {
            builtInLEDState = !builtInLEDState;
        }
    } else {
        builtInLEDState = HIGH;
    }

    digitalWrite(LED_BUILTIN, builtInLEDState);
#endif

    lastLEDUpdateTime = now;
}

void keypad::KeyPad::Step() {
    if (!Ready()) {
        return;
    }

    Scan();
    PlayMacro();
    UpdateLEDs();

    Send();
}

// -----------------------------------------------------------------------------

void keypad::KeyPad::OperationLog(const char *msg, const MacroRecord *re) {
#ifdef DEBUG
    handler->OperationLog(msg, re);
#endif
}

void keypad::KeyPad::UpdateLED(int pin, int value) {
    if (pin == NOT_A_PIN) {
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

bool keypad::KeyPad::CheckIsActive(int r) {
    int rowPin = rowPinList[r];

    bool isActive = digitalRead(rowPin) == LOW;

    return isActive;
}

bool keypad::KeyPad::CheckIsActive(int r, int c) {
    int rowPin = rowPinList[r];
    int colPin = colPinList[c];

    digitalWrite(colPin, LOW);
    bool isActive = digitalRead(rowPin) == LOW;
    digitalWrite(colPin, HIGH);

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
    const Record &re = handler->GetRecord(layer, r * col + c);

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
    const Record &re = handler->GetRecord(layer, r * col + c);

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
    const Record &re = handler->GetRecord(layer, r * col + c);

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
        handler->ReleaseAll();
        macroPlayer.isAllowedToPlay = false;
        macroPlayer.ToggleMacro(handler->GetMacro(re.param), r, c);
        break;
    case Operation::MACRO_RECORD:
        recorder.ToggleRecording(false);
        break;
    case Operation::MACRO_RECORD_LOOP:
        recorder.ToggleRecording(true);
        break;
    case Operation::MACRO_PLAY_RECORDED:
        handler->ReleaseAll();
        macroPlayer.isAllowedToPlay = false;
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
        macroPlayer.isAllowedToPlay = true;
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
