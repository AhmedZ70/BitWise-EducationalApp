#ifndef LEVELELEVEN_H
#define LEVELELEVEN_H
#include "circuitLevel.h"
class LevelEleven : public CircuitLevel
{
private:
    bool firstBit;
    bool secondBit;
    bool thirdBit;
    bool fourthBit;
    bool fifthBit;
    bool sixthBit;
    bool success;
    string userGateSelected1;
    string userGateSelected2;
    string userGateSelected3;
    string userGateSelected4;
    string userGateSelected5;

public:
    LevelEleven();

    void setInput(std::vector<bool> inputs);

    void setGateTypes(const std::vector<std::string>& gateTypes);

    void computeOutput();
};

#endif // LEVELELEVEN_H
