#include "Gate.h"

Gate::Gate(function<bool(bool, bool)> func)
    : gateFunction(func), isNotGate(false) {
}

Gate::Gate(function<bool(bool)> func)
    : notGateFunction(func), isNotGate(true) {
}

// Set inputs for the gate
void Gate::setInput(bool firstValue, bool secondValue) {
    if (!isNotGate) {
        firstInput = firstValue;
        secondInput = secondValue;
    }
    else {

        firstInput = firstValue;

    }
}

void Gate::setInput(bool firstValue)
{
    firstInput = firstValue;
    secondInput = false;
}

bool Gate::computeOutput() {
    if (isNotGate) {
        output = notGateFunction(firstInput);
    }
    else {
        output = gateFunction(firstInput, secondInput);
    }
    return output;
}


bool Gate::getOutput() {
    return output;
}
