#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <vector>
#include "circuitLevel.h"
#include <vector>
#include <QObject>
#include <memory>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name GameModel header file for assignment9
 * This header file defines the GameModel class which manages game levels and handles logic
 * for circuit simulation based on user interactions in a digital circuit simulation game.
 */
class GameModel : public QObject {
    Q_OBJECT

private:
    int currentLevel;  ///< Index of the current level the player is on.
    std::vector<std::unique_ptr<CircuitLevel>> levels;  ///< List of levels in the game.

    /// @brief Computes the circuit logic for the current level.
    void computeLevelCircuit(int currentLevel);

    /// @brief Checks if the vector contains an empty string, indicating an incomplete gate setup.
    bool hasEmptyString(const std::vector<std::string>& gateTypes);

public:
    /// @brief Constructor for GameModel.
    explicit GameModel(QObject *parent = nullptr);

signals:
    /// @brief Signal emitted when a circuit is completed successfully or unsuccessfully.
    void circuitCompleted(bool completed);

    /// @brief Signal emitted to indicate if the dropped gate is correct.
    void correctGate(bool correctGate);

    /// @brief Signal emitted when a gate is expected but not provided.
    void emptyGate();

public slots:
    /// @brief Slot to handle received inputs to the current level's circuit.
    void onInputReceived(std::vector<bool> inputs);

    /// @brief Slot to update the model when a gate is dropped into the circuit.
    void setGateDropped(const std::vector<std::string>& gateTypes);

    /// @brief Slot to check if the user's gate choice is correct.
    void checkUserGate(std::string gate);

    /// @brief Slot to retrieve and set the current level based on user selection.
    void onGetCurrentLevel(int level);
};

#endif // GAMEMODEL_H
