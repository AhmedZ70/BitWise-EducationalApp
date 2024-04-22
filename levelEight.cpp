#include "levelEight.h"
#include "gate.h"
LevelEight::LevelEight() : firstBit(false), secondBit(false), thirdBit(false), fourthBit(false) {}

void LevelEight::setInput(std:: vector<bool> inputs) {
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
    fourthBit = inputs.at(3);
}

void LevelEight::computeOutput() {
    Gate gate1 = setGate(userGateSelected1);
    Gate gate2 = setGate(userGateSelected2);
    Gate gate3 = setGate(userGateSelected3);

    gate1.setInput(firstBit, secondBit);
    bool firstResult = gate1.computeOutput();

    gate2.setInput(thirdBit, fourthBit);
    bool secondResult = gate2.computeOutput();

    gate3.setInput(firstResult, secondResult);
    bool finalResult = gate3.computeOutput();

    result = finalResult;
}

void LevelEight::setGateTypes(const std::vector<std::string>& gateTypes){
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);
    userGateSelected3 = gateTypes.at(2);
}

// void LevelEight::setUserGateSelected1(string gateSelected)
// {
//     userGateSelected1 = gateSelected;
// }

// void LevelEight::setUserGateSelected2(string gateSelected)
// {
//     userGateSelected2 = gateSelected;
// }

// void LevelEight::setUserGateSelected3(string gateSelected)
// {
//     userGateSelected3 = gateSelected;
// }



