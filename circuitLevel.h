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
    string expectedGate;
public:
    virtual void setInput(std:: vector<bool> inputs);
    virtual void computeOutput();
    bool getResult() const;
    bool correctUserGate(string givenGate);
    ~CircuitLevel();

};

#endif // CIRCUITLEVEL_H
