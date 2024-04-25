#include "levelFive.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelFive cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelFive h file.
*/
LevelFive::LevelFive() : firstBit(false), secondBit(false)
{
    expectedGate = "XOR";
}

void LevelFive::setInput(std:: vector<bool> inputs) {
    // Sets the user inputs
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
}

void LevelFive::computeOutput() {
    // Sets gate and gets inputs from user
    Gate xorGate = setGate("XOR");
    xorGate.setInput(firstBit, secondBit);

    // Computes circuit output and sets circuit model result
    result = xorGate.computeOutput();
}



