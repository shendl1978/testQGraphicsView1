#include "startdialog.h"
#include "ui_startdialog.h"
#include <QtGui>
#include <QLabel>
#include <goelement.h>
#include <chessmapitem.h>
#include <QPalette>
#include <math.h>

#include "fivechess.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),fiveChess(FiveChess::getInstance()),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    this->setLayout(this->ui->verticalLayout);

    this->setWindowTitle("五子棋");
    QPalette  palette;
    palette.setColor(this->backgroundRole(), QColor(230, 200, 167));
    this->setPalette(palette);
    this->ui->returnBtn->setEnabled(this->fiveChess->isGameRunning());

}

StartDialog::~StartDialog()
{
    delete ui;
    delete this->fiveChess;
}

 QWidget *StartDialog::getFiveChessForm(void) const{
     return this->fiveChessForm;

 }
 void StartDialog::setFiveChessForm(QWidget *fiveChessForm) {

     this->fiveChessForm=fiveChessForm;
 }
void StartDialog::paintEvent(QPaintEvent * event){
    this->ui->returnBtn->setEnabled(this->fiveChess->isGameRunning());
    QWidget::paintEvent(event);

}
//play with robot
void StartDialog::on_singleGame_clicked()
{
    this->hide();
    this->getFiveChessForm()->show();

    this->fiveChess->setGameRunning(true);
    this->fiveChess->setEnemyType(FiveChessEnemyType_Robot);
}

void StartDialog::on_twoBtn_clicked()
{
    this->hide();
    this->getFiveChessForm()->show();
    this->fiveChess->setGameRunning(true);
    this->fiveChess->setEnemyType(FiveChessEnemyType_LocalUser);


}

void StartDialog::on_returnBtn_clicked()
{

        this->hide();
        this->getFiveChessForm()->show();


}


void StartDialog::on_onlineButton_clicked()
{
    this->fiveChess->setEnemyType(FiveChessEnemyType_RemoteUser);
}

void StartDialog::on_helpButton_clicked()
{

}
