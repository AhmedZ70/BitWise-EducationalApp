#ifndef LEVELSIX_H
#define LEVELSIX_H

#include "circuitLevel.h"

class LevelSix: public CircuitLevel{
private:
    bool inputA;
    bool inputB;
    bool result;

public:
    LevelSix();
    void setInput(std:: vector<bool> inputs) override;
    void computeOutput()override;
};
#endif // LEVELSIX_H
