// LevelFourNor
#ifndef LEVELFOUR_H
#define LEVELFOUR_H

#include "circuitLevel.h"
class LevelFour: public CircuitLevel{
private:
    bool inputA;
    bool inputB;

public:
    LevelFour();
    void setInput(std:: vector<bool> inputs)override;
    void computeOutput()override;
};
#endif // LEVELFOUR_H
