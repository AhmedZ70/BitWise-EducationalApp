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
    connect(this, &LevelsView::levelChanged, gameModel,&GameModel::onGetCurrentLevel);

    QPixmap AND_GATE(":/icons/andGate.png");
    QPixmap OR_GATE(":/icons/orGate.png");
    QPixmap NAND_GATE(":/icons/nandGate.png");
    QPixmap NOR_GATE(":/icons/norGate.png");
    QPixmap XOR_GATE(":/icons/xorGate.png");

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

void LevelsView::on_goButtonLevelOne_clicked()
{
    currentLevel = 1;
    emit levelChanged(currentLevel);
    goClickedTrainingLevel(currentLevel);
}
void LevelsView::on_goButtonLevelTwo_clicked()
{
    currentLevel = 2;
    emit levelChanged(currentLevel);
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_goButtonLevelThree_clicked()
{
    currentLevel = 3;
    emit levelChanged(currentLevel);
    goClickedTrainingLevel(currentLevel);
}


void LevelsView::on_goButtonLevelFour_clicked()
{
    currentLevel = 4;
    emit levelChanged(currentLevel);
    goClickedTrainingLevel(currentLevel);
}
void LevelsView::on_goButtonLevelFive_clicked()
{
    currentLevel = 5;
    emit levelChanged(currentLevel);
    goClickedTrainingLevel(currentLevel);
}

void LevelsView::on_goButtonLevelSix_clicked()
{
    currentLevel = 6;
    emit levelChanged(currentLevel);
    goClickedTrainingLevel(currentLevel);
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

void LevelsView::on_homeButton_11_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_12_clicked(){
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

void LevelsView::on_skipButton_11_clicked(){
    ui->stackedWidget->setCurrentIndex(11);
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
void LevelsView::on_backToLevel1_10_clicked(){
    ui->stackedWidget->setCurrentIndex(8);
}

void LevelsView::on_backToLevel1_12_clicked(){
    ui->stackedWidget->setCurrentIndex(9);
}

void LevelsView::on_backToLevel1_11_clicked(){
    ui->stackedWidget->setCurrentIndex(10);
}

void LevelsView::goClickedTrainingLevel(int level) {
    std::vector<bool> inputs = getUserInputs(level);
    QString lastGate = getLastDroppedGate(level);
    emit userGateSelected(lastGate.toStdString());

    QString warning = "You must use the specified gate to solve this circuit.";
    if (!correctGateDragged) {
        QMessageBox::warning(this, "Gate Requirement", warning);
        return;
    }

    emit gotUserInput(inputs);
}

void LevelsView::onResultReceived(bool successful) {
    //QString lastGate = ui->graphicsView->lastDroppedGateName();
    if (successful) {

            QMessageBox::information(this, "Success", "Good job, on to the next level");
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);

    } else {
        QMessageBox::critical(this, "Level Failed", "Try again");
    }
}

std::vector<bool> LevelsView::getUserInputs(int level) {
    std::vector<bool> inputs;
    inputs.reserve(2);
    switch(level) {
    case 1:
        inputs.push_back(ui->levelOneInput1->text() == "1");
        inputs.push_back(ui->levelOneInput2->text() == "1");
        break;
    case 2:
        inputs.push_back(ui->levelTwoInput1->text() == "1");
        inputs.push_back(ui->levelTwoInput2->text() == "1");
        break;
    case 3:
        inputs.push_back(ui->levelThreeInput1->text() == "1");
        inputs.push_back(ui->levelThreeInput2->text() == "1");
        break;
    case 4:
        inputs.push_back(ui->levelFourInput1->text() == "1");
        inputs.push_back(ui->levelFourInput2->text() == "1");
        break;
    case 5:
        inputs.push_back(ui->levelFiveInput1->text() == "1");
        inputs.push_back(ui->levelFiveInput2->text() == "1");
        break;
    case 6:
        inputs.push_back(ui->levelSixInput1->text() == "1");
        inputs.push_back(ui->levelSixInput2->text() == "1");
        break;
    default:
        inputs = {false, false};
        break;
    }
    return inputs;
}


void LevelsView::processLevelInputs(const std::vector<Custom_GraphicsView*>& gateDropAreas,
                                    const std::vector<CustomLineEdit*>& inputs)
{
    std::vector<std::string> gateTypes;
    for (auto& gate : gateDropAreas) {
        gateTypes.push_back(gate->lastDroppedGateName().toStdString());
    }
    try {
        std::vector<bool> inputValues;
        for (auto& input : inputs) {
            inputValues.push_back(input->text() == "1");
        }
        gameModel->setGateDropped(gateTypes);
        emit gotUserInput(inputValues);
    } catch (const std::invalid_argument& e) {
        QMessageBox::warning(this, "Error", e.what());
    }

}



void LevelsView::on_goButtonLevelSeven_clicked()
{
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel7, ui->gateTwoLevel7};
    std::vector<CustomLineEdit*> inputs = {ui->level7Input1, ui->level7Input2, ui->level7Input3};
    processLevelInputs(gates, inputs);
}

void LevelsView::on_goButtonLevelEight_clicked()
{
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel8, ui->gateTwoLevel8, ui->gateThreeLevel8};
    std::vector<CustomLineEdit*> inputs = {ui->level8Input1, ui->level8Input2, ui->level8Input3, ui->level8Input4};
    emit levelChanged(8);
    processLevelInputs(gates, inputs);
}

void LevelsView::on_goButtonLevelNine_clicked()
{
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel9, ui->gateTwoLevel9, ui->gateThreeLevel9};
    std::vector<CustomLineEdit*> inputs = {ui->level9Input1, ui->level9Input2, ui->level9Input3, ui->level9Input4};
     emit levelChanged(9);
    processLevelInputs(gates, inputs);
}

