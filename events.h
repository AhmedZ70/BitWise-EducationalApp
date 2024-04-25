#ifndef EVENTS_H
#define EVENTS_H

#include <QGraphicsView>
#include <QLabel>
#include <QDragEnterEvent>
#include <QDragLeaveEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QPixmap>
#include <QMouseEvent>
#include <QPoint>
#include <QWidget>
#include <QByteArray>
#include <QDrag>
#include <QMimeData>
#include <QBuffer>
#include <QGraphicsPixmapItem>
#include <QStack>

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name Events header file for assignment9
 * This header file includes classes for handling drag-and-drop and other interactive events
 * in a graphical user interface.
 */

/// @brief Base class for handling event generation.
class events
{
public:
    /// @brief Constructor for the events class.
    events();
};

/// @brief Custom label with drag-and-drop functionality.
class Custom_Label : public QLabel{
    Q_OBJECT
public:
    /// @brief Constructor for creating a custom label.
    explicit Custom_Label(QWidget *widget= nullptr);

    /// @brief Sets the name of the gate.
    void setGateName(const QString &name);

    /// @brief Returns the name of the gate.
    QString getGateName() const;
private:
    /// @brief Helper method to start a drag operation.
    void Create_Drag(const QPoint &pos);

    // name of gate
    QString gateName;
protected:
    /// @brief Mouse event that registers mouse pressed to start a drag
    void mousePressEvent(QMouseEvent *event) override;
    using QLabel::QLabel;
};

/// @brief Custom graphics view that supports drag-and-drop operations.
class Custom_GraphicsView : public QGraphicsView{
    Q_OBJECT
private:
    // stack to keep track of gate names
    QStack<QString> gateNames;
public:
    /// @brief Constructor for creating a custom graphics view.
    explicit Custom_GraphicsView(QWidget *widget = nullptr);

    /// @brief Returns the name of the last dropped gate.
    QString lastDroppedGateName() const;

signals:
    /// @brief Signals that a gate is being dragged.
    void gateDragged();
protected:
    /// @brief Handles the event when a drag enters the view.
    void dragEnterEvent(QDragEnterEvent *event) override;

    /// @brief Handles the event when a drag leaves the view.
    void dragLeaveEvent(QDragLeaveEvent *event) override;

    /// @brief Handles the event when a drag moves over the view.
    void dragMoveEvent(QDragMoveEvent *event) override;

    /// @brief Handles drop events.
    void dropEvent(QDropEvent *event) override;

    /// @brief Adds a pixmap to the view.
    void addPixmap(const QPixmap &pixmap);

    /// @brief Handles paint events.
    void paintEvent(QPaintEvent *event) override;
    using QGraphicsView::QGraphicsView;
};

#endif // EVENTS_H
