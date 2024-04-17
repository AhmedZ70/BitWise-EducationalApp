#include "levelFive.h"

LevelFive::LevelFive() : inputA(false), inputB(false), result(false) {}

void LevelFive::setInput(bool a, bool b) {
    inputA = a;
    inputB = b;
}

void LevelFive::computeOutput() {

    xorGate.setInput(inputA, inputB);

    result = xorGate.computeOutput();
}

bool LevelFive::getResult() const {
    return result;
}

