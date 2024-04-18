// LevelTwoOr
#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "circuitLevel.h"

class LevelTwo: public CircuitLevel {
private:
    bool inputA;
    bool inputB;

public:
    LevelTwo();
    void setInput(std:: vector<bool> inputs) override;
    void computeOutput()override ;
};

#endif // LEVELTWO_H
