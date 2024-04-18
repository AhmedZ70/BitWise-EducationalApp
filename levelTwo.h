// LevelTwoOr
#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "orGate.h"
#include "circuitLevel.h"

class LevelTwo: public CircuitLevel {
private:
    OrGate orGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelTwo();
    void setInput(std:: vector<bool> inputs) override;
    void computeOutput()override ;
};

#endif // LEVELTWO_H
