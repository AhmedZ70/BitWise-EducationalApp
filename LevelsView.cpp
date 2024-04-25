#include "LevelsView.h"
#include "ui_LevelsView.h"
#include <QMessageBox>
#include <vector>
#include "Trainingdialog.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April 22, 2024
 * @name LevelsView cpp file for assignment9
 * This header file implements the LevelsView class methods, which are responsible for displaying
 * and managing the game levels in the user interface.
 */

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
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel6};
    std::vector<CustomLineEdit*> inputs = {ui->level6Input1, ui->level6Input2};
    emit levelChanged(6);
    processLevelInputs(gates, inputs);
}
void LevelsView::on_goButtonLevelSeven_clicked()
{
    std::vector<Custom_GraphicsView*> gates = {ui->gateOneLevel7, ui->gateTwoLevel7};
    std::vector<CustomLineEdit*> inputs = {ui->level7Input1, ui->level7Input2, ui->level7Input3};
    emit levelChanged(7);
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

void LevelsView::onHomeButtonClicked()
{
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_2_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}


void LevelsView::on_homeButton_3_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_4_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_5_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_6_clicked(){
    emit homeClicked();
}

void LevelsView::on_homeButton_7_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_8_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_9_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_10_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_11_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
}

void LevelsView::on_homeButton_12_clicked(){
    emit homeClicked();
    ui->stackedWidget->setCurrentIndex(0);
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
void LevelsView::on_skipTrainingButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
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

    if (successful) {
        if (ui->stackedWidget->currentIndex() == 11){
            QMessageBox msgBox;
            msgBox.setWindowTitle("All Levels Completed!");
            msgBox.setText("Congratulations on completing all the levels! Each circuit can be solved in multiple ways.");
            msgBox.setInformativeText("Would you like to return to the home screen or restart the first level to explore alternative strategies?");
            msgBox.setIcon(QMessageBox::Information);

            QPushButton *restartButton = msgBox.addButton("Back to Level One", QMessageBox::ActionRole);
            QPushButton *homeButton = msgBox.addButton("Go to Home", QMessageBox::AcceptRole);
            msgBox.addButton(QMessageBox::Cancel);

            msgBox.exec();

            if (msgBox.clickedButton() == homeButton) {
                emit homeClicked();
                ui->stackedWidget->setCurrentIndex(0);
            } else if (msgBox.clickedButton() == restartButton) {
                ui->stackedWidget->setCurrentIndex(6);
            }
        }

        else{
            QMessageBox::information(this, "Success", "Good job, on to the next level");
            ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() + 1);
        }

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



QString LevelsView::getLastDroppedGate(int level) {
    QString lastGate;
    switch(level) {
    case 1:
        lastGate = ui->gateOneLevel1->lastDroppedGateName();
        break;
    case 2:
        lastGate = ui->gateOneLevel2->lastDroppedGateName();
        break;
    case 3:
        lastGate = ui->gateOneLevel3->lastDroppedGateName();
        break;
    case 4:
        lastGate = ui->gateOneLevel4->lastDroppedGateName();
        break;
    case 5:
        lastGate = ui->gateOneLevel5->lastDroppedGateName();
        break;
    case 6:
        lastGate = ui->gateOneLevel6->lastDroppedGateName();
        break;
    default:
        lastGate = "";
        break;
    }
    return lastGate;
}


void LevelsView:: onCorrectGateReceived(bool correct)
{
    correctGateDragged = correct;
}


void LevelsView::on_stackedWidget_currentChanged(int index)
{
    if(index >5 || index < 1)
        return;

    QString image, text;
    TrainingDialog *dialog = new TrainingDialog();
    switch(index) {
    case 1:
        image = ":/icons/orGate.png";
        text = "This is an OR gate. The OR gate takes in 2 or 3 inputs and computes a single ouput.\n"
               "In order for the OR gate to calculate to True, at least one inputs must be True.\n"
               "The truth table for the OR gate illustrates this and is shown below";

        dialog->setTruthTable("OR");
        break;
    case 2:
        image = ":/icons/nandGate.png";
        text = "This is an NAND gate. The NAND gate takes in 2 or 3 inputs and computes a single ouput.\n"
               "The NAND gate will function similar to an AND gate, except it will negate its value before outputting it. "
               "Negating the output will simply flip the value: if it was originally True, it will be false, and if it was"
               "originally false, it will be true. The truth table for the NAND gate illustrates this and is shown below.";
         dialog->setTruthTable("NAND");
        break;
    case 3:
        image = ":/icons/norGate.png";
        text = "This is a NOR gate.The NOR gate takes in 2 or 3 inputs and computes a single ouput.\n"
               "The NOR gate will function similar to an OR gate, except it will negate its value before outputting it.\n"
               "Negating the output will simply flip the value: if it was originally True, it will be false, and if it was\n"
               "originally false, it will be true. The truth table for the NOR gate illustrates this and is shown below.";
         dialog->setTruthTable("NOR");
        break;

    case 4:
        image = ":/icons/xorGate.png";
        text = "This is a XOR Gate. The XOR gate takes in 2 or 3 inputs and compuets a single output.\n"
                "The XOR Gate functions a little differently than the previous gates you have learned about,as"
                "it will only compute to an output of True, if only one of its inputs is True."
                " So in order to get an output of true for a XOR gate, both the inputs must be different."
                " The truth table for the XOR gate illustrates this and is shown below.";
         dialog->setTruthTable("XOR");
        break;
    case 5:
        dialog->setTruthTable("NOT");
        image = ":/icons/notGate.png";
        text = "This is a NOT gate. The NOT gate is different than the other gates you have seen so far,"
               "as it only takes a single input and computes a single output. The NOT gate will simply "
               "negate, or flip, the input it is given. If the input is True(1), the output will be False(0),"
               "and if the input is False(0), the output will be True(1).";
        break;


    }


    dialog->setupImageAndText(image,text);
    dialog->exec();
}


















