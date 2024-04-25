#include "levelEight.h"
#include "gate.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelEight cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelEight h file.
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
    Gate firstGate = setGate(userGateSelected1);
    Gate secondGate = setGate(userGateSelected2);
    Gate thirdGate = setGate(userGateSelected3);

    // Sets gate and gets inputs from user while calculating outputs of the gates
    firstGate.setInput(firstBit, secondBit);
    bool firstResult = firstGate.computeOutput();

    secondGate.setInput(thirdBit, fourthBit);
    bool secondResult = secondGate.computeOutput();

    thirdGate.setInput(firstResult, secondResult);
    bool finalResult = thirdGate.computeOutput();

    // Final output of the circuit
    result = finalResult;
}

void LevelEight::setGateTypes(const std::vector<std::string>& gateTypes){
    // Sets the user gate type drag and drop assignment
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);
    userGateSelected3 = gateTypes.at(2);
}


