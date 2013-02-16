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
     translator.load("fiveChess_"+QLocale::system().name());//,":/testQGraphicsView1");//.qm
          app.installTranslator(&translator);
        //  QTextCodec::setCodecForLocale();
     StartDialog *startDialog=new StartDialog();

      FiveChessForm *fiveChessForm=new FiveChessForm();
    fiveChessForm->setStartDialog(startDialog);
    fiveChessForm->hide();
    startDialog->setFiveChessForm(fiveChessForm);
     startDialog->show();

     return app.exec();
 }
