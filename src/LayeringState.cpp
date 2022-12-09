#include "LayeringState.h"

keypad::LayeringState::LayeringState() : layerCnt{MAX_LAYER_CNT} {}

int keypad::LayeringState::GetLayerCnt() {
    return layerCnt;
}

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
    defaultLayer = layer >= 0 && layer < MAX_LAYER_CNT ? layer : defaultLayer;
    UpdateCurLayer();
    OperationLog("set-default", defaultLayer);
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
    unsigned long mask = 1UL << layer;
    if (!(layerStateRecord & mask)) {
        layerStateRecord |= mask;
        UpdateCurLayer();
    }
}

void keypad::LayeringState::DeactivateLayer(int layer) {
    OperationLog("leave", layer);

    unsigned long mask = 1UL << layer;
    if (layerStateRecord & mask) {
        layerStateRecord &= ~mask;
        UpdateCurLayer();
    }
}

void keypad::LayeringState::ToggleLayer(int layer) {
    OperationLog("toggle", layer);

    layerStateRecord ^= 1UL << layer;
    UpdateCurLayer();
}

// ----------------------------------------------------------------------------

void keypad::LayeringState::OneShotLayerOn(int layer) {
    OperationLog("onshot-on", layer);

    ActivateLayer(layer);
    oneShotLayer = layer;
    UpdateCurLayer();
}

void keypad::LayeringState::OneShotLayerOff() {
    OperationLog("oneshot-off", NO_LAYER);

    DeactivateLayer(oneShotLayer);
    oneShotLayer = NO_LAYER;
    UpdateCurLayer();
}

// ----------------------------------------------------------------------------

void keypad::LayeringState::OperationLog(const char *msg, unsigned long param) {
#ifdef DEBUG
    Serial.print(msg);
    if (param != NO_LAYER) {
        Serial.print("(");
        Serial.print(param);
        Serial.print(")");
    }
    Serial.print("\n");
#endif
}

void keypad::LayeringState::UpdateCurLayer() {
    curLayer = defaultLayer;
#ifdef DEBUG
    bool isDirty = false;
#endif

    unsigned long value = layerStateRecord << (MAX_LAYER_CNT - layerCnt);
    for (int l = layerCnt - 1; l >= 0; --l, value <<= 1) {
        if (value & LAYER_CHECK_MASK) {
            OperationLog("update-layer", l);

            curLayer = l;
#ifdef DEBUG
            isDirty = true;
#endif
            break;
        }
    }

#ifdef DEBUG
    if (!isDirty) {
        OperationLog("to-default", NO_LAYER);
    }
#endif
}
