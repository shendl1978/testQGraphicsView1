#ifndef CHESSMAPITEM_H
#define CHESSMAPITEM_H

#include <QGraphicsEllipseItem>
#include <QColor>
#include <QPainter>
#include <QGraphicsSceneHelpEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneMoveEvent>
#include "fivechess.h"
#include "goelement.h"
class ChessMapItem : public QGraphicsRectItem
{
    // Q_OBJECT
public:
    ChessMapItem();
    ChessMapItem(class FiveChess *fiveChess);
    virtual ~ChessMapItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //reset to init state
    void reset(void);
    int getEnemyType(void);
    void setEnemyType(int enemyType);
    GoElement *chessViewArray[MAX_HORIZONTAL][MAX_VERTICAL];
    class FiveChess *fiveChess;
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    ////////////////
    void init(void);
    bool range(int x,int y,int &xIndex,int &yIndex);

    int step;
    //0  robot. 1  user
    int enemyType;
    /////////////


//signals:

//public slots:]
public:
    void restore(void);
    void redo(void);
};

#endif // CHESSMAPITEM_H
