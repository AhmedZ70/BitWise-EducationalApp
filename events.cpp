#include "events.h"
events::events() {}

Custom_GraphicsView::Custom_GraphicsView(QWidget *widget) : QGraphicsView(widget){
    setAcceptDrops(true);
    connect(this, &Custom_GraphicsView::itemdrop, this, &Custom_GraphicsView::mydebuglines);
}
QString Custom_GraphicsView::lastDroppedGateName() const {
    return gateNames.isEmpty() ? QString() : gateNames.top();
}
void Custom_GraphicsView::dragEnterEvent(QDragEnterEvent *event){
    event->accept();
    event->acceptProposedAction();
}

void Custom_GraphicsView::dragLeaveEvent(QDragLeaveEvent *event){
    event->accept();
}

void Custom_GraphicsView::dragMoveEvent(QDragMoveEvent *event){
    event->accept();
    event->acceptProposedAction();
}
void Custom_GraphicsView::mydebuglines(){
    QString lastGate = lastDroppedGateName();
    if (!lastGate.isEmpty()) {
        qDebug() << "Last dropped gate was:" << lastGate;
    }
}
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
}
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

void Custom_GraphicsView::addPixmap(const QPixmap &pixmap) {
    QGraphicsScene *scene = this->scene();
    if (!scene) {
        scene = new QGraphicsScene(this);
        this->setScene(scene);
    }
    scene->clear();
    scene->addPixmap(pixmap);
}


Custom_Label::Custom_Label(QWidget *widget){

}
void Custom_Label::setGateName(const QString &name) {
    gateName = name;
}

QString Custom_Label::getGateName() const {
    return gateName;
}
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


void Custom_Label::mousePressEvent(QMouseEvent *event){
    Create_Drag(event->pos());
}
