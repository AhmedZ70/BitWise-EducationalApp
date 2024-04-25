#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <Box2D/Box2D.h>
#include <QTimer>
#include <QMap>
#include <QDialog>
#include <QComboBox>
#include <QLabel>
#include <QVBoxLayout>
#include "LevelsView.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

private:
    Ui::MainWindow *ui;
    LevelsView *levelsUi;
    b2World* world;
    QTimer* timer;
    b2Body* playButtonBody;
    b2Body* helpButtonBody;
    b2Body* quitButtonBody;
    QLabel *movingGameTitle;
    b2Body *gameTitleBody;
    QMap<QString, QString> helpTexts; // Stores help texts for actions
    QDialog *helpDialog;
    QComboBox *helpOptions;
    QLabel *helpContent;
    float originalXPlay, originalXHelp, originalXQuit;

    void createButtonBody(QPushButton* button, b2Body*& body, float width, float height);
    void updateButtonPosition(QPushButton* button, b2Body* body, int originalX);
    void createLabelBody(QLabel *label, b2Body*& body);
    void initializeHelpTexts();  // Initializes help text descriptions
    void setupHelpDialog();  // Setup the help dialog components


private slots:
    void updatePhysics();
    void on_playButton_clicked();
    void showHelpDialog();  // Slot for showing help based on the action
    void moveHome();
    void onStackedWidgetChange(int index);
    void updateHelpContent();  // Update the help content based on selection
};

#endif // MAINWINDOW_H
