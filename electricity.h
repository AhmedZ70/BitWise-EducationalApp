#ifndef ELECTRICITYEFFECT_H
#define ELECTRICITYEFFECT_H

#include <QWidget>
#include <QPainter>
#include <QTimer>
#include <QRandomGenerator>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name electricty h file for assignment9
 * @brief This class inherits from QWidget and will display a small line of electricity across
 * the main menu of the game utilizing the paint method in Qt.
 */

class Electricity : public QWidget {
    Q_OBJECT

public:

    //Constructor
    explicit Electricity(QWidget* parent = nullptr);

protected:

    /** @brief paint event handler
     */
    void paintEvent(QPaintEvent* event) override;

private:

    /**
     * @brief This method will recursively draw random lines along
     * the line to give the appearance of electricity.
     * @param painter paint object
     * @param start starting point to draw
     * @param end ending point to draw
     * @param depth variable used to control recurion
     */
    void drawElectricity(QPainter& painter, QPoint startingPoint, QPoint endingPoint, int depth);

    /**
     * @brief Connected to a Timer that will update the line every time it goes off. This will
     * update the electricity line to give a movement affect.
     */
    void updateElectricity();
};

#endif // ELECTRICITYEFFECT_H
