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
    Gate firstGate = setGate(userGateSelected1);
    Gate secondGate = setGate(userGateSelected2);
    Gate thirdGate = setGate(userGateSelected3);
    Gate fourthGate = setGate(userGateSelected4);
    Gate fifthGate = setGate(userGateSelected5);

    // Sets gate and gets inputs from user while calculating outputs of the gates
    firstGate.setInput(firstBit, secondBit);
    bool firstResult = firstGate.computeOutput();

    secondGate.setInput(thirdBit, fourthBit);
    bool secondResult = secondGate.computeOutput();

    thirdGate.setInput(fifthBit, sixthBit);
    bool thirdResult = thirdGate.computeOutput();

    fourthGate.setInput(secondResult, firstResult);
    bool output1 = fourthGate.computeOutput();

    // Using the bool to check the double output, checks if circuit is correct
    fifthGate.setInput(thirdResult, secondResult);
    bool output2 = fifthGate.computeOutput();
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



