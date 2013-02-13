#include "goelement.h"
#include <QDrag>
#include <QApplication>
GoElement::GoElement()
{
}
GoElement::GoElement(qreal posX,qreal posY,qreal x, qreal y, qreal w, qreal h,QColor color)

{
    this->setRect(x,y,w,h);
    this->setPos(posX,posY);

    if(color.isValid()){
        this->color=color;
    }else{
        this->color=Qt::red;
    }

}
GoElement::~GoElement()
{
}
void GoElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);
   // painter->setPen(Qt::NoPen);
   // painter->setBrush(Qt::darkGray);
   // painter->drawEllipse(-12, -12, 30, 30);
   // painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(color));
    painter->drawEllipse(this->rect().x(),this->rect().y(),this->rect().width(),this->rect().height());
}
void GoElement::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(Qt::ClosedHandCursor);
}
//! [3]

//! [5]
void GoElement::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /*
    if (QLineF(event->screenPos(), event->buttonDownScreenPos(Qt::LeftButton))
        .length() < QApplication::startDragDistance()) {
        return;
    }
    */
   // this->setPos( event->screenPos());
   // this->setPos( event->pos());
    //this->setPos(event->scenePos());

     this->setCursor(Qt::OpenHandCursor);
}

void GoElement::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
     this->setCursor(Qt::OpenHandCursor);



}
