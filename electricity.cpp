#include "electricity.h"

ElectricityEffect::ElectricityEffect(QWidget* parent)
    : QWidget(parent) {
    setAttribute(Qt::WA_TranslucentBackground);
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &ElectricityEffect::updateElectricity);
    timer->start(100);
}

void ElectricityEffect::paintEvent(QPaintEvent* event) {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(QPen(Qt::yellow, 2));


    QPoint start(rect().left(), rect().bottom() - 50);
    QPoint end(rect().right(), rect().bottom() - 50);
    drawElectricity(painter, start, end, 10);
}

void ElectricityEffect::drawElectricity(QPainter& painter, QPoint start, QPoint end, int depth) {
    if (depth == 0) {
        painter.drawLine(start, end);
        return;
    }
    int middleX = (start.x() + end.x()) / 2 + QRandomGenerator::global()->bounded(-20, 20);
    int middleY = (start.y() + end.y()) / 2 + QRandomGenerator::global()->bounded(-20, 20);
    QPoint midPoint(middleX, middleY);
    drawElectricity(painter, start, midPoint, depth - 1);
    drawElectricity(painter, midPoint, end, depth - 1);
}

void ElectricityEffect::updateElectricity() {
    update();
}
