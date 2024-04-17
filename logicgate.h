#ifndef LOGICGATE_H
#define LOGICGATE_H


class LogicGate {
public:
    virtual bool computeOutput() = 0;
    virtual void setInput(bool firstValue, bool secondValue) = 0;
    virtual bool getOutput() const = 0;
    virtual ~LogicGate() = default;
};


#endif // LOGIC_GATE_H
