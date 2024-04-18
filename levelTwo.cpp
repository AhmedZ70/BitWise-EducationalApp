#include "levelTwo.h"

LevelTwo::LevelTwo() : inputA(false), inputB(false), result(false) {}

void LevelTwo::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelTwo::computeOutput() {

    orGate.setInput(inputA, inputB);

    result = orGate.computeOutput();
}



