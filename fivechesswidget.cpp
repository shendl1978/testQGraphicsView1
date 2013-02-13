#include "fivechesswidget.h"
#include <QtGui>
#include <QLabel>
#include <QPushButton>
#include <QGraphicsProxyWidget>s
#include <goelement.h>
#include <chessmapitem.h>
#include <math.h>
FiveChessWidget::FiveChessWidget(QObject *parent) :
    QObject(parent)
{
}

FiveChessWidget::~FiveChessWidget()
{
}
////////////bussiness
void FiveChessWidget::show(void){
    this->scene=new QGraphicsScene();
    scene->setSceneRect(0.0,0.0,800.0,600.0);
      QPushButton *backBtn=new QPushButton("back");
       QObject::connect(backBtn,SIGNAL(clicked()),this,SLOT(back()));
    QGraphicsProxyWidget *backBtnProxy = this->scene->addWidget(backBtn);
     backBtnProxy->setPos(0.0,0.0);

    QLabel *label = new QLabel;
    label->setText("china");


    QGraphicsProxyWidget *proxy = this->scene->addWidget(label);
     proxy->setPos(10.0,0.0);

    QLabel *label2 = new QLabel;
    QString labelRectStr;
    labelRectStr.append("width:");
    labelRectStr.append(QString::number(proxy->rect().width()));
    labelRectStr.append(",height:");
    labelRectStr.append(QString::number(proxy->rect().height()));

    label2->setText(labelRectStr);


    QGraphicsProxyWidget *proxy2 = this->scene->addWidget(label2);
     proxy2->setPos(110.0,0.0);


    this->chessMapItem=new ChessMapItem();
     this->scene->addItem(chessMapItem);

     QPushButton *restoreBtn=new QPushButton("restore");
    QObject::connect(restoreBtn,SIGNAL(clicked()),this,SLOT(restore()));
     QGraphicsProxyWidget *restoreBtnProxy = this->scene->addWidget(restoreBtn);
     restoreBtnProxy->setPos(150.0,0.0);




}
void FiveChessWidget::restore(void){
    FiveChessElement *fiveChessElement= this->chessMapItem->fiveChess->popCmd();
    if(fiveChessElement==NULL){
        return;
    }
    GoElement * chessView=this->chessMapItem->chessViewArray[fiveChessElement->getX()][fiveChessElement->getY()];
    if(chessView==NULL){
        return;
    }
    delete chessView;
    this->chessMapItem->chessViewArray[fiveChessElement->getX()][fiveChessElement->getY()]=NULL;
    delete fiveChessElement;
}

 void FiveChessWidget::back(void){
    this->getView()->hide();
     this->getStartDialog()->show();
 }
ChessMapItem *FiveChessWidget::getChessMapItem(void){
    return this->chessMapItem;
}
void FiveChessWidget::setChessMapItem(ChessMapItem *chessMapItem){
    this->chessMapItem=chessMapItem;
}
QGraphicsScene *FiveChessWidget::getScene(void) const{
    return this->scene;
}
void FiveChessWidget::setScene( QGraphicsScene *scene){
    this->scene=scene;
}
StartDialog *FiveChessWidget::getStartDialog(void) const{
    return this->startDialog;
}
void FiveChessWidget::setStartDialog( StartDialog *startDialog){
    this->startDialog=startDialog;
}
QGraphicsView *FiveChessWidget::getView(void) const{
    return this->view;
}
void FiveChessWidget::setView(  QGraphicsView *view){
    this->view=view;
}
