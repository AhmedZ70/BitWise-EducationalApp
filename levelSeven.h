#ifndef LEVELSEVEN_H
#define LEVELSEVEN_H

#include "circuitLevel.h"

#include <vector>
#include <string>

using namespace std;

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelSeven h file for assignment9
 * This h file contains the outlined methods for use within the circuit level seven.
*/
class LevelSeven: public CircuitLevel {
private:
    /// @brief first input of the user
    bool firstBit;

    /// @brief second input of the user
    bool secondBit;

    /// @brief third input of the user
    bool thirdBit;

    /// @brief first user selected gate on the circuit
    string userGateSelected1;

    /// @brief second user selected gate on the circuit
    string userGateSelected2;
public:
    /// @brief Constructor that initializes the bits to false and sets the preset gate
    LevelSeven();

    /// @brief Uses a vector of inputs from the user and sets them in the model
    /// @param vector of boolean user inputs
    void setInput(std::vector<bool> inputs) override;

    /// @brief Computes the output of the levels circuit specific to this level using
    /// the user inputs.
    void computeOutput() override;

    /// @brief Sets the types of the gates of this circuit in the model using the
    /// user selected gates from the front end.
    /// @param vector of strings as the gate types
    void setGateTypes(const std::vector<std::string>& gateTypes) override;

};

#endif // LEVELSEVEN_H
