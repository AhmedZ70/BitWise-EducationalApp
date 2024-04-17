// LevelTwoOr
#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "orGate.h"

class LevelTwo {
private:
    OrGate orGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelTwo();
    void setInput(bool a, bool b);
    void computeOutput();
    bool getResult() const;
};

#endif // LEVELTWO_H
