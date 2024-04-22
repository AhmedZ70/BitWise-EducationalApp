// LevelThreeNand
#ifndef LEVELTHREE_H
#define LEVELTHREE_H
#include "circuitLevel.h"

class LevelThree: public CircuitLevel {
private:
    bool inputA;
    bool inputB;
public:
    LevelThree();
    void setInput(std:: vector<bool> inputs)override;
    void computeOutput()override;

};
#endif // LEVELTHREE_H
