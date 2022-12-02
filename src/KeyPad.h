#pragma once

#include "LayeringState.h"
#include "common.h"
#include <Arduino.h>
#include <SwitchControlLibrary.h>

namespace keypad {
    struct MacroRecord {
        static const int NO_MACRO = -1;

        bool isPlaying = false;
        int index = NO_MACRO;
        int row, col;
    };
    class KeyPad {
    public:
        KeyPad(
            int row, int col, int layer,
            int *rowPinList, int *colPinList,
            const Record **keyMap, const Record **macroList,
            unsigned long debounce, unsigned long holdThreshold,
            unsigned long clickDelay, unsigned long keyEndDelay
        );
        ~KeyPad();
        void Scan();
        void Send();
        void PlayMacro();

    private:
        int row, col;
        int *rowPinList, *colPinList;
        const Record **keyMap, **macroList;
        unsigned long debounce, holdThreshold, clickDelay, keyEndDelay;

        Key **keyMatrix;

        LayeringState layeringState;

        MacroRecord curMacro;

        void OperationLog(const char *msg, const Record *re = nullptr);

        bool CheckIsMacroPlaying();
        bool DebounceCheck(int r, int c, unsigned long now);
        bool CheckIsActive(int c);
        bool CheckIsActive(int r, int c);
        void OnKeyActive(int r, int c, unsigned long now);
        void OnKeyInactive(int r, int c, unsigned long now);

        void OnKeyPressed(int r, int c);
        void OnKeyHeld(int r, int c);
        void OnKeyReleased(int r, int c);

        void TapTheKey(Key &key, const Record &re, int r, int c, int layer);
        void ReleaseTheKey(Key &key, const Record &re, int r, int c, int layer);

        void SimPressKey(uint16_t button);
        void SimPressHat(uint8_t button);
    };
}
