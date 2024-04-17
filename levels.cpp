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

    ui->andGateLabel->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
    ui->orGateLabel->setPixmap(pix2.scaled(100, 100, Qt::KeepAspectRatio));
    ui->nandGateLabel->setPixmap(pix3.scaled(100, 100, Qt::KeepAspectRatio));
    ui->norGateLabel->setPixmap(pix4.scaled(100, 100, Qt::KeepAspectRatio));

    ui->andGateLabel->setParent(ui->groupBox);
    ui->orGateLabel->setParent(ui->groupBox);
    ui->nandGateLabel->setParent(ui->groupBox);
    ui->norGateLabel->setParent(ui->groupBox);
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


void levels::on_skipButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void levels::on_backToLevel1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}
