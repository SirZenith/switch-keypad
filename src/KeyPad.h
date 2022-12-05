#pragma once

#include <Arduino.h>
#include <SwitchController.h>

#include "LayeringState.h"
#include "MacroRecorder.h"
#include "common.h"

namespace keypad {
    class KeyPad {
    public:
        KeyPad(
            int row, int col, int layer,
            int *rowPinList, int *colPinList,
            const Record **keyMap, const MacroRecord **macroList,
            unsigned long debounce, unsigned long holdThreshold,
            unsigned long clickDelay, unsigned long clickEndDelay
        );
        ~KeyPad();
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

        Key **keyMatrix;

        LayeringState layeringState;

        MacroTarget curMacro;
        MacroRecorder recorder;

        bool isDirty = false;

        void OperationLog(const char *msg, const MacroRecord *re = nullptr);

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
