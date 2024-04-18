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
    void setInput(std:: vector<bool> inputs)override;
    void computeOutput()override;
};

#endif // LEVELTHREE_H
