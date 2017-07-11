#ifndef GOBJECT_H
#define GOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>


#include <math.h>

class GObject :public QGraphicsPixmapItem
{
public:

    GObject(QGraphicsItem *parent = Q_NULLPTR);
    bool debug;

    void addToScene(QGraphicsScene *scene);

    void loadImgRect(QString path, QRect rect);


    void rotateTo(QPointF target);
    int angleOffset;

    void matchOrigins(const QGraphicsItem *target);

    void moveByOriginTo(qreal x,qreal y);
    void moveByOriginTo(QPoint pos);

private:



};

#endif // GOBJECT_H
