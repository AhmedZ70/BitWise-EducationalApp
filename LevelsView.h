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

namespace Ui {
class LevelsView;
}

class LevelsView : public QWidget
{
    Q_OBJECT

public:
    explicit LevelsView(QWidget *parent = nullptr);
    ~LevelsView();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    //Home button handlers

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

    void on_goButtonLevel8_clicked();

    void on_goButtonLevel9_clicked();

    void on_goButtonLevel10_clicked();

    void on_backToLevel1_11_clicked();

    void on_goButtonLevel7_clicked();

    void on_stackedWidget_currentChanged(int arg1);

private:
    Ui::LevelsView *ui;
    int currentLevel;
    GameModel * gameModel;
    bool correctGateDragged;
    void goClickedTrainingLevel(int level);
    bool getFirstUserInput(int level);
    bool getSecondUserInput(int level);
    QString getLastDroppedGate(int level);
    void processLevelInputs(const std::vector<Custom_GraphicsView*>& gateDropAreas,
                                        const std::vector<CustomLineEdit*>& inputs);
    bool userFirstInput;
    bool userSecondInput;
    bool userThirdInput;
    bool userFourthInput;
    bool userFifthInput;
    bool userSixthInput;
    bool userSeventhInput;
    bool userEighthInput;

    void LearningWindow(int level);

signals:
    void homeClicked();
    void gotUserInput(std::vector<bool>);
    void calculateLevel(int level);
    void userGateSelected(string gate);
    void levelChanged(int level);

public slots:
    void onResultReceived(bool successful);
    void onCorrectGateReceived(bool correct);
};

#endif // LEVELSVIEW_H
