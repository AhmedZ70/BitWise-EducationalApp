#include "levelThree.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelThree cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelThree h file.
*/
LevelThree::LevelThree() : firstBit(false), secondBit(false)
{
    expectedGate = "NAND";
}

void LevelThree::setInput(std:: vector<bool> inputs) {
    // Sets user inputs
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
}

void LevelThree::computeOutput() {
    // Sets gate and gets inputs from user
    Gate nandGate = setGate("NAND");
    nandGate.setInput(firstBit, secondBit);

    // Computes circuit output and sets circuit model result
    result = nandGate.computeOutput();
}


