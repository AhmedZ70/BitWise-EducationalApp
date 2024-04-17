// OrGate.h
#ifndef ORGATE_H
#define ORGATE_H

#include "logicgate.h"

class OrGate : public LogicGate {
private:
    bool input1, input2;
    bool output;

public:
    void setInput(bool firstValue, bool secondValue) override;
    bool computeOutput() override;
    bool getOutput() const override;
};

#endif // ORGATE_H

