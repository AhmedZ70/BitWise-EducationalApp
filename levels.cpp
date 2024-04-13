#include "levels.h"
#include "ui_levels.h"
#include <iostream>
using namespace std;
levels::levels(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levels)
{
    ui->setupUi(this);
}

levels::~levels()
{
    delete ui;
}

void levels::on_pushButton_clicked()
{
    cout << "go clicked" << endl;
}


void levels::on_homeButton_clicked()
{
    emit homeClicked();
}

