#include "levelone.h"

LevelOne::LevelOne() : inputA(false), inputB(false), result(false) {}

void LevelOne::setInput(bool a, bool b) {
    inputA = a;
    inputB = b;
}

void LevelOne::computeOutput() {

    andGate.setInput(inputA, inputB);
    result = andGate.computeOutput();
}

bool LevelOne::getResult() const {
    return result;
}

