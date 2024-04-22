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
    bool fifthBit;
    bool sixthBit;
    string userGateSelected1;
    string userGateSelected2;
    string userGateSelected3;
    string userGateSelected4;
    string userGateSelected5;
public:
    LevelTen();

    void setInput(std::vector<bool> inputs) override;
    void setGateTypes(const std::vector<std::string>&) override;
    void computeOutput() override;
};


#endif // LEVELTEN_H
