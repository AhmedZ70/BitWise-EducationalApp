#include "levelEight.h"
#include "gate.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelSeven cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelSeven h file.
*/
LevelEight::LevelEight() : firstBit(false), secondBit(false), thirdBit(false), fourthBit(false) {}

void LevelEight::setInput(std:: vector<bool> inputs) {
    // Sets the user input
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
    fourthBit = inputs.at(3);
}

void LevelEight::computeOutput() {
    // Create gate objects for the gates on the circuit
    Gate gate1 = setGate(userGateSelected1);
    Gate gate2 = setGate(userGateSelected2);
    Gate gate3 = setGate(userGateSelected3);

    // Sets gate and gets inputs from user while calculating outputs of the gates
    gate1.setInput(firstBit, secondBit);
    bool firstResult = gate1.computeOutput();

    gate2.setInput(thirdBit, fourthBit);
    bool secondResult = gate2.computeOutput();

    gate3.setInput(firstResult, secondResult);
    bool finalResult = gate3.computeOutput();

    // Final output of the circuit
    result = finalResult;
}

void LevelEight::setGateTypes(const std::vector<std::string>& gateTypes){
    // Sets the user gate type drag and drop assignment
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);
    userGateSelected3 = gateTypes.at(2);
}


