#include "levelSeven.h"
#include "gate.h"
LevelSeven::LevelSeven() : firstBit(false), secondBit(false), thirdBit(false) {}

void LevelSeven::setInput(std:: vector<bool> inputs) {
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
}

void LevelSeven::computeOutput() {
    Gate andGate = setGate("AND");
    Gate secondGate = setGate(userGateSelected);

    andGate.setInput(firstBit, secondBit);
    bool firstResult = andGate.computeOutput();
    secondGate.setInput(firstResult, thirdBit);
    bool finalResult = andGate.computeOutput();
    result = finalResult;

}

void LevelSeven::setUserGateSelected(string gateSelected)
{
    userGateSelected = gateSelected;
}



