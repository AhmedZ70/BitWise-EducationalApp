#include "levelFour.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelFour cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelFour h file.
*/
LevelFour::LevelFour() : inputA(false), inputB(false)
{
    expectedGate = "NOR";
}

void LevelFour::setInput(std:: vector<bool> inputs) {
    // Sets the user inputs
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelFour::computeOutput() {
    // Sets gate and gets inputs from user
    Gate norGate = setGate("NOR");
    norGate.setInput(inputA, inputB);

    // Computes circuit output and sets circuit model result
    result = norGate.computeOutput();
}


