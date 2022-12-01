#include "LayeringState.h"

int keypad::LayeringState::SetLayerCnt(int cnt) {
    if (cnt <= 0) {
        layerCnt = 1;
    } else if (cnt > MAX_LAYER_CNT) {
        layerCnt = MAX_LAYER_CNT;
    } else {
        layerCnt = cnt;
    }

    return layerCnt;
}

int keypad::LayeringState::SetDefaultLayer(int layer) {
    if (layer <= 0) {
        defaultLayer = 1;
    } else if (layer > MAX_LAYER_CNT) {
        defaultLayer = MAX_LAYER_CNT;
    } else {
        defaultLayer = layer;
    }

    return defaultLayer;
}

int keypad::LayeringState::GetCurLayer() {
    return curLayer;
}

bool keypad::LayeringState::IsInOneShotState() {
    return oneShotLayer != NO_LAYER;
}

// ----------------------------------------------------------------------------

void keypad::LayeringState::ActivateLayer(int layer) {
    unsigned long mask = 1 << layer;
    if (layerStateRecord & mask == 0) {
        layerStateRecord |= mask;
        UpdateCurLayer();
    }
}

void keypad::LayeringState::DeactivateLayer(int layer) {
    unsigned long mask = 1 << layer;
    if (layerStateRecord & mask == 1) {
        layerStateRecord &= ~mask;
        UpdateCurLayer();
    }
}

void keypad::LayeringState::ToggleLayer(int layer) {
    layerStateRecord ^= 1UL << layer;
    UpdateCurLayer();
}

// ----------------------------------------------------------------------------

void keypad::LayeringState::OneShotLayerOn(int layer) {
    ActivateLayer(layer);
    oneShotLayer = layer;
    UpdateCurLayer();
}

void keypad::LayeringState::OneShotLayerOff() {
    DeactivateLayer(oneShotLayer);
    oneShotLayer = NO_LAYER;
    UpdateCurLayer();
}

// ----------------------------------------------------------------------------

void keypad::LayeringState::UpdateCurLayer() {
    curLayer = defaultLayer;

    unsigned long value = layerStateRecord << (MAX_LAYER_CNT - layerCnt);
    for (int l = layerCnt - 1; l >= 0; --l, value <<= 1) {
        if (value & LAYER_CHECK_MASK) {
            curLayer = l;
            break;
        }
    }
}
