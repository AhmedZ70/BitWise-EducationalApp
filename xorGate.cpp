#include "xorGate.h"

void XorGate:: setInput(bool firstValue, bool secondValue){
        input1 = firstValue;
        input2 = secondValue;
    }

bool XorGate:: computeOutput(){
        output = input1 != input2;
        return output;
    }

bool XorGate:: getOutput() const{
        return output;
    }
