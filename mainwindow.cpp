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
}

MainWindow::~MainWindow()
{
    delete ui;
    delete levelsUi;
}

void MainWindow::on_playButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    levelsUi->show();
}

