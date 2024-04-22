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
    // Sets the user input
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelSix::computeOutput() {
    // Sets gate and gets inputs from user while calculating outputs of the gates
    Gate andGate = setGate("AND");
    andGate.setInput(inputA, inputB);
    bool firstResult = andGate.computeOutput();
    Gate notGate = setGate("NOT");
    notGate.setInput(firstResult);
    bool finalResult = notGate.computeOutput();

    // Final output of the circuit
    result = finalResult;
}



