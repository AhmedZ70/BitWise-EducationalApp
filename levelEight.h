#ifndef LEVELEIGHT_H
#define LEVELEIGHT_H
#include "circuitLevel.h"
#include <vector>
#include <functional>
#include <string>
using namespace std;
class LevelEight: public CircuitLevel {
private:
    bool firstBit;
    bool secondBit;
    bool thirdBit;
    bool fourthBit;
    string userGateSelected1;
    string userGateSelected2;
    string userGateSelected3;
public:
    LevelEight();
    void setInput(std::vector<bool> inputs) override;
    void computeOutput() override;
    void setFunction(string gate);
    void setUserGateSelected1(string gateSelected);
    void setUserGateSelected2(string gateSelected);
    void setUserGateSelected3(string gateSelected);
};

#endif // LEVELEIGHT_H
