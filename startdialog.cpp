#include "startdialog.h"
#include "ui_startdialog.h"
#include <QtGui>
#include <QLabel>
#include <goelement.h>
#include <chessmapitem.h>
#include <QPalette>
#include <math.h>
#include "fivechesswidget.h"
#include "startdialog.h"

StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),gameRunning(false),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    this->setLayout(this->ui->verticalLayout);

    this->setWindowTitle("五子棋");
    QPalette  palette;
    palette.setColor(this->backgroundRole(), QColor(230, 200, 167));
    this->setPalette(palette);

}

StartDialog::~StartDialog()
{
    delete ui;
}
/*
QGraphicsView * StartDialog::getFiveChessView(void) const{
    return this->fiveChessView;
}
void StartDialog::setFiveChessView(QGraphicsView *fiveChessView){
    this->fiveChessView=fiveChessView;
}
*/
 QWidget *StartDialog::getFiveChessForm(void) const{
     return this->fiveChessForm;

 }
 void StartDialog::setFiveChessForm(QWidget *fiveChessForm) {

     this->fiveChessForm=fiveChessForm;
 }

//play with robot
void StartDialog::on_singleGame_clicked()
{
    this->hide();
    this->getFiveChessForm()->show();
    this->setGameRunning(true);
    this->ui->returnBtn->setEnabled(true);
}

void StartDialog::on_twoBtn_clicked()
{
    this->hide();
    this->getFiveChessForm()->show();
    this->setGameRunning(true);
    this->ui->returnBtn->setEnabled(true);
}

void StartDialog::on_returnBtn_clicked()
{
    if(this->isGameRunning()){
        this->hide();
        this->getFiveChessForm()->show();
    }

}
bool StartDialog::isGameRunning(void) const{
    return this->gameRunning;
}
void StartDialog::setGameRunning(bool gameRunning){
    this->gameRunning=gameRunning;
}
