#ifndef LEVELSIX_H
#define LEVELSIX_H

#include "circuitLevel.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelSix h file for assignment9
 * This h file contains the outlined methods for use within the circuit level six.
*/
class LevelSix: public CircuitLevel{
private:
    /// @brief first input of the user
    bool inputA;

    /// @brief second input of the user
    bool inputB;

public:
    /// @brief Constructor that initializes the bits to false and sets the preset gate
    LevelSix();

    /// @brief Uses a vector of inputs from the user and sets them in the model
    /// @param vector of boolean user inputs
    void setInput(std:: vector<bool> inputs) override;

    /// @brief Computes the output of the levels circuit specific to this level using
    /// the user inputs
    void computeOutput()override;
};
#endif // LEVELSIX_H
