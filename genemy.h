#ifndef GENEMY_H
#define GENEMY_H

#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QSettings>
#include <gturret.h>
#include <QTimer>
#include <QObject>

#include <QDebug>

class GEnemy : public QObject, public GTurret
{
    Q_OBJECT
public:
    GEnemy();
    void load(QString pathToINI);


    void movement();

    qreal desiredAngle;
    QPoint destination;

    qreal movement_speed;
    qreal turning_speed;

    int calcRate;
    bool busy;

    const QGraphicsItem *aim_target;
    QPointF aimPos;

    QTimer *spawnTime;

private:
    qreal speed_dx,speed_dy;
    QGraphicsRectItem *move_target;


public slots:
        void calc();
        void order();
        void spawn();
signals:
        void died();
        void spawned();

};

#endif // GENEMY_H
