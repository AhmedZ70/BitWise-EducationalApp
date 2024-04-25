#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "Trainingdialog.h"
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>
#include "electricity.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April 22, 2024
 * @name MainWindow cpp file for assignment9
 * This cpp file implements the MainWindow class methods, which serves as the main interface
 * for a physics-enabled UI application, integrating Box2D for dynamic button interactions.
 */

// Assuming PIXELS_PER_METER is defined as 100
const float PIXELS_PER_METER = 100.0f;
const float MAX_DISPLACEMENT = 2.0f;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), levelsUi(new LevelsView()), world(new b2World(b2Vec2(0.0f, 0.0f))) {
    ui->setupUi(this);
    ui->stackedWidget->addWidget(levelsUi);
    resize(1300, 800);
    setFixedSize(1300, 800);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePhysics);
    timer->start(16);
    connect(levelsUi, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(ui->quitButton, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);
    connect(ui->stackedWidget, &QStackedWidget::currentChanged, this, &MainWindow::onStackedWidgetChange);
    connect(ui->helpButton, &QPushButton::clicked, this, &MainWindow::showHelpDialog);

    createButtonBody(ui->playButton, playButtonBody, ui->playButton->width(), ui->playButton->height());
    createButtonBody(ui->helpButton, helpButtonBody, ui->helpButton->width(), ui->helpButton->height());
    createButtonBody(ui->quitButton, quitButtonBody, ui->quitButton->width(), ui->quitButton->height());

    ui->playButton->installEventFilter(this);
    ui->helpButton->installEventFilter(this);
    ui->quitButton->installEventFilter(this);

    initializeHelpTexts();
    setupHelpDialog();

    // Store initial positions
    originalXPlay = ui->playButton->x();
    originalXHelp = ui->helpButton->x();
    originalXQuit = ui->quitButton->x();

    QPixmap gameTitle(":/icons/BitWiseTitle.png");
    QSize scaledSize = gameTitle.size() * 0.8;
    gameTitle= gameTitle.scaled(scaledSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
    movingGameTitle = new QLabel(this);
    movingGameTitle->setPixmap(gameTitle);
    movingGameTitle->setFixedSize(gameTitle.size());
    movingGameTitle->setGeometry(10, 175, 200, 50);
    movingGameTitle->raise();
    createLabelBody(movingGameTitle, gameTitleBody);

    electricity = new ElectricityEffect(this);
    int lightningHeight = this->height() / 6;
    electricity ->setGeometry(0, 0, this->width(), lightningHeight);
    electricity ->raise();
    electricity ->show();
}

MainWindow::~MainWindow()
{
    delete timer;
    delete world;
    delete ui;
    delete levelsUi;
    delete electricity;
}


void MainWindow::updatePhysics() {
    world->Step(1.0f / 60.0f, 6, 2);

    updateButtonPosition(ui->playButton, playButtonBody, originalXPlay);
    updateButtonPosition(ui->helpButton, helpButtonBody, originalXHelp);
    updateButtonPosition(ui->quitButton, quitButtonBody, originalXQuit);

    b2Vec2 pos = gameTitleBody->GetPosition();
    int newX = static_cast<int>(pos.x * PIXELS_PER_METER);
    if (newX > this->width()) {  // Check if the label moves off-screen
        gameTitleBody->SetTransform(b2Vec2(-movingGameTitle->width() / PIXELS_PER_METER, pos.y), 0);
    }
    else {
        movingGameTitle->move(newX, movingGameTitle->y());
    }
}

void MainWindow::updateButtonPosition(QPushButton *button, b2Body *body, int originalX) {
    b2Vec2 pos = body->GetPosition();
    int newX = static_cast<int>(pos.x * PIXELS_PER_METER);
    button->move(newX, button->y());

    const float hysteresis = 0.1f;


    if (newX > originalX + MAX_DISPLACEMENT + hysteresis) {
        if (body->GetLinearVelocity().x > 0) {
            body->SetLinearVelocity(b2Vec2(-std::abs(body->GetLinearVelocity().x), 0));
        }
    } else if (newX < originalX - MAX_DISPLACEMENT - hysteresis) {
        if (body->GetLinearVelocity().x < 0) {
            body->SetLinearVelocity(b2Vec2(std::abs(body->GetLinearVelocity().x), 0));
        }
    }
}

void MainWindow::createButtonBody(QPushButton* button, b2Body*& body, float width, float height)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    float initialX = button->x() / 100.0f;
    float initialY = button->y() / 100.0f;
    bodyDef.position.Set(initialX, initialY);
    body = world->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(width / 2.0f / 100.0f, height / 2.0f / 100.0f);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);

}

