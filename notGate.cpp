#include "notGate.h"



void NotGate::setInput(bool firstValue, bool secondValue){
        input = firstValue;
    }

bool NotGate::computeOutput() {
        output = !input;
        return output;
    }

bool NotGate::getOutput() const {
        return output;
}
