#ifndef ANDGATE_H
#define ANDGATE_H
#include "logicgate.h"
class AndGate : public LogicGate {
private:
    bool input1, input2;
    bool output;

public:
    void setInput(bool firstValue, bool secondValue)override;
    bool computeOutput() override;
    bool getOutput() const override;
};
#endif // ANDGATE_H
