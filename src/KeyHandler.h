#pragma once

#include "common.h"

namespace keypad {
    class KeyHandler {
    public:
        KeyHandler(unsigned int defaultLayer) : defaultLayer{defaultLayer} {}

        virtual void Begin() = 0;
        virtual void End() = 0;

        virtual bool Ready() = 0;
        virtual bool Dirty() = 0;
        virtual unsigned int DefaultLayer() { return defaultLayer; }

        virtual void Send() = 0;

        virtual void Press(unsigned long param) = 0;
        virtual void Release(unsigned long param) = 0;

        virtual void OperationLog(const char *msg, const MacroRecord *re) = 0;
    protected:
        unsigned int defaultLayer = 0;
    };
}
