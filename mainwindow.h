#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <levels.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    levels * levelsUi;

private slots:
    void on_playButton_clicked();
    void moveHome();
};
#endif // MAINWINDOW_H
