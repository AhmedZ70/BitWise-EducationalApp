#ifndef LEVELS_H
#define LEVELS_H

#include <QWidget>
#include <QMainWindow>
#include <QPixmap>
#include <QDebug>
#include <QString>
#include <QCoreApplication>
#include <QGraphicsScene>

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

    void onHomeButtonClicked();

    void on_skipButton_clicked();

    void on_skipButton_2_clicked();

    void on_backToLevel1_clicked();

    void on_homeButton_3_clicked();

    void on_backToLevel1_2_clicked();

    void on_homeButton_2_clicked();


private:
    Ui::levels *ui;

signals:
    void homeClicked();
};

#endif // LEVELS_H
