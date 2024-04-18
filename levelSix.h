#ifndef LEVELSIX_H
#define LEVELSIX_H

#include "andGate.h"
#include "notGate.h"
#include "circuitLevel.h"

class LevelSix: public CircuitLevel{
private:
    AndGate andGate;
    NotGate notGate;
    bool inputA;
    bool inputB;
    bool result;

public:
    LevelSix();
    void setInput(std:: vector<bool> inputs) override;
    void computeOutput()override;
};
#endif // LEVELSIX_H
