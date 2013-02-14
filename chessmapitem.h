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
#include <QWidget>
class ChessMapItem : public QGraphicsRectItem
{
    // Q_OBJECT
public:
    ChessMapItem();
    ChessMapItem( FiveChess *fiveChess);
    virtual ~ChessMapItem();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    //reset to init state
    virtual void reset(void);
    virtual QWidget *getFiveChessForm(void) const;
     virtual void setFiveChessForm(QWidget *fiveChessForm) ;
    virtual void showGameoverDialog(enum FiveChessType winType);
    GoElement *chessViewArray[MAX_HORIZONTAL][MAX_VERTICAL];
    FiveChess *fiveChess;
protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
private:
    ////////////////
      void init(void);
      bool range(int x,int y,int &xIndex,int &yIndex);

   \
    /////////////
    QWidget *fiveChessForm;

//signals:

//public slots:]
public:
    void restore(void);
    void redo(void);
};

#endif // CHESSMAPITEM_H
