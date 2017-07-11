#ifndef GAMEWINDOW_H
#define GAMEWINDOW_H

#include <QWidget>

#include <QGraphicsView>
#include <QGraphicsScene>

#include <QGraphicsEllipseItem>
#include <QMouseEvent>



#include <qmath.h>

#include <gturret.h>
#include <gprojectile.h>
#include <genemy.h>

#include <QSettings>


class GameWindow : public QWidget
{
    Q_OBJECT
public:
    explicit GameWindow(QWidget *parent = 0);


private:
    std::vector<GProjectile*> projectiles;

    QGraphicsView *view;
    QGraphicsScene *scene;

    QGraphicsLineItem *X_Line;
    QGraphicsLineItem *Y_Line;

    QGraphicsTextItem *text;

    GTurret *t;
    GEnemy *e;
    int kills;

signals:

public slots:
    void updateKills();

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
};

#endif // GAMEWINDOW_H
