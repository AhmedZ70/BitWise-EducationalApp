#include "levelThree.h"

LevelThree::LevelThree() : inputA(false), inputB(false), result(false) {}

void LevelThree::setInput(bool a, bool b) {
    inputA = a;
    inputB = b;
}

void LevelThree::computeOutput() {

    nandGate.setInput(inputA, inputB);

    result = nandGate.computeOutput();
}

bool LevelThree::getResult() const {
    return result;
}

