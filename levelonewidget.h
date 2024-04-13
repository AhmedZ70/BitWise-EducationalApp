#ifndef LEVELONEWIDGET_H
#define LEVELONEWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QLabel>
#include <QIntValidator>
#include <QHBoxLayout>
#include <QVBoxLayout>

class LevelOneWidget : public QWidget {
    Q_OBJECT

public:
    LevelOneWidget(QWidget *parent = nullptr) : QWidget(parent) {
        // Initialize the scene and view for the gate widget
        QGraphicsScene *scene = new QGraphicsScene(this);
        QGraphicsView *view = new QGraphicsView(scene, this);

        // Create input fields with binary (0 or 1) validators
        QLineEdit *input1 = new QLineEdit(this);
        QLineEdit *input2 = new QLineEdit(this);
        QIntValidator *validator = new QIntValidator(0, 1, this);
        input1->setValidator(validator);
        input2->setValidator(validator);

        // Create output field
        QLabel *output = new QLabel("Output", this);
        output->setAlignment(Qt::AlignCenter);

        // Create the 'Go' button
        QPushButton *goButton = new QPushButton("Go", this);
        connect(goButton, &QPushButton::clicked, this, &LevelOneWidget::evaluateLogic);

        // Arrange the widgets in the layout
        QVBoxLayout *mainLayout = new QVBoxLayout(this);
        mainLayout->addWidget(view); // Add the graphics view
        mainLayout->addWidget(input1);
        mainLayout->addWidget(input2);
        mainLayout->addWidget(output);
        mainLayout->addWidget(goButton);

        // Set the main layout
        this->setLayout(mainLayout);

        // Set up the gate widget and add it to the scene...
    }

private slots:
    void evaluateLogic() {
        // Implement the logic evaluation of the gate based on the inputs
        // Update the output label accordingly
    }

    // Add additional slots for handling drag-and-drop if needed
};

#endif // LEVELONEWIDGET_H
