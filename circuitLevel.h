#ifndef CIRCUITLEVEL_H
#define CIRCUITLEVEL_H

class CircuitLevel {
public:
    virtual void setInput(bool a, bool b) = 0;
    virtual void computeOutput() = 0;
    virtual bool getResult() const = 0;
    virtual ~CircuitLevel() {}
};

#endif // CIRCUITLEVEL_H
