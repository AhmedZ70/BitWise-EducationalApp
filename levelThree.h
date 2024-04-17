// LevelThreeNand
#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "circuitLevel.h"
#include "nandGate.h"

class LevelThree: public CircuitLevel {
private:
    NandGate nandGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelThree();
    void setInput(bool a, bool b)override;
    void computeOutput()override;
    bool getResult() const override;
};

#endif // LEVELTHREE_H
