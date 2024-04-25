#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>      // Base class for main window
#include <QPushButton>      // To use push buttons
#include <Box2D/Box2D.h>    // For physics capabilities
#include <QTimer>           // To handle timing events
#include <QMap>             // To store key-value pairs
#include <QDialog>          // To create dialog windows
#include <QComboBox>        // Dropdown list for selecting options
#include <QLabel>           // To display text or image
#include <QVBoxLayout>      // Layout manager for vertical box layout
#include "LevelsView.h"     // Custom header presumably for level management
#include "electricity.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April 23, 2024
 * @name LevelsView header file for assignment9
 * @brief This file defines the MainWindow class which serves as the central widget of the application,
 * incorporating UI elements, physics interactions, and game level management.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief Constructor for MainWindow, optionally taking a parent widget.
    explicit MainWindow(QWidget *parent = nullptr);

    /// @brief Destructor for MainWindow.
    ~MainWindow();

protected:
    /// @brief Overridden event filter to handle custom event processing.
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    // UI pointers and essential components
    Ui::MainWindow *ui;            // Pointer to the UI setup for MainWindow
    LevelsView *levelsUi;          // Pointer to levels view for managing game levels
    b2World* world;                // Pointer to the Box2D world used for physics interactions
    QTimer* timer;                 // Timer to manage time-based events

    // Physics bodies for interactive UI components
    b2Body* playButtonBody;        // Physics body for the play button
    b2Body* helpButtonBody;        // Physics body for the help button
    b2Body* quitButtonBody;        // Physics body for the quit button
    QLabel *movingGameTitle;       // Label for the moving game title
    b2Body *gameTitleBody;         // Physics body for the game title label
    QMap<QString, QString> helpTexts;  // Map to store help texts for different contexts
    QDialog *helpDialog;           // Dialog for displaying help content
    QComboBox *helpOptions;        // Combobox to select help topics
    QLabel *helpContent;           // Label to display help content
    ElectricityEffect* electricity;
    float originalXPlay, originalXHelp, originalXQuit; // Original X positions for buttons

    /// @brief Creates a physics body for a button with given dimensions.
    void createButtonBody(QPushButton* button, b2Body*& body, float width, float height);

    /// @brief Updates the position of a button based on its physics body.
    void updateButtonPosition(QPushButton* button, b2Body* body, int originalX);

    /// @brief Creates a physics body for a label.
    void createLabelBody(QLabel *label, b2Body*& body);

    /// @brief Initializes help text mappings.
    void initializeHelpTexts();

    /// @brief Sets up the help dialog interface.
    void setupHelpDialog();

private slots:
    /// @brief Updates physics state at regular intervals.
    void updatePhysics();

    /// @brief Handles the play button click event.
    void on_playButton_clicked();

    /// @brief Displays the help dialog.
    void showHelpDialog();

    /// @brief Moves the application to the home state.
    void moveHome();

    /// @brief Handles changes in the stacked widget's current page.
    void onStackedWidgetChange(int index);

    /// @brief Updates the displayed help content based on selected topic.
    void updateHelpContent();
};

#endif // MAINWINDOW_H
