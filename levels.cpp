#include "levels.h"
#include "ui_levels.h"
#include <iostream>
using namespace std;
levels::levels(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::levels)
{
    ui->setupUi(this);
<<<<<<< Updated upstream
=======

    connect (ui->homeButton, &QPushButton::clicked, this, &levels::onHomeButtonClicked);


    QPixmap pix(":/icons/andGate.png");
    QPixmap pix2(":/icons/orGate.png");
    QPixmap pix3(":/icons/nandGate.png");
    QPixmap pix4(":/icons/norGate.png");

    // Assuming ui->andGateLabel, ui->orGateLabel, ui->nandGateLabel, and ui->norGateLabel are correct QLabel pointers
    ui->andGateLabel->setPixmap(pix.scaled(100, 100, Qt::KeepAspectRatio));
    ui->orGateLabel->setPixmap(pix2.scaled(100, 100, Qt::KeepAspectRatio)); // Fixed label name
    ui->nandGateLabel->setPixmap(pix3.scaled(100, 100, Qt::KeepAspectRatio)); // Fixed label name
    ui->norGateLabel->setPixmap(pix4.scaled(100, 100, Qt::KeepAspectRatio)); // Fixed label name and pixmap

    // Assuming ui->groupBox is the correct QGroupBox
    ui->andGateLabel->setParent(ui->groupBox);
    ui->orGateLabel->setParent(ui->groupBox); // Fixed label name
    ui->nandGateLabel->setParent(ui->groupBox); // Fixed label name
    ui->norGateLabel->setParent(ui->groupBox); // Fixed label name

    scene = new QGraphicsScene();
    connect(ui->graphicsView, SIGNAL(itemdrop(QPixmap)), this, SLOT(Image_View_Image_Enter(QPixmap)));

}

void levels::Image_View_Image_Enter(QPixmap pixmap){
    if(scene->items().count() >0 ) scene->clear();
    scene->addPixmap(pixmap);
    scene->setSceneRect(pixmap.rect());
    ui->graphicsView->setScene(scene);
    ui->graphicsView->viewport()->update();
    ui->graphicsView->update();
    ui->graphicsView->show();
>>>>>>> Stashed changes
}

levels::~levels()
{
    delete ui;
<<<<<<< Updated upstream
=======
    delete scene;


>>>>>>> Stashed changes
}

void levels::on_pushButton_clicked()
{
    cout << "go clicked" << endl;
}


void levels::on_homeButton_clicked()
{
    emit homeClicked();
}

