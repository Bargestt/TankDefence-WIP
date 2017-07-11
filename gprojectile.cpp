#include "gprojectile.h"

GProjectile::GProjectile(QGraphicsItem *parent) :QGraphicsEllipseItem(parent)
{
    countdown=new QTimer(this);
    lifetime = 2500;

    setRect(0,0,15,15);
    countdown->start(lifetime);
    connect(countdown,SIGNAL(timeout()),this,SLOT(deleteLater()));

    startTimer(10);
}

void GProjectile::addToScene(QGraphicsScene *scene)
{
    scene->addItem(this);
}

void GProjectile::setParams(QPointF pos, float spd, int direction, QPen pen, QBrush brush)
{
    setPos(pos.x()-this->rect().center().x(),pos.y()-this->rect().center().y());
    speed = spd;
    angle = direction;
    setPen(pen);
    setBrush(brush);

    speed_dx = cos(angle*3.14/180)*speed;
    speed_dy = sin(angle*3.14/180)*speed;
}
void GProjectile::setSpeed(int spd)
{
    speed = spd;
    speed_dx = cos(angle)*speed;
    speed_dy = sin(angle)*speed;
}

void GProjectile::setDirection(int direction)
{
    angle = direction;
    speed_dx = cos(angle)*speed;
    speed_dy = sin(angle)*speed;
}

void GProjectile::calc()
{
    moveBy(speed_dx,speed_dy);
    //check collision
    if(collidingItems().length()>1)
    {
        QList<QGraphicsItem*> coll = collidingItems(); //
        foreach(QGraphicsItem* itm,coll)
            itm->setData(0,true);
    }
    else
        this->setBrush(Qt::green);

}

void GProjectile::timerEvent(QTimerEvent *event)
{
    calc();
}
