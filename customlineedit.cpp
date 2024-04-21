#include "customlineedit.h"

CustomLineEdit::CustomLineEdit(QWidget *parent) : QLineEdit(parent) {
    setText("0");

    setReadOnly(true);

    setCursor(Qt::PointingHandCursor);
}

void CustomLineEdit::mousePressEvent(QMouseEvent *event) {
    setText(text() == "0" ? "1" : "0");

    // emit editingFinished();

    QLineEdit::mousePressEvent(event);
}
