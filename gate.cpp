#include "Gate.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name Gate cpp file for assignment9
 * This cpp file implements the methods defined in the Gate class which computes logic gate functionalities.
 */
Gate::Gate(function<bool(bool, bool)> func)
    : gateFunction(func), isNotGate(false) {
}

Gate::Gate(function<bool(bool)> func)
    : notGateFunction(func), isNotGate(true) {
}
Gate::Gate(){

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
