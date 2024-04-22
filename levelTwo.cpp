#include "levelTwo.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelTwo cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelTwo h file.
*/
LevelTwo::LevelTwo() : inputA(false), inputB(false)
{
    expectedGate = "OR";
}

void LevelTwo::setInput(std:: vector<bool> inputs) {
    // Sets user inputs
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelTwo::computeOutput() {
    // Sets gate and gets inputs from user
    Gate orGate = setGate("OR");
    orGate.setInput(inputA, inputB);

    // Computes circuit output and sets circuit model result
    result = orGate.computeOutput();
}



