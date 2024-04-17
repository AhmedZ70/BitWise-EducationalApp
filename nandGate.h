#ifndef NANDGATE_H
#define NANDGATE_H

#include "logicgate.h"
class NandGate : public LogicGate {
private:
    bool input1, input2;
    bool output;

public:
    void setInput(bool firstValue, bool secondValue)override;
    bool computeOutput() override;
    bool getOutput() const override;
};
#endif // NANDGATE_H
