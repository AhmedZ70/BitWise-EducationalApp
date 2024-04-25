#include "circuitLevel.h"
#include <functional>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name circuitLevel cpp file for assignment9
 * This cpp file contains the method definitions for use within the circuit level class for use for levels.
*/
void CircuitLevel::setInput(vector<bool>inputs) {}

void CircuitLevel::computeOutput() {}

bool CircuitLevel::getResult() const {
    return result;
}

void CircuitLevel::setGateTypes(const std::vector<std::string>&){}

Gate CircuitLevel::setGate(string gateType)
{
    function<bool(bool, bool)> gateFunction;
    function<bool(bool)> notGateFunction;

    // Logic to determine which gate to set from the user selected vector.
    if (gateType == "XOR") {
        gateFunction = [](bool a, bool b) { return a ^ b; };
        return Gate(gateFunction);
    }
    else if (gateType == "NOR") {
        gateFunction = [](bool a, bool b) { return !(a || b); };
        return Gate(gateFunction);
    }
    else if (gateType == "AND") {
        gateFunction = [](bool a, bool b) { return a && b; };
        return Gate(gateFunction);
    }
    else if (gateType == "NAND") {
        gateFunction = [](bool a, bool b) { return !(a && b); };
        return Gate(gateFunction);
    }
    else if (gateType == "OR"){
        gateFunction = [](bool a, bool b) { return a || b; };
        return Gate(gateFunction);
    }
    else if (gateType == "NOT")
    {
        notGateFunction = [](bool a) { return !a; };
        return Gate(notGateFunction);
    }
    else{
        //invalid gate
        return Gate();
    }
}

bool CircuitLevel::correctUserGate(string givenGate)
{
    return givenGate == expectedGate;

}

CircuitLevel::~CircuitLevel() {};


