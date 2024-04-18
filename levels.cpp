#include "levels.h"
#include "ui_levels.h"
#include <iostream>
using namespace std;
levels::levels(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levels)
{
    ui->setupUi(this);

    connect (ui->homeButton, &QPushButton::clicked, this, &levels::onHomeButtonClicked);


    QPixmap pix(":/icons/andGate.png");
    QPixmap pix2(":/icons/orGate.png");
    QPixmap pix3(":/icons/nandGate.png");
    QPixmap pix4(":/icons/norGate.png");
    QPixmap pix5(":/icons/xorGate.png");
    QPixmap pix6(":/icons/notGate.png");


    ui->andGateLabel->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
    ui->orGateLabel->setPixmap(pix2.scaled(100, 100, Qt::KeepAspectRatio));
    ui->nandGateLabel->setPixmap(pix3.scaled(100, 100, Qt::KeepAspectRatio));
    ui->norGateLabel->setPixmap(pix4.scaled(100, 100, Qt::KeepAspectRatio));
    ui->xorGateLabel->setPixmap(pix5.scaled(100,100, Qt::KeepAspectRatio));
    ui->notGateLabel->setPixmap(pix6.scaled(100, 100, Qt::KeepAspectRatio));

    ui->andGateLabel->setParent(ui->groupBox);
    ui->orGateLabel->setParent(ui->groupBox);
    ui->nandGateLabel->setParent(ui->groupBox);
    ui->norGateLabel->setParent(ui->groupBox);
    ui->xorGateLabel->setParent(ui->groupBox);
    ui->notGateLabel->setParent(ui->groupBox);
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

void levels::on_backToLevel1_2_clicked(){
    ui->stackedWidget->setCurrentIndex(1);
}

void levels::on_backToLevel1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
