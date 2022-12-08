#pragma once

#include <Arduino.h>
#include <limits.h>

namespace keypad {
    class LayeringState {
    public:
        static const int MAX_LAYER_CNT = sizeof(unsigned long) * CHAR_BIT;
        static const int NO_LAYER = -1;

        LayeringState();

        int GetLayerCnt();
        int SetLayerCnt(int cnt);
        int SetDefaultLayer(int layer);
        int GetCurLayer();
        bool IsInOneShotState();

        void ActivateLayer(int layer);
        void DeactivateLayer(int layer);
        void ToggleLayer(int layer);

        void OneShotLayerOn(int layer);
        void OneShotLayerOff();

    private:
        // top bit mask
        static constexpr unsigned long LAYER_CHECK_MASK = ~(ULONG_MAX >> 1);

        unsigned long layerStateRecord = 0;
        int defaultLayer = 0;
        int layerCnt = 0;
        int curLayer = 0;
        int oneShotLayer = NO_LAYER;

        void OperationLog(const char *msg, unsigned long param);
        void UpdateCurLayer();
    };
}
