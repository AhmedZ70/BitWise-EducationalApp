#ifndef ELECTRICITYEFFECT_H
#define ELECTRICITYEFFECT_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>

class ElectricityEffect : public QWidget {
    Q_OBJECT

public:
    explicit ElectricityEffect(QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    void drawElectricity(QPainter& painter, QPoint start, QPoint end, int depth);
    void updateElectricity();
};

#endif // ELECTRICITYEFFECT_H
