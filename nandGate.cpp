#include "nandGate.h"

void NandGate::setInput(bool firstValue, bool secondValue){
        input1 = firstValue;
        input2 = secondValue;
    }

bool NandGate::computeOutput(){
        output = !(input1 && input2);
        return output;
    }

bool NandGate::getOutput() const {
        return output;
    }

