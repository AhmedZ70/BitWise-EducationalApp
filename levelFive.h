// LevelFiveXor
#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "circuitLevel.h"

class LevelFive: public CircuitLevel {

private:
    bool inputA;
    bool inputB;

public:
    LevelFive();
    void setInput(std:: vector<bool> inputs) override;
    void computeOutput() override;
};

#endif // LEVELFIVE_H
