#ifndef CIRCUIT_H
#define CIRCUIT_H

class Circuit {

private:
    int output;
    int input;

public:
    Circuit();

    unsigned char notGate(unsigned char input);

    unsigned char andGate(unsigned char input1, unsigned char input2);

    unsigned char orGate(unsigned char input1, unsigned char input2);

    unsigned char nandGate(unsigned char input1, unsigned char input2);

    unsigned char norGate(unsigned char input1, unsigned char input2);

    unsigned char xorGate(unsigned char input, unsigned char input2);

};

#endif // CIRCUIT_H
