#include "levelone.h"
#include "gate.h"

LevelOne::LevelOne() : inputA(false), inputB(false)
{
    expectedGate = "AND";
}

void LevelOne::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelOne::computeOutput() {
    Gate andGate = setGate("AND");
    andGate.setInput(inputA, inputB);
    result = andGate.computeOutput();
}

bool LevelOne:: checkCorrectGate(string userGate)
{
    return correctUserGate(userGate);
}


