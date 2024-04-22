#include "levelEleven.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelEleven cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelEleven h file.
*/
LevelEleven::LevelEleven() : firstBit(false), secondBit(false), thirdBit(false),
    fourthBit(false), fifthBit(false), sixthBit(false), success(false) {}

void LevelEleven::setInput(std:: vector<bool> inputs) {
    // Sets the user input
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
    thirdBit = inputs.at(2);
    fourthBit = inputs.at(3);
    fifthBit = inputs.at(4);
    sixthBit = inputs.at(5);
}

void LevelEleven::computeOutput() {
    // Create gate objects for the gates on the circuit
    Gate gate1 = setGate(userGateSelected1);
    Gate gate2 = setGate(userGateSelected2);
    Gate gate3 = setGate(userGateSelected3);
    Gate gate4 = setGate(userGateSelected4);
    Gate gate5 = setGate(userGateSelected5);

    // Sets gate and gets inputs from user while calculating outputs of the gates
    gate1.setInput(firstBit, secondBit);
    bool firstResult = gate1.computeOutput();

    gate2.setInput(thirdBit, fourthBit);
    bool secondResult = gate2.computeOutput();

    gate3.setInput(fifthBit, sixthBit);
    bool thirdResult = gate3.computeOutput();

    gate4.setInput(secondResult, firstResult);
    bool output1 = gate4.computeOutput();

    // Using the bool to check the double output, checks if circuit is correct
    gate5.setInput(thirdResult, secondResult);
    bool output2 = gate5.computeOutput();
    if (output1 & !output2){
        success = true;
    }

    // Final output of the circuit
    result = success;
 }

void LevelEleven::setGateTypes(const std::vector<std::string>& gateTypes){
    // Sets the user gate type drag and drop assignment
    userGateSelected1 = gateTypes.at(0);
    userGateSelected2 = gateTypes.at(1);
    userGateSelected3 = gateTypes.at(2);
    userGateSelected4 = gateTypes.at(3);
    userGateSelected5 = gateTypes.at(4);
}



