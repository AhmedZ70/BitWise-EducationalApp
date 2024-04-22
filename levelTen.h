#ifndef LEVELTEN_H
#define LEVELTEN_H

#include "circuitLevel.h"

#include <vector>
#include <string>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name levelTen h file for assignment9
 * This h file contains the outlined methods for use within the circuit level ten.
*/
class LevelTen : public CircuitLevel
{
private:
    /// @brief first input of the user
    bool firstBit;

    /// @brief second input of the user
    bool secondBit;

    /// @brief third input of the user
    bool thirdBit;

    /// @brief fourth input of the user
    bool fourthBit;

    /// @brief fifth input of the user
    bool fifthBit;

    /// @brief sixth input of the user
    bool sixthBit;

    /// @brief first user selected gate on the circuit
    string userGateSelected1;

    /// @brief second user selected gate on the circuit
    string userGateSelected2;

    /// @brief third user selected gate on the circuit
    string userGateSelected3;

    /// @brief fourth user selected gate on the circuit
    string userGateSelected4;

    /// @brief fifth user selected gate on the circuit
    string userGateSelected5;
public:
    /// @brief Constructor that initializes the bits to false and sets the preset gate
    LevelTen();

    /// @brief Uses a vector of inputs from the user and sets them in the model
    /// @param vector of boolean user inputs
    void setInput(std::vector<bool> inputs) override;

    /// @brief Sets the types of the gates of this circuit in the model using the
    /// user selected gates from the front end.
    /// @param vector of strings as the gate types
    void setGateTypes(const std::vector<std::string>&) override;

    /// @brief Computes the output of the levels circuit specific to this level using
    /// the user inputs.
    void computeOutput() override;
};


#endif // LEVELTEN_H
