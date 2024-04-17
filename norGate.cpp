#include "norGate.h"



void NorGate::setInput(bool firstValue, bool secondValue) {
        input1 = firstValue;
        input2 = secondValue;
    }

bool NorGate::computeOutput() {
        output = !(input1 || input2);
        return output;
    }

bool NorGate::getOutput() const{
        return output;
    }

