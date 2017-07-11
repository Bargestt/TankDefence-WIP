#ifndef GTURRET_H
#define GTURRET_H

#include <gobject.h>
#include <gprojectile.h>
#include <QSettings>

#include <QDebug>
class GTurret
{
public:
    GTurret();
    void addToScene(QGraphicsScene *scene);
    void load(QString pathToINI);

    void aimTo(QPointF target);

    void moveTo(QPoint pos);
    void moveTo(qreal x, qreal y);
    void moveBy(qreal x, qreal y);

    void shoot();

    QPointF posBase();

protected:

    GObject *base;
    GObject *turret;

    QSettings *settings;
};

#endif // GTURRET_H
