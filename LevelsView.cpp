#include "LevelsView.h"
#include "ui_LevelsView.h"
#include <QMessageBox>
#include <iostream>
#include <vector>
using namespace std;
LevelsView::LevelsView(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelsView)
{
    ui->setupUi(this);
    gameModel = new GameModel();
    ui->stackedWidget->setCurrentIndex(0);
    connect (ui->homeButton, &QPushButton::clicked, this, &LevelsView::onHomeButtonClicked);
    connect(gameModel,&GameModel::circuitCompleted,this, &LevelsView::onResultReceived);
    connect(this, &LevelsView::gotUserInput, gameModel,&GameModel::onInputReceived);
    connect(this, &LevelsView::calculateLevel,gameModel,&GameModel::computeLevelCircuit);

    QPixmap AND_GATE(":/icons/andGate.png");
    QPixmap OR_GATE(":/icons/orGate.png");
    QPixmap NAND_GATE(":/icons/nandGate.png");
    QPixmap NOR_GATE(":/icons/norGate.png");
    QPixmap XOR_GATE(":/icons/xorGate.png");
    //TODO: delete the line below
    // QPixmap NOT_GATE(":/icons/notGate.png");

    QPixmap notGatePixmap(":/icons/notGate.png");
    ui->intializedNotGate->setPixmap(notGatePixmap.scaled(105, 105, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->intializedNotGate->setAlignment(Qt::AlignCenter);



    ui->andGateLabel->setPixmap(AND_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->orGateLabel->setPixmap(OR_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->nandGateLabel->setPixmap(NAND_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->norGateLabel->setPixmap(NOR_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->xorGateLabel->setPixmap(XOR_GATE.scaled(100,100, Qt::KeepAspectRatio));
    // ui->notGateLabel->setPixmap(NOT_GATE.scaled(100, 100, Qt::KeepAspectRatio));


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
    // ui->notGateLabel->setParent(ui->groupBox);
    // ui->notGateLabel->setGateName("NOT_GATE");
}

LevelsView::~LevelsView()
{
    delete ui;

}

void LevelsView::on_pushButton_clicked()
{
    cout << "go clicked" << endl;
}

void LevelsView::on_pushButton_2_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_3_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_4_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_5_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_6_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_7_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_8_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_9_clicked(){
    cout<< "go clicked" << endl;
}

void LevelsView::onHomeButtonClicked()
{
    emit homeClicked();
}

void LevelsView::on_homeButton_2_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_3_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_4_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_5_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_6_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_7_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_8_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_9_clicked(){
    emit homeClicked();
}
//Go to next level functions

void LevelsView::on_skipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void LevelsView::on_skipButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void LevelsView::on_skipButton_3_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void LevelsView::on_skipButton_4_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

void LevelsView::on_skipButton_5_clicked(){
    ui->stackedWidget->setCurrentIndex(5);
}

void LevelsView::on_skipButton_6_clicked(){
    ui->stackedWidget->setCurrentIndex(6);
}

void LevelsView::on_skipButton_7_clicked(){
    ui->stackedWidget->setCurrentIndex(7);
}

void LevelsView::on_skipButton_8_clicked(){
    ui->stackedWidget->setCurrentIndex(8);
}

void LevelsView::on_skipButton_9_clicked(){
    ui->stackedWidget->setCurrentIndex(9);
}
//Go back to previous level functions
void LevelsView::on_backToLevel1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_backToLevel1_2_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void LevelsView::on_backToLevel1_3_clicked(){
    ui->stackedWidget->setCurrentIndex(2);
}

void LevelsView::on_backToLevel1_4_clicked(){
    ui->stackedWidget->setCurrentIndex(3);
}

void LevelsView::on_backToLevel1_5_clicked(){
    ui->stackedWidget->setCurrentIndex(4);
}

void LevelsView::on_backToLevel1_6_clicked(){
    ui->stackedWidget->setCurrentIndex(5);
}

void LevelsView::on_backToLevel1_7_clicked(){
    ui->stackedWidget->setCurrentIndex(6);
}

void LevelsView::on_backToLevel1_8_clicked(){
    ui->stackedWidget->setCurrentIndex(7);
}

void LevelsView::on_goButtonLevelOne_clicked() {
    bool inputValue1 = (ui->levelOneInput1->text() == "1");
    bool inputValue2 = (ui->levelOneInput2->text() == "1");
    std::vector<bool> inputs{inputValue1, inputValue2};

    emit gotUserInput(inputs);
    emit calculateLevel(0);
}

void LevelsView::onResultReceived(bool successful) {
    QString lastGate = ui->graphicsView->lastDroppedGateName();
    if (successful) {
        if (lastGate != "AND_GATE") {
            QMessageBox::warning(this, "Gate Requirement", "you need an AND Gate dummy");
        } else {
            ui->stackedWidget->setCurrentIndex(1);
            QMessageBox::information(this, "Success", "Good job, on to level 2");
        }
    } else {
        QMessageBox::critical(this, "Level Failed", "Try again");
    }
}


