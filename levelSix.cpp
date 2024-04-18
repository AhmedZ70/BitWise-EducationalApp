#include "levelSix.h"
LevelSix::LevelSix() : inputA(false), inputB(false){}

void LevelSix::setInput(std:: vector<bool> inputs) {
    inputA = inputs.at(0);
    inputB = inputs.at(1);
}

void LevelSix::computeOutput() {
    Gate andGate = setGate("AND");
    andGate.setInput(inputA, inputB);
    result = andGate.computeOutput();
    Gate notGate = setGate("NOT");
    notGate.setInput(result, false);
    bool finalResult = notGate.computeOutput();
    result = finalResult;

}


