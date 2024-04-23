#ifndef LEVELSVIEW_H
#define LEVELSVIEW_H

#include <QWidget>
#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QString>
#include <QCoreApplication>
#include <QGraphicsScene>
#include "gameModel.h"
#include <vector>
#include "events.h"
#include "customlineedit.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April 22, 2024
 * @name LevelsView header file for assignment9
 * This header file defines the LevelsView class, which is responsible for displaying
 * and managing the game levels in the user interface.
 */
namespace Ui {
class LevelsView;
}

class LevelsView : public QWidget
{
    Q_OBJECT

public:
    /// @brief Constructor for LevelsView.
    explicit LevelsView(QWidget *parent = nullptr);

    /// @brief Destructor for LevelsView.
    ~LevelsView();

private slots:
    // Slots for "Go" button clicks at each level
    void on_goButtonLevelOne_clicked();
    void on_goButtonLevelTwo_clicked();
    void on_goButtonLevelThree_clicked();
    void on_goButtonLevelFour_clicked();
    void on_goButtonLevelFive_clicked();
    void on_goButtonLevelSix_clicked();
    void on_goButtonLevelSeven_clicked();
    void on_goButtonLevelEight_clicked();
    void on_goButtonLevelNine_clicked();
    void on_goButtonLevelTen_clicked();
    void on_goButtonLevelEleven_clicked();
    void on_goButtonLevelTwelve_clicked();

    // Home button handlers
    void onHomeButtonClicked();
    void on_homeButton_2_clicked();
    void on_homeButton_3_clicked();
    void on_homeButton_4_clicked();
    void on_homeButton_5_clicked();
    void on_homeButton_6_clicked();
    void on_homeButton_7_clicked();
    void on_homeButton_8_clicked();
    void on_homeButton_9_clicked();
    void on_homeButton_10_clicked();
    void on_homeButton_11_clicked();
    void on_homeButton_12_clicked();

    // Skip button handlers
    void on_skipButton_clicked();
    void on_skipButton_2_clicked();
    void on_skipButton_3_clicked();
    void on_skipButton_4_clicked();
    void on_skipButton_5_clicked();
    void on_skipButton_6_clicked();
    void on_skipButton_7_clicked();
    void on_skipButton_8_clicked();
    void on_skipButton_9_clicked();
    void on_skipButton_10_clicked();
    void on_skipButton_11_clicked();

    //Back to level handlers
    void on_backToLevel1_clicked();
    void on_backToLevel1_2_clicked();
    void on_backToLevel1_3_clicked();
    void on_backToLevel1_4_clicked();
    void on_backToLevel1_5_clicked();
    void on_backToLevel1_6_clicked();
    void on_backToLevel1_7_clicked();
    void on_backToLevel1_8_clicked();
    void on_backToLevel1_9_clicked();
    void on_backToLevel1_10_clicked();
    void on_backToLevel1_11_clicked();
    void on_backToLevel1_12_clicked();

    /// @brief Slot triggered when the current page of the stacked widget changes.
    void on_stackedWidget_currentChanged(int arg1);

private:
    // Pointer to the user interface setup.
    Ui::LevelsView *ui;

    // Current game level being displayed.
    int currentLevel;

    // Pointer to the game model.
    GameModel * gameModel;

    // Flag to track if the correct gate was dragged.
    bool correctGateDragged;

    /// @brief Handles clicks on the "Go" buttons and sets the appropriate training level.
    void goClickedTrainingLevel(int level);

    /// @brief Fetches the first user input for logic gates at a specific level.
    bool getFirstUserInput(int level);

    /// @brief Fetches the second user input for logic gates at a specific level.
    bool getSecondUserInput(int level);

    /// @brief Retrieves the last dropped gate name for a specific level.
    QString getLastDroppedGate(int level);

    /// @brief Processes the inputs for levels involving gate drop areas and custom inputs.
    void processLevelInputs(const std::vector<Custom_GraphicsView*>& gateDropAreas,
                                        const std::vector<CustomLineEdit*>& inputs);

    /// @brief Retrieves all user inputs as a vector of booleans at a specific level.
    std::vector<bool> getUserInputs(int level);

    // First user input for logic gates.
    bool userFirstInput;

    // Second user input for logic gates.
    bool userSecondInput;

    // Third user input for logic gates.
    bool userThirdInput;

    // Fourth user input for logic gates.
    bool userFourthInput;

    // Fifth user input for logic gates.
    bool userFifthInput;

    // Sixth user input for logic gates.
    bool userSixthInput;

    // Seventh user input for logic gates.
    bool userSeventhInput;

    // Eighth user input for logic gates.
    bool userEighthInput;

    /// @brief Launches the learning window for a specific level.
    void LearningWindow(int level);

signals:
    /// @brief Signal emitted when the home button is clicked.
    void homeClicked();

    /// @brief Signal emitted when user inputs are received.
    void gotUserInput(std::vector<bool>);

    /// @brief Signal emitted to calculate logic for a specific level.
    void calculateLevel(int level);

    /// @brief Signal emitted when a user gate is selected.
    void userGateSelected(string gate);

    /// @brief Signal emitted when the game level changes.
    void levelChanged(int level);

public slots:
    /// @brief Slot to receive the result of the logic calculation.
    void onResultReceived(bool successful);

    /// @brief Slot to receive confirmation of the correct gate.
    void onCorrectGateReceived(bool correct);
};

#endif // LEVELSVIEW_H
