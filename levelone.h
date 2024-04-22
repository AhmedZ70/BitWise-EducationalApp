#ifndef LEVELONE_H
#define LEVELONE_H

#include "circuitLevel.h"

class LevelOne : public CircuitLevel {
private:
    bool inputA;
    bool inputB;
public:
    LevelOne();
    void setInput(std:: vector<bool> inputs)override;
    void computeOutput()override;
    bool checkCorrectGate(string userGate);
};

#endif // LEVELONE_H
