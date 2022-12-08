#pragma once

#include <Arduino.h>

#include "KeyHandler.h"
#include "LayeringState.h"
#include "MacroPlayer.h"
#include "MacroRecorder.h"
#include "common.h"

namespace keypad {
    class KeyPad {
    public:
        static const int NO_LED_PIN = -1;
        static const unsigned long MIN_LED_UPDATE_STEP = 100;
        static const unsigned long BLINK_TIME = 1000;
        static const unsigned long FAST_BLINK_TIME = 500;
        static const unsigned long SUPER_FAST_BLINK_TIME = 250;

        KeyPad(
            int row, int col,
            int *rowPinList, int *colPinList,
            unsigned long debounce, unsigned long holdThreshold,

            const Record **keyMap,
            MacroPlayer &macroPlayer,
            KeyHandler **handlers
        );
        ~KeyPad();

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

        const Record **keyMap;

        Key **keyMatrix;
        LayeringState layeringState;
        MacroRecorder recorder;

        MacroPlayer &macroPlayer;

        int handlerCnt = 0;
        KeyHandler **handlers = nullptr;
        KeyHandler *handler = nullptr;

        unsigned long lastLEDUpdateTime = 0;

        int redLEDPin = NO_LED_PIN, redLEDState = LOW;
        int orangeLEDPin = NO_LED_PIN, orangeLEDState = LOW;
        int yellowLEDPin = NO_LED_PIN, yellowLEDState = LOW;
        int blueLEDPin = NO_LED_PIN, blueLEDState = LOW;

        int changeHandlerLEDBlinkCnt = 0;

        void OperationLog(const char *msg, const MacroRecord *re = nullptr);
        void UpdateLED(int pin, int value);

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
