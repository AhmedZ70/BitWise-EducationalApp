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

class events
{
public:
    events();
};

class Custom_Label : public QLabel{
    Q_OBJECT
public:
    explicit Custom_Label(QWidget *widget= nullptr);
private:
    void Create_Drag(const QPoint &pos, QWidget *widget);
protected:
    void mousePressEvent(QMouseEvent *event) override;
    using QLabel::QLabel;
};
class Custom_GraphicsView : public QGraphicsView{
    Q_OBJECT
public:
    explicit Custom_GraphicsView(QWidget *widget = nullptr);
signals:
    void itemdrop(QPixmap);
protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
    using QGraphicsView::QGraphicsView;
};

#endif // EVENTS_H
