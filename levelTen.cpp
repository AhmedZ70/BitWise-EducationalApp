#include "levelTen.h"

LevelTen::LevelTen() : firstBit(false), secondBit(false), thirdBit(false),
    fourthBit(false), fifthBit(false), sixthBit(false) {}

void LevelTen::setInput(std:: vector<bool> inputs) {
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
    fourthBit = inputs.at(3);
    fifthBit = inputs.at(4);
    sixthBit = inputs.at(5);
}

void LevelTen::computeOutput() {
    Gate gate1 = setGate(userGateSelected1);
    Gate gate2 = setGate(userGateSelected2);
    Gate gate3 = setGate(userGateSelected3);
    Gate gate4 = setGate(userGateSelected4);
    Gate gate5 = setGate(userGateSelected5);
    Gate notGate = setGate("NOT");

    gate1.setInput(firstBit, secondBit);
    bool firstResult = gate1.computeOutput();

    gate2.setInput(thirdBit, fourthBit);
    bool secondResult = gate2.computeOutput();

    notGate.setInput(sixthBit);
    bool notResult = notGate.computeOutput();

    gate3.setInput(fifthBit, notResult);
    bool thirdResult = gate3.computeOutput();

    gate4.setInput(firstResult, secondResult);
    bool fourthResult = gate4.computeOutput();

    gate5.setInput(thirdResult, fourthResult);
    bool finalResult = gate5.computeOutput();

    result = finalResult;
}

void LevelTen::setGateTypes(const std::vector<std::string>& gateTypes){
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);
    userGateSelected3 = gateTypes.at(2);
    userGateSelected4 = gateTypes.at(3);
    userGateSelected5 = gateTypes.at(4);
}



