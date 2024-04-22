#include "levelSix.h"
#include <iostream>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelSix cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelSix h file.
*/
LevelSix::LevelSix() : inputA(false), inputB(false){}

void LevelSix::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelSix::computeOutput() {
    Gate userGate = setGate(userGateSelected);
    userGate.setInput(inputA, inputB);
    bool firstResult = userGate.computeOutput();
    Gate notGate = setGate("NOT");
    notGate.setInput(firstResult);
    bool finalResult = notGate.computeOutput();
    result = finalResult;
}

void LevelSix::setGateTypes(const std::vector<std::string>& gateTypes){
    userGateSelected = gateTypes.at(0);
}
