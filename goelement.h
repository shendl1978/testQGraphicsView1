#ifndef GOELEMENT_H
#define GOELEMENT_H

#include <QGraphicsEllipseItem>
#include <QColor>
#include <QPainter>
#include <QGraphicsSceneHelpEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMoveEvent>
class GoElement : public QGraphicsEllipseItem
{
public:
    GoElement();
    GoElement(qreal posX,qreal posY,qreal x, qreal y, qreal w, qreal h,QColor color=Qt::red);
    virtual ~GoElement();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    QColor color;
};

#endif // GOELEMENT_H
