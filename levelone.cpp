#include "levelone.h"

LevelOne::LevelOne() : inputA(false), inputB(false), result(false) {}

void LevelOne::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelOne::computeOutput() {

    andGate.setInput(inputA, inputB);
    result = andGate.computeOutput();
}


