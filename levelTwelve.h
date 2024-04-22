#ifndef LEVELTWELVE_H
#define LEVELTWELVE_H
#include "circuitLevel.h"
class LevelTwelve : public CircuitLevel
{
private:
    bool firstBit;
    bool secondBit;
    bool thirdBit;
    bool fourthBit;
    bool fifthBit;
    bool sixthBit;
    bool seventhBit;
    bool eighthBit;
    string userGateSelected1;
    string userGateSelected2;
    string userGateSelected3;
    string userGateSelected4;
    string userGateSelected5;
    string userGateSelected6;
    string userGateSelected7;

public:
    LevelTwelve();

    void setInput(std::vector<bool> inputs);

    void setGateTypes(const std::vector<std::string>& gateTypes);

    void computeOutput();
};

#endif // LEVELTWELVE_H
