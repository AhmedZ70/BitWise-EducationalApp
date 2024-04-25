#include "levelFour.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelFour cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelFour h file.
*/
LevelFour::LevelFour() : firstBit(false), secondBit(false)
{
    expectedGate = "NOR";
}

void LevelFour::setInput(std:: vector<bool> inputs) {
    // Sets the user inputs
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
}

void LevelFour::computeOutput() {
    // Sets gate and gets inputs from user
    Gate norGate = setGate("NOR");
    norGate.setInput(firstBit, secondBit);

    // Computes circuit output and sets circuit model result
    result = norGate.computeOutput();
}


