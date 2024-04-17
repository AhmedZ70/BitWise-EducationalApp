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
    void setInput(bool a, bool b) override;
    void computeOutput()override ;
    bool getResult() const override;
};

#endif // LEVELTWO_H
