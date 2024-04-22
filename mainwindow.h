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

    float originalX;
    float originalY;

    float maxDisplacement;
    const float pixelsPerMeter = 100.0f;  // Define pixels per meter scaling factor

    void createButtonBody(QPushButton* button, b2Body*& body, float width, float height);
    void updateButtonPosition(QPushButton* button, b2Body* body);

private slots:
    void updatePhysics();
    void on_playButton_clicked();
    void moveHome();
};

#endif // MAINWINDOW_H
