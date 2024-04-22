#ifndef CIRCUITLEVEL_H
#define CIRCUITLEVEL_H

#include <vector>
#include <string>
#include "gate.h"

using namespace std;

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name circuitLevel h file for assignment9
 * This h file contains the outlined methods for use within the circuit level class for use for levels.
 * This is used in connection with the front end to communicate user inputs to the model and is a base class
 * for the level classes.
*/
class CircuitLevel {

protected:
    /// @brief computed result of a user input for a circuit
    bool result;

    /// @brief sets the gate of a user selected gate
    Gate setGate(string gate);

    /// @brief expected gate that the level requires for early levels
    string expectedGate;
public:

    /// @brief Sets the inputs of a circuit in the model according to a vector of user inputs
    /// @param vector of user inputs from the view-controller
    virtual void setInput(std:: vector<bool> inputs);

    /// @brief Computes the output of the levels circuit specific to this level using
    /// the user inputs.
    virtual void computeOutput();

    /// @brief Sets the types of the gates of this circuit in the model using the
    /// user selected gates from the front end.
    /// @param vector of strings as the gate types
    virtual void setGateTypes(const std::vector<std::string>& gateTypes);

    /// @brief Gets the result of a computed circuit according to the user inputs
    /// @return bool of whether the circuit is completed or not
    bool getResult() const;

    /// @brief
    bool correctUserGate(string givenGate);

    /// @brief deconstructor of a circuit level object
    ~CircuitLevel();
};

#endif // CIRCUITLEVEL_H
