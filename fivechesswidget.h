#ifndef FIVECHESSWIDGET_H
#define FIVECHESSWIDGET_H

#include <QObject>
#include <chessmapitem.h>
#include "startdialog.h"
class FiveChessWidget : public QObject
{
    Q_OBJECT
public:
    explicit FiveChessWidget(QObject *parent = 0);
    virtual ~FiveChessWidget();
    //
    void show(void);
    ChessMapItem *getChessMapItem(void);
    void setChessMapItem(ChessMapItem *chessMapItem);
    QGraphicsScene *getScene(void) const;
    void setScene( QGraphicsScene *scene) ;
    StartDialog *getStartDialog(void) const;
    void setStartDialog( StartDialog *startDialog) ;
    QGraphicsView *getView(void) const;
    void setView(QGraphicsView *view) ;

signals:
    
public slots:
    void restore(void);
    void back(void);
private:
    ChessMapItem *chessMapItem;
    QGraphicsScene *scene;
     StartDialog *startDialog;
     QGraphicsView *view;
};

#endif // FIVECHESSWIDGET_H
