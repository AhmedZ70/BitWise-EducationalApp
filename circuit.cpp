#include "circuit.h"

Circuit::Circuit() {

}

unsigned char Circuit::notGate(unsigned char input) {
    return ~input;
}

unsigned char Circuit::andGate(unsigned char input1, unsigned char input2) {
    return (input1 & input2);
}

unsigned char Circuit::orGate(unsigned char input1, unsigned char input2) {
    return (input1 | input2);
}

unsigned char Circuit::nandGate(unsigned char input1, unsigned char input2) {
    return ~(input1 & input2);
}

unsigned char Circuit::norGate(unsigned char input1, unsigned char input2) {
    return ~(input1 | input2);
}

unsigned char Circuit::xorGate(unsigned char input1, unsigned char input2) {
    return (input1 ^ input2);
}