void LevelsView::on_goButtonLevelTen_clicked()
{
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel10, ui->gateTwoLevel10, ui->gateThreeLevel10, ui->gateFourLevel10, ui->gateFiveLevel10};
    std::vector<CustomLineEdit*> inputs = {ui->level10Input1, ui->level10Input2, ui->level10Input3, ui->level10Input4, ui->level10Input5, ui->level10Input6};
    emit levelChanged(10);
    processLevelInputs(gates, inputs);
}

void LevelsView::on_goButtonLevelEleven_clicked()
{
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel11, ui->gateTwoLevel11, ui->gateThreeLevel11, ui->gateFourLevel11, ui->gateFiveLevel11};
    std::vector<CustomLineEdit*> inputs = {ui->level11Input1, ui->level11Input2, ui->level11Input3, ui->level11Input4, ui->level11Input5, ui->level11Input6};
    emit levelChanged(11);
    processLevelInputs(gates, inputs);
}

void LevelsView::on_goButtonLevelTwelve_clicked()
{
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel12, ui->gateTwoLevel12, ui->gateThreeLevel12, ui->gateFourLevel12, ui->gateFiveLevel12, ui->gateSixLevel12, ui->gateSevenLevel12};
    std::vector<CustomLineEdit*> inputs = {ui->level12Input1, ui->level12Input2, ui->level12Input3, ui->level12Input4, ui->level12Input5, ui->level12Input6, ui->level12Input7, ui->level12Input8};
    emit levelChanged(12);
    processLevelInputs(gates, inputs);
}

QString LevelsView::getLastDroppedGate(int level)
{
    QString lastGate;
    switch(level){
    case 1:
        lastGate = ui->gateOneLevel1->lastDroppedGateName();
        return lastGate;
    case 2:
        lastGate = ui->gateOneLevel2->lastDroppedGateName();
        return lastGate;
    case 3:
        lastGate = ui->gateOneLevel3->lastDroppedGateName();
        return lastGate;
    case 4:
        lastGate = ui->gateOneLevel4->lastDroppedGateName();
        return lastGate;

    case 5:
        lastGate = ui->gateOneLevel5->lastDroppedGateName();
        return lastGate;

    case 6:
        lastGate = ui->gateOneLevel6->lastDroppedGateName();
        return lastGate;
    }

}

void LevelsView:: onCorrectGateReceived(bool correct)
{
    correctGateDragged = correct;
}















