#include "startdialog.h"
#include "ui_startdialog.h"
#include <QtGui>
#include <QLabel>
#include <goelement.h>
#include <chessmapitem.h>
#include <math.h>
#include "fivechesswidget.h"
#include "startdialog.h"
StartDialog::StartDialog(QWidget *parent) :
    QDialog(parent),gameRunning(false),
    ui(new Ui::StartDialog)
{
    ui->setupUi(this);
    this->setLayout(this->ui->verticalLayout);

}

StartDialog::~StartDialog()
{
    delete ui;
}
QGraphicsView * StartDialog::getFiveChessView(void) const{
    return this->fiveChessView;
}
void StartDialog::setFiveChessView(QGraphicsView *fiveChessView){
    this->fiveChessView=fiveChessView;
}
//play with robot
void StartDialog::on_singleGame_clicked()
{
    this->hide();
    this->getFiveChessView()->show();
    this->setGameRunning(true);
    this->ui->returnBtn->setEnabled(true);
}

void StartDialog::on_twoBtn_clicked()
{
    this->hide();
    this->getFiveChessView()->show();
    this->setGameRunning(true);
    this->ui->returnBtn->setEnabled(true);
}

void StartDialog::on_returnBtn_clicked()
{
    if(this->isGameRunning()){
        this->hide();
        this->getFiveChessView()->show();
    }

}
bool StartDialog::isGameRunning(void) const{
    return this->gameRunning;
}
void StartDialog::setGameRunning(bool gameRunning){
    this->gameRunning=gameRunning;
}
