// LevelOne.h
#ifndef LEVELONE_H
#define LEVELONE_H

#include "andGate.h"

class LevelOne {
private:
    AndGate andGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelOne();
    void setInput(bool a, bool b);
    void computeOutput();
    bool getResult() const;
};

#endif // LEVELONE_H
