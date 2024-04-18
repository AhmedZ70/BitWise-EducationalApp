#include "levels.h"
#include "ui_levels.h"
#include <QMessageBox>
#include <iostream>
using namespace std;
levels::levels(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levels)
{
    ui->setupUi(this);
    gameModel = new GameModel();
    ui->stackedWidget->setCurrentIndex(0);
    connect (ui->homeButton, &QPushButton::clicked, this, &levels::onHomeButtonClicked);


    QPixmap AND_GATE(":/icons/andGate.png");
    QPixmap OR_GATE(":/icons/orGate.png");
    QPixmap NAND_GATE(":/icons/nandGate.png");
    QPixmap NOR_GATE(":/icons/norGate.png");
    QPixmap XOR_GATE(":/icons/xorGate.png");
    QPixmap NOT_GATE(":/icons/notGate.png");


    ui->andGateLabel->setPixmap(AND_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->orGateLabel->setPixmap(OR_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->nandGateLabel->setPixmap(NAND_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->norGateLabel->setPixmap(NOR_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->xorGateLabel->setPixmap(XOR_GATE.scaled(100,100, Qt::KeepAspectRatio));
    ui->notGateLabel->setPixmap(NOT_GATE.scaled(100, 100, Qt::KeepAspectRatio));


    ui->andGateLabel->setParent(ui->groupBox);
    ui->andGateLabel->setGateName("AND_GATE");
    ui->orGateLabel->setParent(ui->groupBox);
    ui->orGateLabel->setGateName("OR_GATE");
    ui->nandGateLabel->setParent(ui->groupBox);
    ui->nandGateLabel->setGateName("NAND_GATE");
    ui->norGateLabel->setParent(ui->groupBox);
    ui->norGateLabel->setGateName("NOR_GATE");
    ui->xorGateLabel->setParent(ui->groupBox);
    ui->xorGateLabel->setGateName("XOR_GATE");
    ui->notGateLabel->setParent(ui->groupBox);
    ui->notGateLabel->setGateName("NOT_GATE");
}

levels::~levels()
{
    delete ui;

}

void levels::on_pushButton_clicked()
{
    cout << "go clicked" << endl;
}


void levels::onHomeButtonClicked()
{
    emit homeClicked();
}

void levels::on_homeButton_2_clicked(){
    emit homeClicked();
}

//Go to next level functions

void levels::on_skipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void levels::on_skipButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void levels::on_homeButton_3_clicked(){
    emit homeClicked();
}


//Go back to previous level functions
void levels::on_backToLevel1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void levels::on_backToLevel1_2_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void levels::on_backToLevel1_3_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}

void levels::on_goButtonLevelOne_clicked()
{
    bool inputValue1 = (ui->levelOneInput1->text() == "1");
    bool inputValue2 = (ui->levelOneInput2->text() == "1");
    gameModel->setLevelInput(inputValue1, inputValue2);
    bool successful = gameModel->computeLevelCiruit(0);
    QString lastGate = ui->graphicsView->lastDroppedGateName();
    if (successful) {
        if (lastGate != "AND_GATE"){
            QMessageBox::warning(this, "Gate Requirement", "you need an AND Gate dummy");
        }
        else {
            ui->stackedWidget->setCurrentIndex(1);
            QMessageBox::information(this, "Success", "good job on to level 2");
        }
    } else {
        QMessageBox::critical(this, "Level Failed", "try again");
    }
}

