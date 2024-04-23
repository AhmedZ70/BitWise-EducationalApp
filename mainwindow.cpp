#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "Trainingdialog.h"

// Assuming PIXELS_PER_METER is defined as 100
const float PIXELS_PER_METER = 100.0f;
const float MAX_DISPLACEMENT = 50.0f; // Max displacement in pixels

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

    createButtonBody(ui->playButton, playButtonBody, ui->playButton->width(), ui->playButton->height());
    createButtonBody(ui->helpButton, helpButtonBody, ui->helpButton->width(), ui->helpButton->height());
    createButtonBody(ui->quitButton, quitButtonBody, ui->quitButton->width(), ui->quitButton->height());

    ui->playButton->installEventFilter(this);
    ui->helpButton->installEventFilter(this);
    ui->quitButton->installEventFilter(this);

    // Store initial positions
    originalXPlay = ui->playButton->x();
    originalXHelp = ui->helpButton->x();
    originalXQuit = ui->quitButton->x();
}

MainWindow::~MainWindow()
{
    delete timer;
    delete world;
    delete ui;
    delete levelsUi;
}


void MainWindow::updatePhysics() {
    world->Step(1.0f / 60.0f, 6, 2);

    updateButtonPosition(ui->playButton, playButtonBody, originalXPlay);
    updateButtonPosition(ui->helpButton, helpButtonBody, originalXHelp);
    updateButtonPosition(ui->quitButton, quitButtonBody, originalXQuit);
}

void MainWindow::updateButtonPosition(QPushButton *button, b2Body *body, int originalX) {
    b2Vec2 pos = body->GetPosition();
    int newX = static_cast<int>(pos.x * PIXELS_PER_METER);
    button->move(newX, button->y());

    // Reverse direction if max displacement is reached
    if (newX > originalX + MAX_DISPLACEMENT || newX < originalX - MAX_DISPLACEMENT) {
        b2Vec2 currentVelocity = body->GetLinearVelocity();
        body->SetLinearVelocity(b2Vec2(-currentVelocity.x, 0)); // Reverse direction
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
        body->SetLinearVelocity(b2Vec2(1.0f, 0)); // Start moving right
    } else if (body && event->type() == QEvent::HoverLeave) {
        body->SetLinearVelocity(b2Vec2(0, 0)); // Stop moving
        body->SetTransform(b2Vec2(button->x() / PIXELS_PER_METER, button->y() / PIXELS_PER_METER), body->GetAngle());
    }

    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::on_playButton_clicked() {
    qDebug() << "Current index before change:" << ui->stackedWidget->currentIndex();
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(levelsUi));
    qDebug() << "Current index after change:" << ui->stackedWidget->currentIndex();
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
