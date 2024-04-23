#include "customlineedit.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name customLineEdit cpp file for assignment9
 * This cpp file inherits from QLineEdit that lets the user toggle the input bit boxes between two
 * and one respectively.
*/
CustomLineEdit::CustomLineEdit(QWidget *parent) : QLineEdit(parent) {
    // Sets to 0 initially
    setText("0");

    setReadOnly(true);

    setCursor(Qt::PointingHandCursor);
}

void CustomLineEdit::mousePressEvent(QMouseEvent *event) {
    setText(text() == "0" ? "1" : "0");

    QLineEdit::mousePressEvent(event);
}
