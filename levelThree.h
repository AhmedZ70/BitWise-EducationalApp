// LevelThreeNand
#ifndef LEVELTHREE_H
#define LEVELTHREE_H

#include "nandGate.h"

class LevelThree {
private:
    NandGate nandGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelThree();
    void setInput(bool a, bool b);
    void computeOutput();
    bool getResult() const;
};

#endif // LEVELTHREE_H
