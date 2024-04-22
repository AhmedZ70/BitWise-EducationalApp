#include "levelTwelve.h"

LevelTwelve::LevelTwelve() : firstBit(false), secondBit(false), thirdBit(false), fourthBit(false),
    fifthBit(false), sixthBit(false), seventhBit(false), eighthBit(false) {}

void LevelTwelve::setInput(std:: vector<bool> inputs) {
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
    fourthBit = inputs.at(3);
    fifthBit = inputs.at(4);
    sixthBit = inputs.at(5);
    seventhBit = inputs.at(6);
    eighthBit = inputs.at(7);
}

void LevelTwelve::computeOutput() {
    Gate gate1 = setGate(userGateSelected1);
    Gate gate2 = setGate(userGateSelected2);
    Gate gate3 = setGate(userGateSelected3);
    Gate gate4 = setGate(userGateSelected4);
    Gate gate5 = setGate(userGateSelected5);
    Gate gate6 = setGate(userGateSelected6);
    Gate gate7 = setGate(userGateSelected7);

    gate1.setInput(firstBit, secondBit);
    bool firstResult = gate1.computeOutput();

    gate2.setInput(thirdBit, fourthBit);
    bool secondResult = gate2.computeOutput();

    gate3.setInput(fifthBit, sixthBit);
    bool thirdResult = gate3.computeOutput();

    gate4.setInput(seventhBit, eighthBit);
    bool fourthResult = gate4.computeOutput();

    gate5.setInput(firstResult, secondResult);
    bool fifthResult = gate5.computeOutput();

    gate6.setInput(thirdResult, fourthResult);
    bool sixthResult = gate6.computeOutput();

    gate7.setInput(fifthResult, sixthResult);
    bool finalResult = gate7.computeOutput();

    result = finalResult;
}

void LevelTwelve::setGateTypes(const std::vector<std::string>& gateTypes){
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);
    userGateSelected3 = gateTypes.at(2);
    userGateSelected4 = gateTypes.at(3);
    userGateSelected5 = gateTypes.at(4);
    userGateSelected6 = gateTypes.at(5);
    userGateSelected7 = gateTypes.at(6);
}



