#pragma once

#include "common.h"

namespace keypad {
    class KeyHandler {
    public:
        KeyHandler(
            const Record **keymap,
            const MacroRecord **macroList,
            unsigned int defaultLayer
        ) : keymap{keymap},
            macroList{macroList},
            defaultLayer{defaultLayer} {

            layerCnt = 0;
            for (; keymap[layerCnt] != nullptr; ++layerCnt) {
            }

            macroCnt = 0;
            for (; macroList[macroCnt] != nullptr; ++macroCnt) {
            }
        }

        virtual void Begin() = 0;
        virtual void End() = 0;

        virtual bool Ready() = 0;
        virtual bool Dirty() = 0;

        unsigned int LayerCnt() { return layerCnt; }
        unsigned int DefaultLayer() { return defaultLayer; }

        virtual void Send() = 0;

        virtual void Press(unsigned long param) = 0;
        virtual void Release(unsigned long param) = 0;
        virtual void ReleaseAll() = 0;

        virtual const char *Name() = 0;
        virtual void OperationLog(const char *msg, const MacroRecord *re) = 0;

        const Record &GetRecord(int layer, int index) {
            return keymap[layer][index];
        }

        const MacroRecord *GetMacro(int index) {
            return index >= 0 && index < macroCnt ? macroList[index] : nullptr;
        }

    protected:
        const Record **keymap = nullptr;
        const MacroRecord **macroList = nullptr;

        unsigned int layerCnt = 0;
        unsigned int defaultLayer = 0;

        unsigned int macroCnt = 0;
    };
}
