// LevelFourNor
#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "norGate.h"
#include "circuitLevel.h"
class LevelFour: public CircuitLevel{
private:
    NorGate norGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelFour();
    void setInput(bool a, bool b)override;
    void computeOutput()override;
    bool getResult() const override;
};

#endif // LEVELFOUR_H
