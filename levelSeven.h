#ifndef LEVELSEVEN_H
#define LEVELSEVEN_H
#include "circuitLevel.h"
#include <vector>
#include <string>
using namespace std;
class LevelSeven: public CircuitLevel {
private:
    bool firstBit;
    bool secondBit;
    bool thirdBit;
    string userGateSelected1;
    string userGateSelected2;
public:
    LevelSeven();
    void setInput(std::vector<bool> inputs) override;
    void computeOutput() override;
    void setGateTypes(const std::vector<std::string>& gateTypes) override;

};

#endif // LEVELSEVEN_H
