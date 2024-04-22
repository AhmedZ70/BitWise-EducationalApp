#include "levelSeven.h"
#include "gate.h"
LevelSeven::LevelSeven() : firstBit(false), secondBit(false), thirdBit(false) {}

void LevelSeven::setInput(std:: vector<bool> inputs) {
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
}

void LevelSeven::computeOutput() {
    Gate firstGate = setGate(userGateSelected1);
    Gate secondGate = setGate(userGateSelected2);

    firstGate.setInput(firstBit, secondBit);
    bool firstResult = firstGate.computeOutput();
    secondGate.setInput(firstResult, thirdBit);
    bool finalResult = secondGate.computeOutput();
    result = finalResult;

}

void LevelSeven::setGateTypes(const std::vector<std::string>& gateTypes){
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);

}


