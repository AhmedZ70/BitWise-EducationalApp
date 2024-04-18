#include "levelFour.h"

LevelFour::LevelFour() : inputA(false), inputB(false){}

void LevelFour::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelFour::computeOutput() {
    Gate norGate = setGate("NOR");
    norGate.setInput(inputA, inputB);
    result = norGate.computeOutput();
}


