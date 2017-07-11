#include "gturret.h"

GTurret::GTurret()
{    
    base = new GObject();
    turret = new GObject();


}

void GTurret::addToScene(QGraphicsScene *scene)
{
    scene->addItem(base);
    scene->addItem(turret);
}

void GTurret::load(QString pathToINI)
{
    settings = new QSettings(pathToINI,QSettings::IniFormat);

    settings->beginGroup("Turret");
    base->loadImgRect(settings->value("TexturePath").toString(),settings->value("GunBaseRect").toRect());
    base->setTransformOriginPoint(settings->value("GunBaseAxis").toPoint());

    turret->loadImgRect(settings->value("TexturePath").toString(),settings->value("GunRect").toRect());
    turret->setTransformOriginPoint(settings->value("GunAxis").toPoint());

    base->setScale(settings->value("Scale").toReal());
    turret->setScale(settings->value("Scale").toReal());
    settings->endGroup();

    turret->moveByOriginTo(0,0);
    base->moveByOriginTo(0,0);
}

void GTurret::aimTo(QPointF target)
{
    turret->rotateTo(target);
}

void GTurret::moveTo(QPoint pos)
{
    base->moveByOriginTo(pos);
    turret->moveByOriginTo(pos);
}

void GTurret::moveTo(qreal x, qreal y)
{
    base->moveByOriginTo(x,y);
    turret->moveByOriginTo(x,y);
}

void GTurret::moveBy(qreal x, qreal y)
{
    base->moveBy(x,y);
    turret->moveBy(x,y);
}

void GTurret::shoot()
{
    GProjectile *p = new GProjectile();
    p->setParams(turret->mapToScene(turret->transformOriginPoint()),5,(int)turret->rotation()-turret->angleOffset,QPen(Qt::red),QBrush(Qt::green));
    p->setZValue(this->turret->zValue()-1);
    p->addToScene(this->base->scene());


}

QPointF GTurret::posBase()
{
    return base->mapToScene(base->transformOriginPoint());

}
