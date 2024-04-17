#ifndef NOTGATE_H
#define NOTGATE_H
#include "logicgate.h"

class NotGate : public LogicGate {
private:
    bool input;
    bool output;

public:
    void setInput(bool firstValue, bool secondValue)override;

    bool computeOutput() override;

    bool getOutput() const override;
};

#endif // NOTGATE_H
