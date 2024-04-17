#include "orGate.h"

void OrGate:: setInput(bool firstValue, bool secondValue) {
        input1 = firstValue;
        input2 = secondValue;
    }

bool OrGate::computeOutput(){
        output = input1 || input2;
        return output;
    }

bool OrGate:: getOutput() const{
        return output;
    }


