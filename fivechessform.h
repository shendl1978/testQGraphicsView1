#ifndef FIVECHESSFORM_H
#define FIVECHESSFORM_H

#include <QWidget>
#include <QDialog>
#include <QGraphicsScene>
///////
#include "chessmapitem.h"
//#include "startdialog.h"
#include "fivechess.h"
namespace Ui {
class FiveChessForm;
}

class FiveChessForm : public QWidget
{
    Q_OBJECT
    
public:
    explicit FiveChessForm(QWidget *parent = 0);
    virtual ~FiveChessForm();
    /////////
    virtual ChessMapItem *getChessMapItem(void);
    virtual void setChessMapItem(ChessMapItem *chessMapItem);
    virtual QGraphicsScene *getScene(void) const;
    virtual void setScene( QGraphicsScene *scene) ;
    virtual QDialog *getStartDialog(void) const;
    virtual void setStartDialog( QDialog *startDialog) ;

protected:
     virtual void paintEvent(QPaintEvent * event);
private slots:
    void on_backButton_clicked();


    void on_helpButton_clicked();

    void on_blackGiveupButton_clicked();

    void on_whiteGiveupButton_clicked();

    void on_restoreButton_clicked();

private:
    Ui::FiveChessForm *ui;
    QGraphicsScene *scene;
    ChessMapItem *chessMapItem;

     QDialog *startDialog;
     FiveChess *fiveChess;
};

#endif // FIVECHESSFORM_H
