#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), levelsUi(new levels())
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(levelsUi);

    // Connect signals to slots
    connect(levelsUi, SIGNAL(homeClicked()), this, SLOT(moveHome()));

    // Closes the application when the quit button is clicked.
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
}


void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}
