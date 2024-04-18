#include "levelNine.h"
#include "gate.h"
LevelNine::LevelNine() : firstBit(false), secondBit(false), thirdBit(false) {}

void LevelNine::setInput(std:: vector<bool> inputs) {
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
    fourthBit = inputs.at(3);
}

void LevelNine::computeOutput() {
    Gate gate1 = setGate(userGateSelected1);
    Gate gate2 = setGate(userGateSelected2);
    Gate gate3 = setGate(userGateSelected3);

    gate1.setInput(firstBit, thirdBit);
    bool firstResult = gate1.computeOutput();

    gate2.setInput(secondBit, fourthBit);
    bool secondResult = gate2.computeOutput();

    gate3.setInput(firstResult, secondResult);
    bool finalResult = gate3.computeOutput();

    result = finalResult;
}

void LevelNine::setUserGateSelected1(string gateSelected)
{
    userGateSelected1 = gateSelected;
}

void LevelNine::setUserGateSelected2(string gateSelected)
{
    userGateSelected2 = gateSelected;
}

void LevelNine::setUserGateSelected3(string gateSelected)
{
    userGateSelected3 = gateSelected;
}



