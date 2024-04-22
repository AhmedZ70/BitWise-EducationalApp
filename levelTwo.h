// LevelTwoOr
#ifndef LEVELTWO_H
#define LEVELTWO_H

#include "circuitLevel.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelTwo h file for assignment9
 * This h file contains the outlined methods for use within the circuit level two.
*/
class LevelTwo: public CircuitLevel {
private:
    /// @brief first input of the user
    bool inputA;

    /// @brief second input of the user
    bool inputB;

public:
    /// @brief Constructor that initializes the bits to false and sets preset gate
    LevelTwo();

    /// @brief Uses a vector of inputs from the user and sets them in the model
    /// @param vector of boolean user inputs
    void setInput(std:: vector<bool> inputs) override;

    /// @brief Computes the output of the levels circuit specific to this level using
    /// the user inputs
    void computeOutput()override ;
};

#endif // LEVELTWO_H
