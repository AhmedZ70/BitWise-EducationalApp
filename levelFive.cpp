#include "levelFive.h"

LevelFive::LevelFive() : inputA(false), inputB(false)
{
    expectedGate = "XOR";
}

void LevelFive::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelFive::computeOutput() {
    Gate xorGate = setGate("XOR");
    xorGate.setInput(inputA, inputB);
    result = xorGate.computeOutput();
}



