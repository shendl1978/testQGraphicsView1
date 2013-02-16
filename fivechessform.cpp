#include "fivechessform.h"
#include "ui_fivechessform.h"
#include <QMessageBox>
FiveChessForm::FiveChessForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FiveChessForm),
    fiveChess(FiveChess::getInstance())
{
    ui->setupUi(this);
    this->fiveChess->addWidget(this);
    this->chessMapItem=new ChessMapItem();
    this->chessMapItem->setFiveChessForm(this);
    this->scene=new QGraphicsScene(this);
    this->scene->addItem(chessMapItem);
    this->ui->graphicsView->setScene(scene);


    this->setLayout(this->ui->verticalLayout);

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
QDialog *FiveChessForm::getStartDialog(void) const{
    return this->startDialog;
}
void FiveChessForm::setStartDialog( QDialog *startDialog){
    this->startDialog=startDialog;
}
void FiveChessForm::paintEvent(QPaintEvent * event){
    //game role label and button enabled
    if(this->fiveChess->getCurrentIndex()%2==0){
        this->ui->blackLable->setEnabled(true);
        this->ui->whiteLabel->setEnabled(false);
        this->ui->blackGiveupButton->setEnabled(true);
        this->ui->whiteGiveupButton->setEnabled(false);
    }else{
        this->ui->blackLable->setEnabled(false);
        this->ui->whiteLabel->setEnabled(true);
        this->ui->blackGiveupButton->setEnabled(false);
        this->ui->whiteGiveupButton->setEnabled(true);
    }
    ////////show game record


   // this->ui->blackRecordLabel->setText(QString::number(this->fiveChess->getBlackWinRecord()));
   // this->ui->blackRecordLoseLabel->setText(QString::number(this->fiveChess->getBlackLoseRecord()));
    //win %1 times,lose %2 times
    this->ui->blackRecordLabel->setText(tr("win %1 times,lose %2 times").arg(QString::number(this->fiveChess->getBlackWinRecord()))
                                    .arg(QString::number(this->fiveChess->getBlackLoseRecord())));

 this->ui->whiteRecordLabel->setText(tr("win %1 times,lose %2 times").arg(QString::number(this->fiveChess->getWhiteWinRecord()))
                                     .arg(QString::number(this->fiveChess->getWhiteLoseRecord())));

    // this->ui->whiteRecordWinLabel->setText(QString::number(this->fiveChess->getWhiteWinRecord()));
    // this->ui->whiteRecordLoseLabel->setText(QString::number(this->fiveChess->getWhiteLoseRecord()));
      //set enable or disable state of restoreBtn
      if(this->fiveChess->getCurrentIndex()==0){
          this->ui->restoreButton->setEnabled(false);
      }else{
          this->ui->restoreButton->setEnabled(true);
      }
      QWidget::paintEvent(event);
}

void FiveChessForm::on_backButton_clicked()
{
    this->hide();
    this->getStartDialog()->show();
}



void FiveChessForm::on_helpButton_clicked()
{

}

void FiveChessForm::on_blackGiveupButton_clicked()
{
    this->chessMapItem->showGameoverDialog(FiveChessType_White);


}

void FiveChessForm::on_whiteGiveupButton_clicked()
{
    this->chessMapItem->showGameoverDialog(FiveChessType_Black);
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
