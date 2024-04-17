#include "levelTwo.h"

LevelTwo::LevelTwo() : inputA(false), inputB(false), result(false) {}

void LevelTwo::setInput(bool a, bool b) {
    inputA = a;
    inputB = b;
}

void LevelTwo::computeOutput() {

    orGate.setInput(inputA, inputB);

    result = orGate.computeOutput();
}

bool LevelTwo::getResult() const {
    return result;
}

