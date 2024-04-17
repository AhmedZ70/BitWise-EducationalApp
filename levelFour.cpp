#include "levelFour.h"

LevelFour::LevelFour() : inputA(false), inputB(false), result(false) {}

void LevelFour::setInput(bool a, bool b) {
    inputA = a;
    inputB = b;
}

void LevelFour::computeOutput() {

    norGate.setInput(inputA, inputB);

    result = norGate.computeOutput();
}

bool LevelFour::getResult() const {
    return result;
}

