#ifndef CUSTOMLINEEDIT_H
#define CUSTOMLINEEDIT_H


#include <QLineEdit>
#include <QMouseEvent>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name customLineEdit h file for assignment9
 * This h file inherits from QLineEdit that lets the user toggle the input bit boxes between two
 * and one respectively.
*/
class CustomLineEdit : public QLineEdit {
    Q_OBJECT

public:
    /// @brief custom line edit object
    explicit CustomLineEdit(QWidget *parent = nullptr);

protected:
    /// @brief mouse event that registers mouse clicked on the input bit box
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // CUSTOMLINEEDIT_H

