#include "levelFive.h"

LevelFive::LevelFive() : inputA(false), inputB(false), result(false) {}

void LevelFive::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelFive::computeOutput() {

    xorGate.setInput(inputA, inputB);

    result = xorGate.computeOutput();
}



