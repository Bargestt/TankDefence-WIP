#ifndef GPROJECTILE_H
#define GPROJECTILE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QObject>
#include <QTimer>


class GProjectile : public QObject,public QGraphicsEllipseItem
{
    Q_OBJECT
public:
    GProjectile(QGraphicsItem *parent = Q_NULLPTR);

    void addToScene(QGraphicsScene *scene);
    void setParams(QPointF pos, float spd, int direction, QPen pen, QBrush brush);
    void setSpeed(int spd);
    void setDirection(int direction);
    void calc();




private:
    float speed;
    float speed_dx;
    float speed_dy;
    int angle;

    int lifetime;
    QTimer *countdown;




    // QObject interface
protected:
    void timerEvent(QTimerEvent *event);
};

#endif // GPROJECTILE_H
