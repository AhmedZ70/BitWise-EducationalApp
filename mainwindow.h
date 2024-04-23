#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <Box2D/Box2D.h>
#include <QTimer>
#include "LevelsView.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April 22, 2024
 * @name MainWindow header file for assignment9
 * This header file defines the MainWindow class, which serves as the main interface
 * for a physics-enabled UI application, integrating Box2D for dynamic button interactions.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /// @brief Constructor for MainWindow, sets up the UI and physics world.
    explicit MainWindow(QWidget *parent = nullptr);

    /// @brief Destructor for MainWindow, cleans up resources.
    ~MainWindow();

protected:
    /// @brief Custom event filter to handle physics-based UI interactions.
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    // Pointer to the user interface.
    Ui::MainWindow *ui;

    // Pointer to the levels view UI component.
    LevelsView *levelsUi;

    // Pointer to the Box2D world, managing all physics bodies.
    b2World* world;

    // Timer to update physics calculations regularly.
    QTimer* timer;

    // Physics objects for UI buttons
    b2Body* playButtonBody;
    b2Body* helpButtonBody;
    b2Body* quitButtonBody;

    // Original X positions for buttons
    float originalXPlay;
    float originalXHelp;
    float originalXQuit;

    // Maximum displacement allowed for the buttons.
    float maxDisplacement;

    // Scaling factor for converting pixels to meters in physics calculations.
    const float pixelsPerMeter = 100.0f;

    /// @brief Creates a Box2D body for a button to enable physics interactions.
    void createButtonBody(QPushButton* button, b2Body*& body, float width, float height);

    /// @brief Updates the button position based on its physics body's status.
    void updateButtonPosition(QPushButton* button, b2Body* body, int height);

private slots:
    /// @brief Updates the physics world and the positions of physics-enabled UI elements.
    void updatePhysics();

    /// @brief Slot to handle clicks on the play button.
    void on_playButton_clicked();

    /// @brief Moves the view back to the home screen.
    void moveHome();
};

#endif // MAINWINDOW_H
