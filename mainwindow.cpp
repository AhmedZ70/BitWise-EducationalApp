#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "Trainingdialog.h"
//#include "levelonewidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    levelsUi(new LevelsView()),
    world(new b2World(b2Vec2(0.0f, 0.0f))) // No gravity in a 2D UI context
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(levelsUi);
    resize(800, 600);
    connect(levelsUi, SIGNAL(homeClicked()), this, SLOT(moveHome()));
    connect(ui->quitButton, &QPushButton::clicked, this, &QCoreApplication::quit, Qt::QueuedConnection);

    // Setup physics world
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updatePhysics);
    timer->start(16); // Update physics at about 60Hz

    // Create physics bodies for the buttons
    createButtonBody(ui->playButton, playButtonBody, ui->playButton->width(), ui->playButton->height());
    createButtonBody(ui->helpButton, helpButtonBody, ui->helpButton->width(), ui->helpButton->height());
    createButtonBody(ui->quitButton, quitButtonBody, ui->quitButton->width(), ui->quitButton->height());

    ui->playButton->installEventFilter(this);
    ui->helpButton->installEventFilter(this);
    ui->quitButton->installEventFilter(this);

    originalX = ui->playButton->x();
    originalY = ui->playButton->y();  // Assuming all buttons start at the same y level
    maxDisplacement = 50; // Maximum displacement from the original position
}

MainWindow::~MainWindow()
{
    delete timer;
    delete world;
    delete ui;
    delete levelsUi;
}

void MainWindow::updatePhysics()
{
    world->Step(1.0f / 60.0f, 6, 2);

    // Update button positions based on physics bodies
    updateButtonPosition(ui->playButton, playButtonBody);
    updateButtonPosition(ui->helpButton, helpButtonBody);
    updateButtonPosition(ui->quitButton, quitButtonBody);
}
void MainWindow::on_playButton_clicked() {
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->indexOf(levelsUi));
    TrainingDialog *dialog = new TrainingDialog();
    QString trainingDialog = "This is an AND gate. The AND gate takes in 2 or 3 inputs and computes a single ouput.\n"
                             "In order for the AND gate to calculate to TRUE, all inputs must be TRUE.\n"
                             "The truth table for the AND gate illustrates this and is shown below";
    dialog->setupImageAndText(":/icons/andGate.png", trainingDialog);
    dialog->exec();
    //auto index = ui->stackedWidget->currentIndex();   // for debugging

}

void MainWindow::updateButtonPosition(QPushButton *button, b2Body *body)
{
    b2Vec2 pos = body->GetPosition();
    int newX = static_cast<int>(pos.x * pixelsPerMeter);
    button->move(newX, static_cast<int>(pos.y * pixelsPerMeter));

    if (newX >= originalX + maxDisplacement || newX <= originalX - maxDisplacement) {
        b2Vec2 currentVelocity = body->GetLinearVelocity();
        body->SetLinearVelocity(b2Vec2(-currentVelocity.x, 0));
    }
}

void MainWindow::createButtonBody(QPushButton* button, b2Body*& body, float width, float height)
{
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(button->x() / 100.0f, button->y() / 100.0f);
    body = world->CreateBody(&bodyDef);

    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(width / 2.0f / 100.0f, height / 2.0f / pixelsPerMeter);

    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    if (event->type() == QEvent::HoverEnter || event->type() == QEvent::HoverLeave) {
        QPushButton *button = qobject_cast<QPushButton *>(obj);
        b2Body *body = nullptr;

        if (button == ui->playButton) body = playButtonBody;
        else if (button == ui->helpButton) body = helpButtonBody;
        else if (button == ui->quitButton) body = quitButtonBody;

        if (body) {
            if (event->type() == QEvent::HoverEnter) {
                body->SetLinearVelocity(b2Vec2(1.0f, 0)); // Start moving right
            } else {
                body->SetLinearVelocity(b2Vec2(0, 0)); // Stop moving
                body->SetTransform(b2Vec2(originalX / 100.0f, originalY / 100.0f), body->GetAngle()); // Reset to original position
            }
            return true;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::moveHome()
{
    ui->stackedWidget->setCurrentIndex(0);
}
