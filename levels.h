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

    void on_backToLevel1_clicked();

    void Image_View_Image_Enter(QPixmap pixmap);

private:
    Ui::levels *ui;
    //DropGraphicsView *graphicsView;
    QGraphicsScene *scene;

signals:
    void homeClicked();
};

#endif // LEVELS_H
