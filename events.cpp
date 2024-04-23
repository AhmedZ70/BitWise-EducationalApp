#include "events.h"

/**
 * @author Joseph Corbeil, Johnny Song, Ezekiel Jaramillo, Ahmed Zahran, Raj Reddy, Joel Ronca
 * @date April. 22, 2024
 * @name events cpp file for assignment9
 * This cpp file implements all of the events and handlers for our game.
*/

/// @brief Constructor for the events class.
events::events() {}

/// @brief Constructor for Custom_GraphicsView, initializes drag-and-drop and connects signals.
Custom_GraphicsView::Custom_GraphicsView(QWidget *widget) : QGraphicsView(widget) {
    setAcceptDrops(true);
    connect(this, &Custom_GraphicsView::itemdrop, this, &Custom_GraphicsView::mydebuglines);
}

/// @brief Returns the name of the last dropped gate, if available.
QString Custom_GraphicsView::lastDroppedGateName() const {
    return gateNames.isEmpty() ? QString() : gateNames.top();
}

/// @brief Accepts drag enter events to prepare for a potential drop.
void Custom_GraphicsView::dragEnterEvent(QDragEnterEvent *event){
    event->accept();
    event->acceptProposedAction();
}

/// @brief Accepts drag leave events to clean up after a drag operation that doesn't result in a drop.
void Custom_GraphicsView::dragLeaveEvent(QDragLeaveEvent *event){
    event->accept();
}

/// @brief Accepts and processes drag move events, typically used to update the interface or perform visual feedback.
void Custom_GraphicsView::dragMoveEvent(QDragMoveEvent *event){
    event->accept();
    event->acceptProposedAction();
}

/// @brief Debug function that logs the last gate dropped.
void Custom_GraphicsView::mydebuglines(){
    QString lastGate = lastDroppedGateName();
    if (!lastGate.isEmpty()) {
        qDebug() << "Last dropped gate was:" << lastGate;
    }
}

/// @brief Handles drop events to manage dropped items, including images and associated metadata.
void Custom_GraphicsView::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasFormat("image/png")) {
        QByteArray pixmapData = event->mimeData()->data("image/png");
        QPixmap pixmap;
        pixmap.loadFromData(pixmapData, "PNG");

        QGraphicsScene *scene = this->scene();
        if (!scene) {
            scene = new QGraphicsScene(this);
            setScene(scene);
        }
        scene->clear();
        scene->addPixmap(pixmap);

        if (event->mimeData()->hasText()) {
            gateNames.push(event->mimeData()->text());  // Store the gate name
        }
    }
    event->acceptProposedAction();
    emit itemdrop();
    emit gateDragged();
}

/// @brief Custom paint event to display instructions or feedback on the graphics view.
void Custom_GraphicsView::paintEvent(QPaintEvent *event) {
    QGraphicsView::paintEvent(event);

    if (gateNames.isEmpty()) {
        QPainter painter(viewport());
        painter.setPen(Qt::darkGray);
        painter.setFont(QFont("Arial", 14, QFont::DemiBold));

        QStringList lines = {"Drag", "Gate", "Here!"};

        QRect viewportRect = viewport()->rect();
        QPoint center = viewportRect.center();

        QFontMetrics metrics(painter.font());
        int totalHeight = metrics.height() * lines.size();

        int startY = center.y() - totalHeight / 2;

        for (const QString &line : lines) {
            QRect lineRect = metrics.boundingRect(line);
            lineRect.moveCenter(QPoint(center.x(), startY));

            painter.drawText(lineRect, Qt::AlignCenter, line);
            startY += metrics.height();
        }
    }
}

/// @brief Adds a pixmap to the scene, typically after a drop event.
void Custom_GraphicsView::addPixmap(const QPixmap &pixmap) {
    QGraphicsScene *scene = this->scene();
    if (!scene) {
        scene = new QGraphicsScene(this);
        setScene(scene);
    }
    scene->clear();
    scene->addPixmap(pixmap);
}

/// @brief Constructor for Custom_Label.
Custom_Label::Custom_Label(QWidget *widget) : QLabel(widget) {}

/// @brief Sets the name of the gate associated with this label.
void Custom_Label::setGateName(const QString &name) {
    gateName = name;
}

/// @brief Returns the name of the gate associated with this label.
QString Custom_Label::getGateName() const {
    return gateName;
}

/// @brief Initiates a drag operation with the associated gate name and image.
void Custom_Label::Create_Drag(const QPoint &pos) {
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    QByteArray pixmapData;
    QBuffer buffer(&pixmapData);
    buffer.open(QIODevice::WriteOnly);
    this->pixmap().save(&buffer, "PNG");

    mimeData->setText(gateName);  // Use the gate name
    mimeData->setData("image/png", pixmapData);

    drag->setMimeData(mimeData);
    drag->setPixmap(this->pixmap().scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    drag->setHotSpot(pos - this->rect().topLeft());
    drag->exec(Qt::CopyAction | Qt::MoveAction);
}

/// @brief Handles mouse press events to initiate a drag operation from this label.
void Custom_Label::mousePressEvent(QMouseEvent *event) {
    Create_Drag(event->pos());
}
