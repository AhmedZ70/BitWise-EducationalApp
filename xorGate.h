#ifndef XORGATE_H
#define XORGATE_H
#include "logicgate.h"
class XorGate : public LogicGate {
private:
    bool input1, input2;
    bool output;

public:
    void setInput(bool firstValue, bool secondValue)override;
    bool computeOutput() override;

    bool getOutput() const override;
};

#endif // XORGATE_H
