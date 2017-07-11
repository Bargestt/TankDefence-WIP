#include "gamewindow.h"

GameWindow::GameWindow(QWidget *parent) : QWidget(parent)
{

    setMouseTracking(true);

    resize(900,900);
    view = new QGraphicsView(this);
    scene = new QGraphicsScene(this);
    view->setScene(scene);
    view->resize(this->size());

    view->setAttribute(Qt::WA_TransparentForMouseEvents, true);

    X_Line =scene->addLine(-1000,0,1000,0,QPen(Qt::blue));
    Y_Line =scene->addLine(0,-1000,0,1000,QPen(Qt::blue));


    kills=0;
    text = scene->addText("Kills:",QFont("Helvetica [Cronyx]"));
    text->setZValue(100);
    text->setPos(-350,-350);



    t = new GTurret();

    t->addToScene(scene);
    t->load("default_gun_sett.ini");

    t->moveTo(100,100);

    e = new GEnemy();
    e->addToScene(scene);
    e->load("default_gun_sett.ini");
    e->aimPos = t->posBase();
    //e->moveTo(-100,-100);


    connect(e,SIGNAL(died()),this,SLOT(updateKills()));
}

void GameWindow::updateKills()
{
    kills++;
    text->setPlainText(QString("Kills")+QString::number(kills));
}

void GameWindow::mousePressEvent(QMouseEvent *event)
{
    t->shoot();
}

void GameWindow::mouseMoveEvent(QMouseEvent *event)
{
    t->aimTo(view->mapToScene(event->pos()));


}
