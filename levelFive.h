// LevelFiveXor
#ifndef LEVELFIVE_H
#define LEVELFIVE_H

#include "xorGate.h"

class LevelFive {
private:
    XorGate xorGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelFive();
    void setInput(bool a, bool b);
    void computeOutput();
    bool getResult() const;
};

#endif // LEVELFIVE_H
