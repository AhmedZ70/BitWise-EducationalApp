#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "levelonewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    levelsUi(new levels())

{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(levelsUi);

    connect(levelsUi, SIGNAL(homeClicked()), this, SLOT(moveHome()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete levelsUi;
}

void MainWindow::on_playButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(levelsUi));
    //auto index = ui->stackedWidget->currentIndex();   // for debugging
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

// void MainWidget::dragEnterEvent(QDragEnterEvent *event) {
//     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
//         event->acceptProposedAction();
//     }
// }

// void MainWidget::dropEvent(QDropEvent *event) {
//     if (event->mimeData()->hasFormat("application/x-dnditemdata")) {
//         // Perform the action needed to simulate the gate between input and output
//         // This could involve changing the state of the widget to reflect that
//         // a gate has been placed and is ready to compute the logic operation
//         event->acceptProposedAction();
//     }
// }

