#ifndef LEVELS_H
#define LEVELS_H

#include <QWidget>
#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QString>
#include <QCoreApplication>
#include <QGraphicsScene>
#include "gameModel.h"
#include <vector>


namespace Ui {
class levels;
}

class levels : public QWidget
{
    Q_OBJECT

public:
    explicit levels(QWidget *parent = nullptr);
    ~levels();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();


    void onHomeButtonClicked();

    void on_homeButton_2_clicked();

    void on_homeButton_3_clicked();

    void on_homeButton_4_clicked();

    void on_homeButton_5_clicked();

    void on_homeButton_6_clicked();

    void on_homeButton_7_clicked();

    void on_homeButton_8_clicked();

    void on_homeButton_9_clicked();

    void on_skipButton_clicked();

    void on_skipButton_2_clicked();

    void on_skipButton_3_clicked();

    void on_skipButton_4_clicked();

    void on_skipButton_5_clicked();

    void on_skipButton_6_clicked();

    void on_skipButton_7_clicked();

    void on_skipButton_8_clicked();

    void on_skipButton_9_clicked();

    void on_backToLevel1_clicked();

    void on_backToLevel1_2_clicked();

    void on_backToLevel1_3_clicked();

    void on_backToLevel1_4_clicked();

    void on_backToLevel1_5_clicked();

    void on_backToLevel1_6_clicked();

    void on_backToLevel1_7_clicked();

    void on_backToLevel1_8_clicked();

    void on_goButtonLevelOne_clicked();

private:
    Ui::levels *ui;

    GameModel * gameModel;

signals:
    void homeClicked();
    void gotUserInput(std::vector<bool>);
    void calculateLevel(int level);

public slots:
    void onResultReceived(bool successful);
};

#endif // LEVELS_H
