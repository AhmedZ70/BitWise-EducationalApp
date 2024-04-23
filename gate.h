#ifndef GATE_H
#define GATE_H

#include <functional>

using namespace std;

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name Gate header file for assignment9
 * This header file defines the Gate class which encapsulates logic gate functionalities
 * such as NOT, AND, OR, etc., allowing for dynamic gate behavior in circuit simulations.
 */
class Gate {
private:
    // Inputs for the gate, supporting up to two inputs.
    bool firstInput, secondInput;

    // The current output of the gate based on its inputs.
    bool output;

    // Function for NOT gate computation.
    function<bool(bool)> notGateFunction;

    // Function for binary gate computation (AND, OR, etc.).
    function<bool(bool, bool)> gateFunction;

    // Flag to determine if the gate is a NOT gate.
    bool isNotGate;

public:
    /// @brief Constructor for binary gate types (AND, OR, etc.).
    Gate(function<bool(bool, bool)> func);

    /// @brief Constructor for unary gate types (NOT).
    Gate(function<bool(bool)> func);

    /// @brief Default constructor.
    Gate();

    /// @brief Sets inputs for binary gates.
    void setInput(bool firstValue, bool secondValue);

    /// @brief Sets input for unary gates.
    void setInput(bool value);

    /// @brief Computes the output of the gate based on its inputs and function.
    bool computeOutput();

    /// @brief Retrieves the current output of the gate.
    bool getOutput();
};

#endif // GATE_H
