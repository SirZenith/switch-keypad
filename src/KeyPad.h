#pragma once

#include <Arduino.h>
#include <SwitchController.h>

#include "LayeringState.h"
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
            int row, int col, int layer,
            int *rowPinList, int *colPinList,
            const Record **keyMap, const MacroRecord **macroList,
            unsigned long debounce, unsigned long holdThreshold,
            unsigned long clickDelay, unsigned long clickEndDelay
        );
        ~KeyPad();

        void SetLEDPin(int red, int orange, int yellow, int blue);
        void Begin();
        void End();
        bool Ready();
        void Scan();
        void Send();
        void PlayMacro();

    private:
        struct MacroTarget {
            bool isPlaying = false;
            const MacroRecord *macro = nullptr;
            int row, col;

            bool CheckHasMacroBinded();
            bool CheckIsMacroPlaying();

            void ToggleMacro(const MacroRecord *macro, int r, int c);
            void UpdateMacroBinding(const MacroRecord **macroList, int index, int r, int c);
            void Unbind();
        };

        int row, col;
        int *rowPinList, *colPinList;
        const Record **keyMap;
        const MacroRecord **macroList;
        unsigned long debounce, holdThreshold, clickDelay, clickEndDelay;

        unsigned long lastLEDUpdateTime = 0;

        int redLEDPin = NO_LED_PIN, redLEDState = LOW;
        int orangeLEDPin = NO_LED_PIN, orangeLEDState = LOW;
        int yellowLEDPin = NO_LED_PIN, yellowLEDState = LOW;
        int blueLEDPin = NO_LED_PIN, blueLEDState = LOW;

        Key **keyMatrix;

        LayeringState layeringState;

        MacroTarget curMacro;
        MacroRecorder recorder;

        bool isDirty = false;

        void OperationLog(const char *msg, const MacroRecord *re = nullptr);
        void UpdateLEDState();

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
