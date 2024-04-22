#include "levelTen.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelTen cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelTen h file.
*/
LevelTen::LevelTen() : firstBit(false), secondBit(false), thirdBit(false),
    fourthBit(false), fifthBit(false), sixthBit(false) {}

void LevelTen::setInput(std:: vector<bool> inputs) {
    // Sets the user input
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
    fourthBit = inputs.at(3);
    fifthBit = inputs.at(4);
    sixthBit = inputs.at(5);
}

void LevelTen::computeOutput() {
    // Create gate objects for the gates on the circuit
    Gate gate1 = setGate(userGateSelected1);
    Gate gate2 = setGate(userGateSelected2);
    Gate gate3 = setGate(userGateSelected3);
    Gate gate4 = setGate(userGateSelected4);
    Gate gate5 = setGate(userGateSelected5);
    Gate notGate = setGate("NOT");

    // Sets gate and gets inputs from user while calculating outputs of the gates
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

    // Final output of the circuit
    result = finalResult;
}

void LevelTen::setGateTypes(const std::vector<std::string>& gateTypes){
    // Sets the user gate type drag and drop assignment
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);
    userGateSelected3 = gateTypes.at(2);
    userGateSelected4 = gateTypes.at(3);
    userGateSelected5 = gateTypes.at(4);
}



