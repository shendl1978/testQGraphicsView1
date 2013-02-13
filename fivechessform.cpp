#include "fivechessform.h"
#include "ui_fivechessform.h"

FiveChessForm::FiveChessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FiveChessForm)
{
    ui->setupUi(this);
    this->chessMapItem=new ChessMapItem();
    this->scene=new QGraphicsScene(this);
    this->scene->addItem(chessMapItem);
    this->ui->graphicsView->setScene(scene);


    this->setLayout(this->ui->verticalLayout);
    this->setWindowTitle("五子棋");
    QPalette  palette;
    palette.setColor(this->backgroundRole(), QColor(230, 200, 167));
    this->setPalette(palette);
    this->ui->graphicsView->setLineWidth(0);
    this->ui->graphicsView->setBackgroundBrush(QColor(230, 200, 167));
    /*
     this->ui->graphicsView->setRenderHint(QPainter::Antialiasing);
     this->ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     this->ui->graphicsView->setWindowOpacity(0.0);
    this->ui->graphicsView->setWindowFlags(Qt::FramelessWindowHint);
    this->ui->graphicsView->setAttribute(Qt::WA_TranslucentBackground);
    */


}

FiveChessForm::~FiveChessForm()
{
    delete ui;
}
//////////
ChessMapItem *FiveChessForm::getChessMapItem(void){
    return this->chessMapItem;
}
void FiveChessForm::setChessMapItem(ChessMapItem *chessMapItem){
    this->chessMapItem=chessMapItem;
}
QGraphicsScene *FiveChessForm::getScene(void) const{
    return this->scene;
}
void FiveChessForm::setScene( QGraphicsScene *scene){
    this->scene=scene;
}
StartDialog *FiveChessForm::getStartDialog(void) const{
    return this->startDialog;
}
void FiveChessForm::setStartDialog( StartDialog *startDialog){
    this->startDialog=startDialog;
}


void FiveChessForm::on_backButton_clicked()
{
    this->hide();
    this->getStartDialog()->show();
}

void FiveChessForm::on_forwardButton_clicked()
{

}

void FiveChessForm::on_helpButton_clicked()
{

}

void FiveChessForm::on_blackGiveupButton_clicked()
{

}

void FiveChessForm::on_whiteGiveupButton_clicked()
{

}

void FiveChessForm::on_restoreButton_clicked()
{
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
