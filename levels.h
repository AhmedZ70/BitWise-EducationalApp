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

private slots:
    void on_pushButton_clicked();

    void on_homeButton_clicked();

private:
    Ui::levels *ui;

signals:
    void homeClicked();
};

#endif // LEVELS_H
