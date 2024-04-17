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
    void setInput(bool a, bool b) override;
    void computeOutput()override;
    bool getResult() const override;
};
#endif // LEVELSIX_H
