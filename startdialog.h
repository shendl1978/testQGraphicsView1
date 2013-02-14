#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include <QGraphicsView>
#include "fivechess.h"
namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();
   //QGraphicsView * getFiveChessView(void) const;
  // void setFiveChessView(QGraphicsView *fiveChessView);
    QWidget *getFiveChessForm(void) const;
     void setFiveChessForm(QWidget *fiveChessForm) ;
protected:
     virtual void paintEvent(QPaintEvent * event);
private:
    Ui::StartDialog *ui;
    QWidget *fiveChessForm;
     // QGraphicsView *fiveChessView;
signals:

public    slots:



private slots:
    void on_singleGame_clicked();
    void on_twoBtn_clicked();
    void on_returnBtn_clicked();
    void on_onlineButton_clicked();

    void on_helpButton_clicked();

private:

    FiveChess *fiveChess;
};

#endif // STARTDIALOG_H
