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
    connect(this, &LevelsView::userGateSelected,gameModel,&GameModel::checkUserGate);
    connect(gameModel, &GameModel::correctGate, this, &LevelsView:: onCorrectGateReceived);
    connect (ui->goButtonLevelOne, &QPushButton::clicked, this, &LevelsView::on_pushButton_clicked);



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

    ui->intializedNotGate_2->setPixmap(notGatePixmap.scaled(105, 105, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    ui->intializedNotGate_2->setAlignment(Qt::AlignCenter);


    ui->andGateLabel->setPixmap(AND_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->orGateLabel->setPixmap(OR_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->nandGateLabel->setPixmap(NAND_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->norGateLabel->setPixmap(NOR_GATE.scaled(100, 100, Qt::KeepAspectRatio));
    ui->xorGateLabel->setPixmap(XOR_GATE.scaled(100,100, Qt::KeepAspectRatio));
    // ui->notGateLabel->setPixmap(NOT_GATE.scaled(100, 100, Qt::KeepAspectRatio));


    ui->andGateLabel->setParent(ui->groupBox);
    ui->andGateLabel->setGateName("AND");
    ui->orGateLabel->setParent(ui->groupBox);
    ui->orGateLabel->setGateName("OR");
    ui->nandGateLabel->setParent(ui->groupBox);
    ui->nandGateLabel->setGateName("NAND");
    ui->norGateLabel->setParent(ui->groupBox);
    ui->norGateLabel->setGateName("NOR");
    ui->xorGateLabel->setParent(ui->groupBox);
    ui->xorGateLabel->setGateName("XOR");
}

LevelsView::~LevelsView()
{
    delete ui;

}

void LevelsView::on_pushButton_clicked()
{
    currentLevel = 1;
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_pushButton_2_clicked(){
    currentLevel = 2;
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_pushButton_3_clicked(){
    currentLevel = 3;
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_pushButton_4_clicked(){
    currentLevel = 4;
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_pushButton_5_clicked(){
    currentLevel = 5;
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_pushButton_6_clicked(){
    currentLevel = 6;
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_pushButton_7_clicked(){
    currentLevel = 7;
    goClickedTrainingLevel(currentLevel);
}


void LevelsView::on_pushButton_8_clicked(){
    currentLevel = 8;
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_9_clicked(){
    currentLevel = 9;
    cout<< "go clicked" << endl;
}

void LevelsView::on_pushButton_10_clicked(){
    currentLevel = 10;
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

void LevelsView::on_homeButton_10_clicked(){
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

void LevelsView::on_skipButton_10_clicked(){
    ui->stackedWidget->setCurrentIndex(10);
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

void LevelsView::on_backToLevel1_9_clicked(){
    ui->stackedWidget->setCurrentIndex(8);
}



void LevelsView ::goClickedTrainingLevel(int level){
    bool inputValue1 = getFirstUserInput(level);
    bool inputValue2 = getSecondUserInput(level);
    std::vector<bool> inputs{inputValue1, inputValue2};

    emit gotUserInput(inputs,level);
}
void LevelsView::onResultReceived(bool successful) {
    //QString lastGate = ui->graphicsView->lastDroppedGateName();
    if (successful) {
             ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
            QMessageBox::information(this, "Success", "Good job, on to the next level");

    } else {
        QMessageBox::critical(this, "Level Failed", "Try again");
    }
}
// void LevelsView::onResultReceived(bool successful) {
//     QString lastGate = ui->graphicsView->lastDroppedGateName();
//     if (successful) {
//         if (lastGate != "AND_GATE") {
//             QMessageBox::warning(this, "Gate Requirement", "you need an AND Gate dummy");
//         } else {
//             ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
//             QMessageBox::information(this, "Success", "Good job, on to level 2");
//         }
//     } else {
//         QMessageBox::critical(this, "Level Failed", "Try again");
//     }
// }

bool LevelsView::getFirstUserInput(int level)
{
    switch(level){
    case 1:
        return (ui->levelOneInput1->text() == "1");
    case 2:
        return (ui->lineEdit_3->text() == "1");
    case 3:
        return (ui->lineEdit_5->text() == "1");
    case 4:
        return (ui->lineEdit_7->text() == "1");

    case 5:
        return (ui->lineEdit_9->text() == "1");

    case 6:
        return (ui -> lineEdit_11 -> text() == "1");
    }


}

bool LevelsView::getSecondUserInput(int level)
{
    switch(level){
    case 1:
        return (ui->levelOneInput2->text() == "1");
    case 2:
        return (ui->lineEdit_4->text() == "1");
    case 3:
        return (ui->lineEdit_6->text() == "1");

    case 4:
        return (ui->lineEdit_8->text() == "1");

    case 5:
        return (ui->lineEdit_10->text() == "1");

    case 6:
        return (ui -> lineEdit_12 -> text() == "1");
    }

}

void LevelsView::on_goButtonLevel8_clicked()
{
    QString gateOneType = ui->gateOneLevel8->lastDroppedGateName();
    QString gateTwoType = ui->gateTwoLevel8->lastDroppedGateName();
    QString gateThreeType = ui->gateThreeLevel8->lastDroppedGateName();


    std::vector<std::string> gateTypes = {
        gateOneType.toStdString(),
        gateTwoType.toStdString(),
        gateThreeType.toStdString()
    };
    gameModel->setGateDropped(gateTypes, 8);

    userFirstInput = ui->level8Input1->text() == "1";
    userSecondInput = ui->level8Input2->text() == "1";
    userThirdInput = ui->level8Input3->text() == "1";
    userFourthInput = ui->level8Input4->text() == "1";
    std::vector<bool> inputs{userFirstInput, userSecondInput,
                             userThirdInput, userFourthInput};

    emit gotUserInput(inputs,8);



}

QString LevelsView::getLastDroppedGate(int level)
{
    QString lastGate;
    switch(level){
    case 1:
        lastGate = ui->graphicsView->lastDroppedGateName();
        return lastGate;
    case 2:
        lastGate = ui->graphicsView_2->lastDroppedGateName();
        return lastGate;
    case 3:
        lastGate = ui->graphicsView_3->lastDroppedGateName();
        return lastGate;
    case 4:
        lastGate = ui->graphicsView_4->lastDroppedGateName();
        return lastGate;

    case 5:
        lastGate = ui->graphicsView_5->lastDroppedGateName();
        return lastGate;


    case 6:
        lastGate = ui->graphicsView_6->lastDroppedGateName();
        return lastGate;
    }

}

void LevelsView:: onCorrectGateReceived(bool correct)
{
    correctGateDragged = correct;
}
