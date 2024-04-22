#include "imageDialog.h"

ImageDialog::ImageDialog(const QString &imagePath, const QString &text, QWidget *parent)
    : QDialog(parent) {
    setWindowTitle("Image Dialog");
    resize(400, 300);
    // Create label for image
    QLabel *imageLabel = new QLabel(this);
    QPixmap pixmap(imagePath);
    imageLabel->setPixmap(pixmap.scaled(100, 300, Qt::KeepAspectRatio));

    // Create label for text
    QLabel *textLabel = new QLabel(text, this);
    textLabel->setAlignment(Qt::AlignCenter);

    // Create a layout and add widgets
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(imageLabel);
    layout->addWidget(textLabel);

    // Create close button
    QPushButton *closeButton = new QPushButton("Close", this);
    connect(closeButton, &QPushButton::clicked, this, &ImageDialog::accept);
    layout->addWidget(closeButton);

    // Set the dialog layout
    setLayout(layout);
}
