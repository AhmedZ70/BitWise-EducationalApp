#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "levelonewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
    levelsUi(new LevelsView())

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



