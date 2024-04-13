#ifndef LEVELS_H
#define LEVELS_H

#include <QWidget>

namespace Ui {
class levels;
}

class levels : public QWidget
{
    Q_OBJECT

public:
    explicit levels(QWidget *parent = nullptr);
    ~levels();

private:
    Ui::levels *ui;
};

#endif // LEVELS_H
