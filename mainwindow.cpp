#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Trainingdialog.h"
//#include "levelonewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    levelsUi(new LevelsView())

{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(levelsUi);
    resize(800, 600);
    connect(levelsUi, SIGNAL(homeClicked()), this, SLOT(moveHome()));

    connect(ui->quitButton, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete levelsUi;
}

void MainWindow::on_playButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(levelsUi));
    TrainingDialog *dialog = new TrainingDialog();
    QString trainingDialog = "This is an AND gate. The AND gate takes in 2 or 3 inputs and computes a single ouput.\n"
                             "In order for the AND gate to calculate to TRUE, all inputs must be TRUE.\n"
                             "The truth table for the AND gate illustrates this and is shown below";
    dialog->setupImageAndText(":/icons/andGate.png", trainingDialog);
    dialog->exec();
    //auto index = ui->stackedWidget->currentIndex();   // for debugging

}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}



