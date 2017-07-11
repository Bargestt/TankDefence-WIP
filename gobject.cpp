#include "gobject.h"

GObject::GObject(QGraphicsItem *parent) : QGraphicsPixmapItem(parent)
{
    angleOffset =90;
    debug =true;

}

void GObject::addToScene(QGraphicsScene *scene)
{
    scene->addItem(this);

}
void GObject::loadImgRect(QString path, QRect rect)
{
    setPixmap(QPixmap(path).copy(rect));
}



void GObject::rotateTo(QPointF target)
{
    QPointF origin = mapToScene(this->transformOriginPoint());

    float angle = atan2(-origin.y()+target.y(),-origin.x()+target.x());

    this->setRotation(angle*180/3.14+angleOffset);
}

void GObject::matchOrigins(const QGraphicsItem *target)
{
    QPointF torigin = target->mapToScene(target->transformOriginPoint());

    this->moveByOriginTo(torigin.x(),torigin.y());
}

void GObject::moveByOriginTo(qreal x,qreal y)
{
    this->setPos(x-transformOriginPoint().x(),y-transformOriginPoint().y());
}

void GObject::moveByOriginTo(QPoint pos)
{
    this->setPos(pos-transformOriginPoint());
}


