// LevelFiveXor
#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "xorGate.h"
#include "circuitLevel.h"

class LevelFive: public CircuitLevel {
private:
    XorGate xorGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelFive();
    void setInput(std:: vector<bool> inputs) override;
    void computeOutput() override;
};

#endif // LEVELFIVE_H
