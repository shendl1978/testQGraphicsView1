#ifndef STARTDIALOG_H
#define STARTDIALOG_H

#include <QDialog>
#include <QGraphicsView>
namespace Ui {
class StartDialog;
}

class StartDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit StartDialog(QWidget *parent = 0);
    ~StartDialog();
   QGraphicsView * getFiveChessView(void) const;
   void setFiveChessView(QGraphicsView *fiveChessView);
   bool isGameRunning(void) const;
   void setGameRunning(bool gameRunning) ;
private:
    Ui::StartDialog *ui;
      QGraphicsView *fiveChessView;
signals:

public    slots:



private slots:
    void on_singleGame_clicked();
    void on_twoBtn_clicked();
    void on_returnBtn_clicked();
private:
    bool gameRunning;
};

#endif // STARTDIALOG_H
