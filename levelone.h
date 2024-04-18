// LevelOneAnd
#ifndef LEVELONE_H
#define LEVELONE_H

#include "circuitLevel.h"
#include "andGate.h"

class LevelOne : public CircuitLevel {
private:
    AndGate andGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelOne();
    void setInput(std:: vector<bool> inputs)override;
    void computeOutput()override;
};

#endif // LEVELONE_H
