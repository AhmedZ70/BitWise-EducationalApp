#include "circuitLevel.h"
#include <functional>
void CircuitLevel::setInput(vector<bool>inputs) {}

void CircuitLevel::computeOutput() {}

bool CircuitLevel::getResult() const {
    return result;
}


Gate CircuitLevel::setGate(string gateType)
{
    function<bool(bool, bool)> gateFunction;

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
    else {
        gateFunction = [](bool a, bool b) { return a || b; };
        return Gate(gateFunction);
    }
}

CircuitLevel::~CircuitLevel() {};


