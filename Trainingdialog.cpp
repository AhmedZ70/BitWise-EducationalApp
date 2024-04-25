#include "TrainingDialog.h"
#include "ui_trainingdialog.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QStringList>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April 22, 2024
 * @name TrainingDialog cpp file for assignment9
 * This cpp file implements the TrainingDialog class, which is used to display educational material
 * about logic gates in a dialog format, including images and truth tables.
 */
TrainingDialog::TrainingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TrainingDialog)
{
    ui->setupUi(this);
    setWindowTitle("Training Dialog");
    ui->truthTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Setup the initial image and text
    setupImageAndText(":/path/to/image.png", "Welcome to the Training Module");

    // Connect the close button signal to the close slot
    connect(ui->okButton, &QPushButton::clicked, this, &QDialog::accept);

    QStringList horizontalHeaders;
    horizontalHeaders << "Input A" << "Input B" << "Output";
    ui->truthTable->setHorizontalHeaderLabels(horizontalHeaders);

    ui->truthTable->setItem(0, 0, new QTableWidgetItem("0"));
    ui->truthTable->setItem(0, 1, new QTableWidgetItem("0"));
    ui->truthTable->setItem(0, 2, new QTableWidgetItem("0"));

    ui->truthTable->setItem(1, 0, new QTableWidgetItem("1"));
    ui->truthTable->setItem(1, 1, new QTableWidgetItem("0"));
    ui->truthTable->setItem(1, 2, new QTableWidgetItem("0"));

    ui->truthTable->setItem(2, 0, new QTableWidgetItem("0"));
    ui->truthTable->setItem(2, 1, new QTableWidgetItem("1"));
    ui->truthTable->setItem(2, 2, new QTableWidgetItem("0"));

    ui->truthTable->setItem(3, 0, new QTableWidgetItem("1"));
    ui->truthTable->setItem(3, 1, new QTableWidgetItem("1"));
    ui->truthTable->setItem(3, 2, new QTableWidgetItem("1"));
}

TrainingDialog::~TrainingDialog() {
    delete ui;
}

void TrainingDialog::setupImageAndText(QString image,  QString text) {
    QPixmap gateImage(image);
    ui->gate->setPixmap(gateImage.scaled(200, 200, Qt::KeepAspectRatio));
    ui->gateDescription->setText(text);


}

void TrainingDialog:: setTruthTable(std::string gate)
{
    if(gate == "OR")
    {
        ui->truthTable->setItem(0, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 2, new QTableWidgetItem("0"));

        ui->truthTable->setItem(1, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(1, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(1, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(2, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(2, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(2, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(3, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 2, new QTableWidgetItem("1"));

    }

    else if(gate == "NOR")
    {
        ui->truthTable->setItem(0, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(1, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(1, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(1, 2, new QTableWidgetItem("0"));

        ui->truthTable->setItem(2, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(2, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(2, 2, new QTableWidgetItem("0"));

        ui->truthTable->setItem(3, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 2, new QTableWidgetItem("0"));

    }

    else if(gate == "NAND")
    {
        ui->truthTable->setItem(0, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(1, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(1, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(1, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(2, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(2, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(2, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(3, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 2, new QTableWidgetItem("0"));

    }

    else if(gate == "XOR")
    {
        ui->truthTable->setItem(0, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(0, 2, new QTableWidgetItem("0"));

        ui->truthTable->setItem(1, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(1, 1, new QTableWidgetItem("0"));
        ui->truthTable->setItem(1, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(2, 0, new QTableWidgetItem("0"));
        ui->truthTable->setItem(2, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(2, 2, new QTableWidgetItem("1"));

        ui->truthTable->setItem(3, 0, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 1, new QTableWidgetItem("1"));
        ui->truthTable->setItem(3, 2, new QTableWidgetItem("0"));

    }

    else if(gate == "NOT")
    {
        ui->truthTable->hide();
    }
}