bool MainWindow::eventFilter(QObject *obj, QEvent *event) {
    QPushButton *button = qobject_cast<QPushButton *>(obj);
    b2Body *body = nullptr;

    if (button == ui->playButton) body = playButtonBody;
    else if (button == ui->helpButton) body = helpButtonBody;
    else if (button == ui->quitButton) body = quitButtonBody;

    if (body && event->type() == QEvent::HoverEnter) {
        body->SetLinearVelocity(b2Vec2(0.75f, 0));
    } else if (body && event->type() == QEvent::HoverLeave) {
        body->SetLinearVelocity(b2Vec2(0, 0));
        body->SetTransform(b2Vec2(button->x() / PIXELS_PER_METER, button->y() / PIXELS_PER_METER), body->GetAngle());
    }

    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_playButton_clicked() {
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(levelsUi));
    TrainingDialog *dialog = new TrainingDialog();
    QString trainingDialog = "This is an AND gate. The AND gate takes in 2 or 3 inputs and computes a single ouput.\n"
                             "In order for the AND gate to calculate to TRUE, all inputs must be TRUE.\n"
                             "The truth table for the AND gate illustrates this and is shown below";
    dialog->setupImageAndText(":/icons/andGate.png", trainingDialog);
    dialog->exec();

}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::initializeHelpTexts()
{
    helpTexts["AND Gates"] = "The AND gate is a digital logic gate that outputs true only if all its inputs are true.";
    helpTexts["OR Gates"] = "The OR gate is a digital logic gate that outputs true if at least one of its inputs is true.";
    helpTexts["NOT Gates"] = "The NOT gate, also known as an inverter, is a digital logic gate that outputs the opposite of its input.";
    helpTexts["NAND Gates"] = "The NAND gate outputs false only when all its inputs are true. It is an inverted AND gate.";
    helpTexts["NOR Gates"] = "The NOR gate outputs true only when all its inputs are false. It is an inverted OR gate.";
    helpTexts["XOR Gates"] = "The XOR gate (exclusive OR) is a digital logic gate that outputs true only when its inputs are different.";
    helpTexts["Bits"] = "A bit (binary digit) is the basic unit of information in computing and digital communications. A bit can have only one of two values: 0 or 1, often corresponding to the electrical values of off or on, respectively.";
    helpTexts["Binary Operations"] = "Binary operations involve arithmetic on binary numbers, which are composed of bits. The most common binary operations are addition, subtraction, and multiplication. Binary operations are fundamental in the functioning of digital electronics, such as processors and logic gates.";
    helpTexts["Binary Numbers"] = "Binary numbers are represented using only two symbols: 0 and 1. Each digit in a binary number is called a bit. For example, the binary number '1010' represents the decimal number 10, with each position representing a power of two, starting from the rightmost digit."
                                  " Bits are also often treated as boolean values, with 0 representing false and 1 representing true. This is fundamental to understanding how logic gates work, as they compute boolean logic operations by treating bits as boolean values. ";
}



void MainWindow::setupHelpDialog() {
    helpDialog = new QDialog(this);
    helpDialog->setWindowTitle("Help Information");
    helpDialog->resize(400, 200);

    QVBoxLayout *layout = new QVBoxLayout(helpDialog);
    helpOptions = new QComboBox(helpDialog);
    helpContent = new QLabel(helpDialog);
    helpContent->setWordWrap(true);
    QPushButton *backButton = new QPushButton("Back", helpDialog);

    layout->addWidget(helpOptions);
    layout->addWidget(helpContent);
    layout->addWidget(backButton);

    connect(helpOptions, SIGNAL(currentIndexChanged(int)), this, SLOT(updateHelpContent()));
    connect(backButton, &QPushButton::clicked, helpDialog, &QDialog::hide);


    foreach (const QString &key, helpTexts.keys()) {
        helpOptions->addItem(key, helpTexts[key]);
    }
}


void MainWindow::showHelpDialog() {
    helpDialog->show();
}

void MainWindow::updateHelpContent() {
    int index = helpOptions->currentIndex();
    QString helpText = helpOptions->itemData(index).toString();
    helpContent->setText(helpText);
}

void MainWindow::createLabelBody(QLabel *label, b2Body*& body) {
    b2BodyDef bodyDef;
    bodyDef.type = b2_kinematicBody;
    float initialX = label->x() / PIXELS_PER_METER;
    float initialY = label->y() / PIXELS_PER_METER;
    bodyDef.position.Set(initialX, initialY);
    body = world->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(label->width() / 2.0f / PIXELS_PER_METER, label->height() / 2.0f / PIXELS_PER_METER);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    body->CreateFixture(&fixtureDef);

    // Set initial velocity to move across the screen
    body->SetLinearVelocity(b2Vec2(2.0f, 0));
}

void MainWindow::onStackedWidgetChange(int index) {
    if (index == 0) {
        movingGameTitle->show();
        electricity->show();
        if (gameTitleBody) {
            gameTitleBody->SetLinearVelocity(b2Vec2(2.0f, 0));

        }
    }

    else {
        movingGameTitle->hide();
        electricity->hide();
        if (gameTitleBody) {
            gameTitleBody->SetLinearVelocity(b2Vec2(0, 0));

        }
    }
}

