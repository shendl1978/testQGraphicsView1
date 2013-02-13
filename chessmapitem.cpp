#include "chessmapitem.h"

#include <QDrag>
#include <QApplication>
#include <QMessageBox>
#include "goelement.h"
#include "fivechesselement.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ChessMapItem::init(void){
    /*
    QMessageBox msgBox;
    QString str("MAX_HORIZONTAL:");
    str.append(QString::number(MAX_HORIZONTAL));
    str.append(",MAX_VERTICAL:");
    str.append(QString::number(MAX_VERTICAL));
     msgBox.setText(str);
     msgBox.exec();
    */

    this->setRect(0.0,0.0,(this->fiveChess->getXSize()+3)*this->fiveChess->getElementSize(),(this->fiveChess->getYSize()+3)*this->fiveChess->getElementSize());
    //this->setRect(0.0,0.0,500.0,500.0);

    this->setPos(10.0,50.0);
    for(int i=0;i<MAX_HORIZONTAL;i++){
        for(int j=0;j<MAX_VERTICAL;j++){
            this->chessViewArray[i][j]=NULL;
        }

    }

}

ChessMapItem::ChessMapItem():step(0),enemyType(0)
{
    this->fiveChess=new class FiveChess(19,19,20);
    this->init();
}
ChessMapItem::ChessMapItem(class FiveChess *fiveChess):step(0),enemyType(0){
    this->fiveChess=fiveChess;
    this->init();
}
ChessMapItem::~ChessMapItem()
{
}

bool ChessMapItem::range(int x,int y,int &xIndex,int &yIndex){
    bool ret=true;
    QPoint current(x,y);

    QPoint leftTop(x/this->fiveChess->getElementSize()*this->fiveChess->getElementSize(),y/this->fiveChess->getElementSize()*this->fiveChess->getElementSize());
    QPoint rightTop(x/this->fiveChess->getElementSize()*this->fiveChess->getElementSize()+this->fiveChess->getElementSize(),y/this->fiveChess->getElementSize()*this->fiveChess->getElementSize());
    QPoint leftBottom(x/this->fiveChess->getElementSize()*this->fiveChess->getElementSize(),y/this->fiveChess->getElementSize()*this->fiveChess->getElementSize()+this->fiveChess->getElementSize());
    QPoint rightBottom(x/this->fiveChess->getElementSize()*this->fiveChess->getElementSize()+this->fiveChess->getElementSize(),y/this->fiveChess->getElementSize()*this->fiveChess->getElementSize()+this->fiveChess->getElementSize());

    //////////////////////
    QLineF leftTopLine(current,leftTop);
    QLineF rightTopLine(current,rightTop);
    QLineF leftBottomLine(current,leftBottom);
    QLineF rightBottomLine(current,rightBottom);
    QLineF shortLine=leftTopLine;
    if(shortLine.length()>rightTopLine.length()){

        shortLine=rightTopLine;
    }
    if(shortLine.length()>leftBottomLine.length()){

        shortLine=leftBottomLine;
    }
    if(shortLine.length()>rightBottomLine.length()){

        shortLine=rightBottomLine;
    }
    xIndex=((int)shortLine.p2().x())/this->fiveChess->getElementSize();
    yIndex=((int)shortLine.p2().y())/this->fiveChess->getElementSize();

    return ret;
}

void ChessMapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // painter->setBackgroundMode();
    // painter->setBackground(QBrush(Qt::darkGray));
    // painter->drawEllipse(-12, -12, 30, 30);
    painter->setPen(QPen(Qt::black, 1));
    painter->setBrush(QBrush(Qt::black));


    for(int j=0;j<this->fiveChess->getYSize();j++){
        painter->drawLine(0,j*this->fiveChess->getElementSize(),(this->fiveChess->getXSize()-1)*this->fiveChess->getElementSize(),j*this->fiveChess->getElementSize());


    }
    for(int i=0;i<this->fiveChess->getXSize();i++){
        painter->drawLine(i*this->fiveChess->getElementSize(),0,i*this->fiveChess->getElementSize(),(this->fiveChess->getYSize()-1)*this->fiveChess->getElementSize());
    }



    //painter->drawEllipse(this->rect().x(),this->rect().y(),this->rect().width(),this->rect().height());
}
void ChessMapItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    //this->setCursor(Qt::ClosedHandCursor);
}
//! [3]

//! [5]
void ChessMapItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
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

    //this->setCursor(Qt::OpenHandCursor);
}

void ChessMapItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    int indexX;
    int indexY;
    this->range(event->pos().rx(),event->pos().ry(),indexX,indexY);
    if(indexX<0 || indexX>=this->fiveChess->getXSize()
            || indexY<0 || indexY>=this->fiveChess->getYSize()
            ){
        return;
    }
    if(this->chessViewArray[indexX][indexY]!=NULL){
        return;
    }


    QColor color;
    QColor nextColor;
    FiveChessElement *fiveChessElement=NULL;
    enum FiveChessType fiveChessType=FiveChessTypeNone;
    enum FiveChessType nextFiveChessType=FiveChessTypeNone;
    if(this->step%2==0){
        color=Qt::black;
        nextColor=Qt::white;
        fiveChessType=FiveChessTypeBlack;
        nextFiveChessType=FiveChessTypeWhite;
        fiveChessElement=new FiveChessElement(indexX,indexY,fiveChessType);
    }else{
        color=Qt::white;
        nextColor=Qt::black;
        fiveChessType=FiveChessTypeWhite;
        nextFiveChessType=FiveChessTypeBlack;
        fiveChessElement=new FiveChessElement(indexX,indexY,fiveChessType);
    }
    GoElement *goElement=new GoElement((indexX)*this->fiveChess->getElementSize()-this->fiveChess->getElementSize()/2,
                                       (indexY)*this->fiveChess->getElementSize()-this->fiveChess->getElementSize()/2,
                                       0.0,0.0,this->fiveChess->getElementSize(),this->fiveChess->getElementSize(),color
                                       );
    goElement->setParentItem(this);
    this->chessViewArray[indexX][indexY]=goElement;

    this->fiveChess->pushCmd(fiveChessElement);
    this->step++;
    enum FiveChessType winner=this->fiveChess->winner();
    if(winner!=FiveChessTypeNone){
        QMessageBox msgBox;
        QString str("");
        str.append(g_FiveChessTypeCStr[winner]);
        str.append(" win!");
        msgBox.setText(str);
        msgBox.exec();//block
        //user clicked OK button.
        this->reset();
        return;
    }
    //this->setCursor(Qt::OpenHandCursor);
    ///////////play with robot
    if(this->getEnemyType()==0){
        FiveChessElement *left=NULL;FiveChessElement *right=NULL;int length=0;int  type=0;
        FiveChessElement *nextFiveChessElement=NULL;
        this->fiveChess->recommendSteps(nextFiveChessType,&left,&right,length,type);
        if(left!=NULL){
            nextFiveChessElement=left;
        }else if(right!=NULL){
            nextFiveChessElement=right;
        }

        if(nextFiveChessElement!=NULL){
            if(this->chessViewArray[nextFiveChessElement->getX()][nextFiveChessElement->getY()]!=NULL){
                delete left;
                delete right;
                return;
            }
            GoElement *nextElement=new GoElement((nextFiveChessElement->getX())*this->fiveChess->getElementSize()-this->fiveChess->getElementSize()/2,
                                                 (nextFiveChessElement->getY())*this->fiveChess->getElementSize()-this->fiveChess->getElementSize()/2,
                                                 0.0,0.0,this->fiveChess->getElementSize(),this->fiveChess->getElementSize(),nextColor
                                                 );
            nextElement->setParentItem(this);
            this->chessViewArray[nextFiveChessElement->getX()][nextFiveChessElement->getY()]=nextElement;

            this->fiveChess->pushCmd(nextFiveChessElement);
            this->step++;
            enum FiveChessType winner=this->fiveChess->winner();
            if(winner!=FiveChessTypeNone){
                QMessageBox msgBox;
                QString str("");
                str.append(g_FiveChessTypeCStr[winner]);
                str.append(" win!");
                msgBox.setText(str);
                msgBox.exec();//block
                //user clicked OK button.
                this->reset();
                return;
            }
        }

    }

}
void ChessMapItem::restore(void){
    FiveChessElement *fiveChessElement= this->fiveChess->popCmd();
    if(fiveChessElement==NULL){
        return;
    }
    GoElement * chessView=this->chessViewArray[fiveChessElement->getX()][fiveChessElement->getY()];
    if(chessView==NULL){
        return;
    }
    delete chessView;
    this->chessViewArray[fiveChessElement->getX()][fiveChessElement->getY()]=NULL;
    delete fiveChessElement;

}
void ChessMapItem::redo(void){

}
void ChessMapItem::reset(void){
    this->fiveChess->reset();
    for(int i=0;i<MAX_HORIZONTAL;i++){
        for(int j=0;j<MAX_VERTICAL;j++){
            if(this->chessViewArray[i][j]!=NULL){
                delete this->chessViewArray[i][j];
                this->chessViewArray[i][j]=NULL;
            }
        }

    }
    this->step=0;

}
int ChessMapItem::getEnemyType(void){
    return this->enemyType;
}
void ChessMapItem::setEnemyType(int enemyType){
    this->enemyType=enemyType;
}
