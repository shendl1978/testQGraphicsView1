#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//////////
#include <QtGui>
#include <QLabel>
#include <QApplication>
#include <goelement.h>
#include <chessmapitem.h>
#include <QTranslator>
/////////
#include "fivechessform.h"
#include "startdialog.h"
int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
     QTranslator translator;
          translator.load(":/testQGraphicsView1/fiveChess_zh_CN");//.qm
          app.installTranslator(&translator);

     StartDialog *startDialog=new StartDialog();

      FiveChessForm *fiveChessForm=new FiveChessForm();
    fiveChessForm->setStartDialog(startDialog);
    fiveChessForm->hide();
    startDialog->setFiveChessForm(fiveChessForm);
     startDialog->show();

     return app.exec();
 }
