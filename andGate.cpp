#include "andGate.h"

void AndGate::setInput(bool firstValue, bool secondValue){
        input1 = firstValue;
        input2 = secondValue;
    }

bool AndGate:: computeOutput(){
        output = input1 && input2;
        return output;
    }

bool AndGate::getOutput() const {
        return output;
    }
