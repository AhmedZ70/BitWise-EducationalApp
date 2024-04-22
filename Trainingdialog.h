#ifndef TRAININGDIALOG_H
#define TRAININGDIALOG_H

#include <QDialog>
#include <string>

namespace Ui {
class TrainingDialog;
}

class TrainingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TrainingDialog(QWidget *parent = nullptr);
    ~TrainingDialog();

    void setupImageAndText(const QString &imagePath, const QString &text);
    void setTruthTable(std::string gate);

private:
    Ui::TrainingDialog *ui;
};

#endif // TRAININGDIALOG_H
