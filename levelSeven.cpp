#include "levelSeven.h"
#include "gate.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelSeven cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelSeven h file.
*/
LevelSeven::LevelSeven() : firstBit(false), secondBit(false), thirdBit(false) {}

void LevelSeven::setInput(std:: vector<bool> inputs) {
    // Sets the user input
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
}

void LevelSeven::computeOutput() {
    // Create gate objects for the gates on the circuit
    Gate firstGate = setGate(userGateSelected1);
    Gate secondGate = setGate(userGateSelected2);

    // Sets gate and gets inputs from user while calculating outputs of the gates
    firstGate.setInput(firstBit, secondBit);
    bool firstResult = firstGate.computeOutput();
    secondGate.setInput(firstResult, thirdBit);
    bool finalResult = secondGate.computeOutput();

    // Final output of the circuit
    result = finalResult;
}

void LevelSeven::setGateTypes(const std::vector<std::string>& gateTypes){
    // Sets the user gate type drag and drop assignment
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);

}


