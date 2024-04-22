#include "circuitLevel.h"
#include <functional>
#include <iostream>
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
    cout << expectedGate << endl;
    return givenGate == expectedGate;

}

CircuitLevel::~CircuitLevel() {};


