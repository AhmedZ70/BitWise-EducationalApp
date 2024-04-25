#include "electricity.h"

Electricity::Electricity(QWidget* parent)
    : QWidget(parent) {
    setAttribute(Qt::WA_TranslucentBackground);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Electricity::updateElectricity);
    timer->start(100);
}

void Electricity::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::yellow, 1));


    //Starting point
    QPoint start(rect().left(), rect().bottom() - 50);
    QPoint end(rect().right(), rect().bottom() - 50);
    drawElectricity(painter, start, end, 10);
}

void Electricity::drawElectricity(QPainter& painter, QPoint start, QPoint end, int depth) {

    //end recursion
    if (depth == 0) {
        painter.drawLine(start, end);
        return;
    }

    //generate random point
    int middleX = (start.x() + end.x()) / 2 + QRandomGenerator::global()->bounded(-5, 5);
    int middleY = (start.y() + end.y()) / 2 + QRandomGenerator::global()->bounded(-5, 5);

    QPoint midPoint(middleX, middleY);

    //recursive call
    drawElectricity(painter, start, midPoint, depth - 1);
    drawElectricity(painter, midPoint, end, depth - 1);
}

void Electricity::updateElectricity() {
    update();
}
