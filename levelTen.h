#ifndef LEVELTEN_H
#define LEVELTEN_H
#include "circuitLevel.h"
#include <vector>
#include <string>
class LevelTen : public CircuitLevel
{
private:
    bool firstBit;
    bool secondBit;
    bool thirdBit;
    bool fourthBit;
    string userGateSelected1;
    string userGateSelected2;
    string userGateSelected3;
    string userGateSelected4;
    string userGateSelected5;
public:
    LevelTen();
};


#endif // LEVELTEN_H
