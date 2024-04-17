#ifndef NORGATE_H
#define NORGATE_H
#include "logicgate.h"
class NorGate : public LogicGate {
private:
    bool input1, input2;
    bool output;

public:
    void setInput(bool firstValue, bool secondValue) override;
    bool computeOutput() override;
    bool getOutput() const override;
};

#endif // NORGATE_H
