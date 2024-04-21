#ifndef GATE_H
#define GATE_H

#include <functional>
using namespace std;

class Gate {
private:
    bool firstInput, secondInput;
    bool output;
    function<bool(bool)> notGateFunction;
    function<bool(bool, bool)> gateFunction;
    bool isNotGate;
public:
    Gate(function<bool(bool, bool)> func);
    Gate(function<bool(bool)> func);
    void setInput(bool firstValue, bool secondValue);
    void setInput(bool value);
    bool computeOutput();
    bool getOutput();
};
#endif // GATE_H
