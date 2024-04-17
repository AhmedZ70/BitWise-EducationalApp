// LevelFourNor
#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "norGate.h"

class LevelFour {
private:
    NorGate norGate; // Used for calculating the carry

    bool inputA;
    bool inputB;
    bool result;

public:
    LevelFour();
    void setInput(bool a, bool b);
    void computeOutput();
    bool getResult() const;
};

#endif // LEVELFOUR_H
