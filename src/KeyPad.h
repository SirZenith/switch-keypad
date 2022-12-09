#pragma once

#include <Arduino.h>

#include "KeyHandler.h"
#include "LayeringState.h"
#include "MacroPlayer.h"
#include "MacroRecorder.h"
#include "common.h"

namespace keypad {
    struct Key {
        enum State {
            TRIGGERED,
            PRESSED,
            HELD,
            RELEASED,
        };

        State state = State::RELEASED;
        unsigned long updatetime = 0;
        bool isHoldTriggered = false;
        // if layer will change after this key is pressed
        // then we should remember on which layer we pressed this key on,
        // so that we can release it on the same layer,
        // but not releasing another key code on changed layer.
        int layer;
        const KeyHandler *usedHandler = nullptr;
    };

    class KeyPad {
    public:
        static const unsigned long MIN_LED_UPDATE_STEP = 50;
        static const unsigned long SLOW_BLINK_TIME = 1000;
        static const unsigned long NORMAL_BLINK_TIME = 500;
        static const unsigned long FAST_BLINK_TIME = 150;
        static const unsigned long SUPER_FAST_BLINK_TIME = 50;

        KeyPad(
            int *rowPinList, int *colPinList,
            unsigned long debounce, unsigned long holdThreshold,
            MacroPlayer &macroPlayer,
            KeyHandler **handlers
        );
        ~KeyPad();

        void LogState();

        void SetLEDPin(int red, int orange, int yellow, int blue);
        void SetHandler(int index);

        void Begin();
        void End();

        bool Ready();
        void Send();

        void Scan();
        void PlayMacro();
        void UpdateLEDs();

        void Step();

    private:
        static const int CHANGE_HANDLER_LED_BLINK_CNT = 2;

        int row, col;
        int *rowPinList, *colPinList;
        unsigned long debounce, holdThreshold;

        Key **keyMatrix;
        LayeringState layeringState;
        MacroRecorder recorder;

        MacroPlayer &macroPlayer;

        int handlerCnt = 0;
        KeyHandler **handlers = nullptr;
        KeyHandler *handler = nullptr;

        unsigned long lastLEDUpdateTime = 0;

        int redLEDPin = NOT_A_PIN, redLEDState = LOW;
        int orangeLEDPin = NOT_A_PIN, orangeLEDState = LOW;
        int yellowLEDPin = NOT_A_PIN, yellowLEDState = LOW;
        int blueLEDPin = NOT_A_PIN, blueLEDState = LOW;

        int builtInLEDState = HIGH;

        int changeHandlerLEDBlinkCnt = 0;

        void OperationLog(const char *msg, const MacroRecord *re = nullptr);
        void UpdateLED(int pin, int value);
        bool UpdateExternalLED(unsigned long deltaTime);
        bool UpdateBuiltInLED(unsigned long deltaTime);

        bool DebounceCheck(int r, int c, unsigned long now);
        bool CheckIsActive(int c);
        bool CheckIsActive(int r, int c);
        void OnKeyActive(int r, int c, unsigned long now);
        void OnKeyInactive(int r, int c, unsigned long now);

        void OnKeyPressed(int r, int c);
        void OnKeyHeld(int r, int c);
        void OnKeyReleased(int r, int c);

        void DoKeyTap(Key &key, const Record &re, int r, int c, int layer);
        void DoKeyRelease(Key &key, const Record &re, int r, int c, int layer);
    };
}
