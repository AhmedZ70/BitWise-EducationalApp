#include "events.h"

events::events() {}

Custom_GraphicsView::Custom_GraphicsView(QWidget *widget) : QGraphicsView(widget){
    setAcceptDrops(true);
    connect(this, &Custom_GraphicsView::itemdrop, this, &Custom_GraphicsView::addPixmap);
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

void Custom_GraphicsView::dropEvent(QDropEvent *event) {
    if (event->mimeData()->hasFormat("image/png")) {
        QByteArray pixmapData = event->mimeData()->data("image/png");
        QPixmap pixmap;
        pixmap.loadFromData(pixmapData, "PNG");

        QGraphicsScene *scene = this->scene();
        if (!scene) {
            scene = new QGraphicsScene(this);
            this->setScene(scene);
        }
        scene->clear(); // Consider if you really want to clear the scene every time
        scene->addPixmap(pixmap);
    }
    event->acceptProposedAction();
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

void Custom_Label::Create_Drag(const QPoint &pos) {
    QDrag *drag = new QDrag(this);
    QMimeData *mimeData = new QMimeData;

    // Here you need to serialize the pixmap data, or store a reference to it
    QByteArray pixmapData;
    QBuffer buffer(&pixmapData);
    buffer.open(QIODevice::WriteOnly);
    this->pixmap().save(&buffer, "PNG"); // PNG format for transparency
    mimeData->setData("image/png", pixmapData);

    drag->setMimeData(mimeData);
    drag->setPixmap(this->pixmap().scaled(100, 100, Qt::KeepAspectRatio, Qt::SmoothTransformation)); // Scale the pixmap for the drag preview
    drag->setHotSpot(pos);
    drag->exec(Qt::CopyAction | Qt::MoveAction);
}

// void Custom_Label::Create_Drag(const QPoint &pos, QWidget *widget){
//     if(widget == nullptr) return;
//     QByteArray byteArray(reinterpret_cast<char*>(&widget),sizeof(widget));
//     QMimeData *mimedata = new QMimeData();
//     mimedata->setData("Label",byteArray);

//     QDrag *drag = new QDrag(this);
//     drag->setMimeData(mimedata);

//     QPoint globalpos = mapToGlobal(pos);
//     QPoint p= widget->mapFromGlobal(globalpos);

//     drag->setHotSpot(p);
//     drag->setPixmap(widget->grab());
//     //drag->exec();
//     drag->exec(Qt::CopyAction | Qt::MoveAction);
// }


void Custom_Label::mousePressEvent(QMouseEvent *event){
    Create_Drag(event->pos());
}
