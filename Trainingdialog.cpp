#include "TrainingDialog.h"
#include "ui_trainingdialog.h"
#include <QPixmap>
#include <QVBoxLayout>
#include <QStringList>


TrainingDialog::TrainingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TrainingDialog)
{
    ui->setupUi(this);
    setWindowTitle("Training Dialog");

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

void TrainingDialog::setupImageAndText(const QString& imagePath, const QString& text) {
    QPixmap pixmap(imagePath);
    ui->gate->setPixmap(pixmap.scaled(200, 200, Qt::KeepAspectRatio)); // Ensure the image fits
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
}
