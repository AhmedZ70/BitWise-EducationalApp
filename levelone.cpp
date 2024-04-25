#include "levelone.h"
#include "gate.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelOne cpp file for assignment9
 * This cpp file contains the the implementation of the methods outlines in the levelOne h file.
*/
LevelOne::LevelOne() : firstBit(false), secondBit(false)
{
    expectedGate = "AND";
}

void LevelOne::setInput(std:: vector<bool> inputs) {
    // Sets user inputs
    firstBit = inputs.at(0);
    secondBit = inputs.at(1);
}

void LevelOne::computeOutput() {
    // Sets gate and gets inputs from user
    Gate andGate = setGate("AND");
    andGate.setInput(firstBit, secondBit);

    // Computes circuit output and sets circuit model result
    result = andGate.computeOutput();
}

bool LevelOne:: checkCorrectGate(string userGate)
{
    return correctUserGate(userGate);
}


