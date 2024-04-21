#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <LevelsView.h>

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
    LevelsView * levelsUi;
    // void dragEnterEvent(QDragEnterEvent *event) override;

    // void dropEvent(QDropEvent *event) override;
private slots:
    void on_playButton_clicked();
    void moveHome();
};
#endif // MAINWINDOW_H
