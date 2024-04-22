#ifndef CIRCUITLEVEL_H
#define CIRCUITLEVEL_H
#include <vector>
#include <string>
#include "gate.h"
using namespace std;
class CircuitLevel {

protected:
    bool result;
    Gate setGate(string gate);


public:
    virtual void setInput(std:: vector<bool> inputs);
    virtual void computeOutput();
    virtual void setGateTypes(const std::vector<std::string>& gateTypes);
    bool getResult() const;
    ~CircuitLevel();

};

#endif // CIRCUITLEVEL_H
