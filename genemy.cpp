#include "genemy.h"

GEnemy::GEnemy()
{

    movement_speed=0.1;
    turning_speed=30;
    calcRate = 60;
    QTimer *calcTimer= new QTimer(this);
    connect(calcTimer,SIGNAL(timeout()),this,SLOT(calc()));
    QTimer *order= new QTimer(this);
    connect(order,SIGNAL(timeout()),this,SLOT(order()));
    spawnTime = new QTimer(this);
    spawnTime->setSingleShot(true);
    connect(spawnTime,SIGNAL(timeout()),this,SLOT(spawn()));

    calcTimer->start(1000/calcRate);
    order->start(5000);


    speed_dy=0;
    speed_dx=0;
    busy = false;
    move_target = new QGraphicsRectItem();

}
void GEnemy::load(QString pathToINI)
{
    settings = new QSettings(pathToINI,QSettings::IniFormat);

    settings->beginGroup("Enemy");
    base->loadImgRect(settings->value("TexturePath").toString(),settings->value("GunBaseRect").toRect());
    base->setTransformOriginPoint(settings->value("GunBaseAxis").toPoint());

    turret->loadImgRect(settings->value("TexturePath").toString(),settings->value("GunRect").toRect());
    turret->setTransformOriginPoint(settings->value("GunAxis").toPoint());

    base->setScale(settings->value("Scale").toReal());
    turret->setScale(settings->value("Scale").toReal());

    turret->angleOffset = settings->value("GunAngleOffset").toReal();
    base->angleOffset = settings->value("BaseAngleOffset").toReal();

    movement_speed = settings->value("Speed").toReal();
    turning_speed = settings->value("Turning_speed").toReal()/calcRate;
    settings->endGroup();


    base->moveByOriginTo(0,0);
    turret->moveByOriginTo(0,0);
    move_target = base->scene()->addRect(0,0,10,10,QPen(Qt::red),QBrush(Qt::red));
}

void GEnemy::calc()
{
    speed_dx = cos(base->rotation()*3.14/180)*movement_speed;
    speed_dy = sin(base->rotation()*3.14/180)*movement_speed;

    QPointF origin = base->mapToScene(this->base->transformOriginPoint());
    float angle = atan2(-origin.y()+destination.y(),-origin.x()+destination.x())*180/3.14+base->angleOffset;

    if(base->rotation()<angle)
    {
            base->setRotation(base->rotation()+turning_speed);
    }

    if(base->rotation()>angle)
        base->setRotation(base->rotation()-turning_speed);

    moveBy(-speed_dx,-speed_dy);

    int dist = sqrt(pow(base->pos().x()-destination.x(),2)+pow(base->pos().y()-destination.y(),2));
    if(dist<5)
        busy=false;

    turret->rotateTo(aimPos);

    if(base->data(0).toBool())
    {
        base->hide();
        turret->hide();
        spawnTime->start(500);
        emit died();
        base->setData(0,false);
    }
}

void GEnemy::movement()
{

}

void GEnemy::order()
{
    if(!busy)
    {
        destination.setX(rand() %900 - 450);
        destination.setY(rand() %900 - 450);
        move_target->setPos(destination);
    }
}

void GEnemy::spawn()
{
    QPoint newpos(rand() %900 - 450,rand() %900 - 450);
    base->moveByOriginTo(newpos);
    turret->moveByOriginTo(newpos);

    base->show();
    turret->show();
    emit spawned();
}
