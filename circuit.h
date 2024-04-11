#ifndef CIRCUIT_H
#define CIRCUIT_H

class Circuit {

private:
    int output;
    int input;

public:
    Circuit();

    void notGate(unsigned char input);

    void andGate(unsigned char input);

    void orGate(unsigned char input);

    void nand(unsigned char input);

    void nor(unsigned char input);

    void xorGate(unsigned char input);

};

#endif // CIRCUIT_H
