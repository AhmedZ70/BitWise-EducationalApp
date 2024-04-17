#include "levelSix.h"
LevelSix::LevelSix() : inputA(false), inputB(false), result(false) {}

void LevelSix::setInput(bool a, bool b) {
    inputA = a;
    inputB = b;
}

void LevelSix::computeOutput() {

    andGate.setInput(inputA, inputB);

    result = andGate.computeOutput();

    notGate.setInput(result, false);

    bool finalResult = notGate.computeOutput();
    result = finalResult;

}

bool LevelSix::getResult() const {
    return result;
}

