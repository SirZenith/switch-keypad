#pragma once

#include <Arduino.h>
#include <SwitchControlLibrary.h>

namespace keypad {
    enum Operation {
        EMPTY,
        DELAY,
        MACRO,
        END,
        BTN,
        HAT,
        HAT_BTN
    };

    struct Record {
        Operation type;
        int param;
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
        int updatetime = 0;
    };

    class KeyPad {
    public:
        KeyPad(
            int row, int col, int layer,
            int *rowPinList, int *colPinList,
            Record **keyMap, Record **macroList,
            int debounce, int holdThreshold,
            int clickDelay, int keyEndDelay
        );
        ~KeyPad();
        void Scan();
        void Send();
        void PlayMacro();

    private:
        int row, col, layer;
        int *rowPinList, *colPinList;
        Record **keyMap, **macroList;
        int debounce, holdThreshold, clickDelay, keyEndDelay;
        Key **keyMatrix;
        bool isScanning = false;
        int curLayer = 0;
        MacroRecord curMacro;

        bool CheckIsActive(int c);
        bool CheckIsActive(int r, int c);
        void OnKeyActive(int r, int c, int now);
        void OnKeyInactive(int r, int c, int now);

        void OnKeyPressed(int r, int c);
        void OnKeyHeld(int r, int c);
        void OnKeyReleased(int r, int c);

        void PressKey(uint16_t button);
        void PressHat(uint8_t button);
    };

}
