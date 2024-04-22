#ifndef IMAGEDIALOG_H
#define IMAGEDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>
#include <QPixmap>

class ImageDialog : public QDialog {
    Q_OBJECT

public:
    explicit ImageDialog(const QString &imagePath, const QString &text, QWidget *parent = nullptr);
};

#endif // IMAGEDIALOG_H
