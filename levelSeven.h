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
    string userGateSelected;
public:
    LevelSeven();
    void setInput(std::vector<bool> inputs) override;
    void computeOutput() override;
    void setUserGateSelected(string gateSelected);
};

#endif // LEVELSEVEN_H
