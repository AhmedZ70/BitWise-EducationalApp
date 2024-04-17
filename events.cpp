#include "events.h"

events::events() {}

Custom_GraphicsView::Custom_GraphicsView(QWidget *widget) : QGraphicsView(widget){
    setAcceptDrops(true);
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

void Custom_GraphicsView::dropEvent(QDropEvent *event){
    if(event->source() == this) return;
    QLabel *label = qobject_cast<QLabel*>(event->source());
    QPixmap label_Image = label->pixmap();
    emit itemdrop(label_Image);

}

Custom_Label::Custom_Label(QWidget *widget){

}

void Custom_Label::Create_Drag(const QPoint &pos, QWidget *widget){
    if(widget == nullptr) return;
    QByteArray byteArray(reinterpret_cast<char*>(&widget),sizeof(widget));
    QMimeData *mimedata = new QMimeData();
    mimedata->setData("Label",byteArray);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimedata);

    QPoint globalpos = mapToGlobal(pos);
    QPoint p= widget->mapFromGlobal(globalpos);

    drag->setHotSpot(p);
    drag->setPixmap(widget->grab());
    drag->exec();
}
void Custom_Label::mousePressEvent(QMouseEvent *event){
    Create_Drag(event->pos(), this );
}
