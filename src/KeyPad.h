#pragma once

#include "LayeringState.h"
#include <Arduino.h>
#include <SwitchControlLibrary.h>

namespace keypad {
    enum Operation {
        EMPTY,
        DELAY,
        MACRO,
        END,
        // --------------------------------------------------------------------
        MOMENT_LAYER,
        ONE_SHOT_LAYER,
        TOGGLE_LAYER,
        DEFAULT_LAYER,
        // --------------------------------------------------------------------
        BTN,
        HAT,
        HAT_BTN
    };

    struct Record {
        Operation type;
        unsigned long param;
    };

    struct MacroRecord {
        static const int NO_MACRO = -1;

        bool isPlaying = false;
        int index = NO_MACRO;
        int row, col;
    };

    struct Key {
        enum State {
            TRIGGERED,
            PRESSED,
            HELD,
            RELEASED,
        };

        State state = State::RELEASED;
        unsigned long updatetime = 0;
    };

    class KeyPad {
    public:
        KeyPad(
            int row, int col, int layer,
            int *rowPinList, int *colPinList,
            Record **keyMap, Record **macroList,
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
        Record **keyMap, **macroList;

        unsigned long debounce, holdThreshold, clickDelay, keyEndDelay;

        Key **keyMatrix;
        bool isScanning = false;

        LayeringState layeringState;

        MacroRecord curMacro;

        void OperationLog(const char *prefix, Record *re = nullptr);

        bool CheckIsActive(int c);
        bool CheckIsActive(int r, int c);
        void OnKeyActive(int r, int c, unsigned long now);
        void OnKeyInactive(int r, int c, unsigned long now);

        void OnKeyPressed(int r, int c);
        void OnKeyHeld(int r, int c);
        void OnKeyReleased(int r, int c);

        void SimPressKey(uint16_t button);
        void SimPressHat(uint8_t button);
    };
}
