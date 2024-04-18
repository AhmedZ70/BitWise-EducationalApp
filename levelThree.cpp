#include "levelThree.h"

LevelThree::LevelThree() : inputA(false), inputB(false), result(false) {}

void LevelThree::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelThree::computeOutput() {

    nandGate.setInput(inputA, inputB);

    result = nandGate.computeOutput();
}


