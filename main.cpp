#include <stdio.h>
#include <stdlib.h>

#include <QtGui>
#include <QLabel>
#include <QApplication>
#include <goelement.h>
#include <chessmapitem.h>
#include <math.h>

#include "fivechessform.h"
#include "startdialog.h"
int main(int argc, char **argv)
 {
     QApplication app(argc, argv);
 /*
      FiveChessWidget *fiveChessWidget=new FiveChessWidget();


        fiveChessWidget->show();



     QGraphicsView *view=new QGraphicsView(fiveChessWidget->getScene());
     view->setRenderHint(QPainter::Antialiasing);
     view->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
     view->centerOn(0,0);
     //view.resize(200,200);

     view->setBackgroundBrush(QColor(230, 200, 167));
     //view.setWindowTitle("Drag and Drop Robot");
     view->hide();
     */
     StartDialog *startDialog=new StartDialog();
     /*
     startDialog->setFiveChessView(view);
     fiveChessWidget->setStartDialog(startDialog);
     fiveChessWidget->setView(view);
      */

      FiveChessForm *fiveChessForm=new FiveChessForm();
    fiveChessForm->setStartDialog(startDialog);
    fiveChessForm->hide();
    startDialog->setFiveChessForm(fiveChessForm);
     startDialog->show();

     return app.exec();
 }
