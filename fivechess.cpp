#include "fivechess.h"
#include <stdio.h>
#include <stdlib.h>
#include "fiveChessType.h"
FiveChess *FiveChess::instance=NULL;
FiveChess *FiveChess::getInstance(void){
    if(FiveChess::instance==NULL){
        FiveChess::instance=new FiveChess();

    }
    return FiveChess::instance;
}
FiveChess::FiveChess(void):
    xSize(FiveChess_XSize),
    ySize(FiveChess_YSize),
    elementSize(FiveChess_ElementSize),
    currentIndex(0),
     gameRunning(false),

     enemyType(FiveChessEnemyType_Robot)
   ,blackWinRecord(0)
   ,blackLoseRecord(0)
   ,whiteWinRecord(0)
   ,whiteLoseRecord(0)
   ,widgets(new QList<QWidget *>())
{
    for(int i=0;i<CMDS_LENGTH;i++){

        this->cmds[i]=NULL;

    }
}
FiveChess::FiveChess( int xSize,int ySize,int elementSize):
    xSize(xSize),
    ySize(ySize),
    elementSize(elementSize),
    currentIndex(0),
    gameRunning(false),

    enemyType(FiveChessEnemyType_Robot)
  ,blackWinRecord(0)
  ,blackLoseRecord(0)
  ,whiteWinRecord(0)
  ,whiteLoseRecord(0)
{
    //this->grid=(enum FiveChessType **)malloc(sizeof(enum FiveChessType)*xSize*ySize);
    for(int i=0;i<xSize;i++){
        for(int j=0;j<ySize;j++){
            this->grid[i][j]=FiveChessType_None;
        }
    }
    for(int i=0;i<CMDS_LENGTH;i++){

        this->cmds[i]=NULL;

    }
}
FiveChess::~FiveChess()
{
}
int FiveChess::getXSize() const{
    return this->xSize;
}
void FiveChess::setXSize(int xSize){
    this->xSize=xSize;
}
int FiveChess::getYSize() const{
    return this->ySize;
}
void FiveChess::setYSize(int ySize){
    this->ySize=ySize;
}
int FiveChess::getElementSize(void) const{
    return this->elementSize;
}
void FiveChess::setElementSize(int elementSize){
    this->elementSize=elementSize;
}
int FiveChess::getCurrentIndex() const{
    return this->currentIndex;
}
bool FiveChess::pushCmd(  FiveChessElement *cmd){
    if(cmd==NULL){
        return false;
    }
    if(this->currentIndex>=CMDS_LENGTH-1){
        return false;
    }else{
        this->cmds[this->currentIndex++]=cmd;
        this->grid[cmd->getX()][cmd->getY()]=cmd->getType();
       this->updateWidgets();
        return true;
    }
}
FiveChessElement * FiveChess::popCmd(void){
    if(this->currentIndex>0){

        FiveChessElement * cmd= this->cmds[--this->currentIndex];
        this->grid[cmd->getX()][cmd->getY()]=FiveChessType_None;
        this->updateWidgets();
        return cmd;
    }else{
        return NULL;
    }
}
void FiveChess::reset(void){
    FiveChessElement * cmd=NULL;
    while((cmd=this->popCmd())!=NULL){
        delete cmd;
        cmd=NULL;
    }
    this->currentIndex=0;
}
bool FiveChess::isGameRunning(void) const{

    return this->gameRunning;
}
void FiveChess::setGameRunning(bool gameRunning){

    this->gameRunning=gameRunning;
}
/*
int FiveChess::getStep(void) const{
    return this->step;
}
int FiveChess::incrementStep(void){
    return ++(this->step);
}
void FiveChess::setStep(int step){
    this->step=step;
}
*/
  int FiveChess::getBlackWinRecord(void) const{
    return this->blackWinRecord;
}
  void  FiveChess::setBlackWinRecord(int blackWinRecord){
    this->blackWinRecord=blackWinRecord;
}

  int FiveChess::getBlackLoseRecord(void) const{
    return this->blackLoseRecord;
}
  void  FiveChess::setBlackLoseRecord(int blackLoseRecord){
      this->blackLoseRecord=blackLoseRecord;
  }

  int FiveChess::getWhiteWinRecord(void) const{
    return this->whiteWinRecord;
  }
   void FiveChess::setWhiteWinRecord(int whiteWinRecord){
       this->whiteWinRecord=whiteWinRecord;
   }

  int FiveChess::getWhiteLoseRecord(void) const{
      return this->whiteLoseRecord;
  }
  void FiveChess::setWhiteLoseRecord(int whiteLoseRecord){
      this->whiteLoseRecord=whiteLoseRecord;
  }

   bool FiveChess::recordWin(enum FiveChessType winType,int &blackWinRecord,int &blackLoseRecord,int &whiteWinRecord,int &whiteLoseRecord){
       switch(winType){
       case FiveChessType_Black:
           this->blackWinRecord++;
           this->whiteLoseRecord++;
           break;
       case FiveChessType_White:
           this->whiteWinRecord++;
           this->blackLoseRecord++;
           break;
        case FiveChessType_None:
           //break;

       default:
           return false;
           break;

       }

       blackWinRecord=this->blackWinRecord;
       blackLoseRecord=this->blackLoseRecord;
       whiteWinRecord=this->whiteWinRecord;
       whiteLoseRecord=this->whiteLoseRecord;
       return true;
   }

enum FiveChessEnemyType FiveChess::getEnemyType(void) const{
    return this->enemyType;
}
void FiveChess::setEnemyType(enum FiveChessEnemyType enemyType){
    this->enemyType=enemyType;
}

  void FiveChess::updateWidgets(void){
      for(int i=0;i<this->widgets->size();i++){
          this->widgets->at(i)->update();

      }
  }
  bool FiveChess::addWidget(QWidget *widget){

    this->widgets->append(widget);
      return true;
  }
//TODO：
enum FiveChessType FiveChess::winner(void){
    enum FiveChessType returnType=FiveChessType_None;
    //垂直
    for(int i=0;i<xSize;i++){
        for(int j=0;j<ySize-4;j++){
            enum FiveChessType entry0=this->grid[i][j];

            if(entry0!=FiveChessType_None){
                if(entry0==this->grid[i][j+1] && entry0==this->grid[i][j+2] && entry0==this->grid[i][j+3] && entry0==this->grid[i][j+4]){
                    return entry0;
                }
            }
        }
    }
    //水平
    for(int j=0;j<ySize;j++){
        for(int i=0;i<xSize-4;i++){
            enum FiveChessType entry0=this->grid[i][j];

            if(entry0!=FiveChessType_None){
                if(entry0==this->grid[i+1][j] && entry0==this->grid[i+2][j] && entry0==this->grid[i+3][j] && entry0==this->grid[i+4][j]){
                    return entry0;
                }
            }
        }
    }

    //上斜线  x+1,y-1   水平优先

    for(int j=4;j<ySize;j++){
        for(int i=0;i<xSize-4;i++){
            enum FiveChessType entry0=this->grid[i][j];
            if(entry0!=FiveChessType_None){
                if(entry0==this->grid[i+1][j-1] && entry0==this->grid[i+2][j-2] && entry0==this->grid[i+3][j-3] && entry0==this->grid[i+4][j-4]){
                    return entry0;
                }
            }
        }
    }





    //下斜线  x+1,y+1 水平优先
    for(int j=0;j<ySize-4;j++){
        for(int i=0;i<xSize-4;i++){
            enum FiveChessType entry0=this->grid[i][j];
            if(entry0!=FiveChessType_None){
                if(entry0==this->grid[i+1][j+1] && entry0==this->grid[i+2][j+2] && entry0==this->grid[i+3][j+3] && entry0==this->grid[i+4][j+4]){
                    return entry0;
                }
            }
        }
    }

    return returnType;
}
//type=0  attack
//type=1  defend
void FiveChess::recommendSteps(enum FiveChessType selfType,FiveChessElement **left,FiveChessElement **right,int &length,int &type){
    /*
    if(this->currentIndex==0){
        *left=new FiveChessElement(this->getXSize()/2,this->getYSize()/2,selfType);
        length=0;
        type=0;
        return ;
    }
    */

    /////////////////////////
    enum FiveChessType enemyType=FiveChessType_None;
    if(selfType==FiveChessType_Black){
        enemyType=FiveChessType_White;
    }else{
        enemyType=FiveChessType_Black;
    }



    //defend 4
    //垂直
    for(int i=0;i<xSize;i++){
        for(int j=0;j<ySize-4;j++){
                if(enemyType==this->grid[i][j] &&enemyType==this->grid[i][j+1] && enemyType==this->grid[i][j+2] && enemyType==this->grid[i][j+3]
                       ){
                    bool testFlag=false;
                    if(j+4<ySize &&this->grid[i][j+4]==FiveChessType_None){
                        *right=new FiveChessElement(i,j+4,this->grid[i][j+4]);
                       testFlag=true;
                    }
                    if(j-1>=0 &&this->grid[i][j-1]==FiveChessType_None){
                        *left=new FiveChessElement(i,j-1,this->grid[i][j-1]);
                        testFlag=true;
                    }
                    if(testFlag){
                        type=1;
                        length=4;
                        return;
                    }
                }

        }
    }
    //水平
    for(int j=0;j<ySize;j++){
        for(int i=0;i<xSize-4;i++){


            if(enemyType==this->grid[i][j] &&enemyType==this->grid[i+1][j] && enemyType==this->grid[i+2][j] && enemyType==this->grid[i+3][j]
                   ){
                bool testFlag=false;
                if(i+4<xSize &&this->grid[i+4][j]==FiveChessType_None){
                    *right=new FiveChessElement(i+4,j,this->grid[i+4][j]);
                   testFlag=true;
                }
                if(i-1>=0 &&this->grid[i-1][j]==FiveChessType_None){
                    *left=new FiveChessElement(i-1,j,this->grid[i-1][j]);
                    testFlag=true;
                }
                if(testFlag){
                    type=1;
                    length=4;
                    return;
                }
            }

        }
    }

    //上斜线  x+1,y-1   水平优先

    for(int j=4;j<ySize;j++){
        for(int i=0;i<xSize-4;i++){
            if(enemyType==this->grid[i][j] &&enemyType==this->grid[i+1][j-1] && enemyType==this->grid[i+2][j-2] && enemyType==this->grid[i+3][j-3]
                   ){
                bool testFlag=false;
                if(i+4<xSize && j-4>=0 &&this->grid[i+4][j-4]==FiveChessType_None){
                    *right=new FiveChessElement(i+4,j-4,this->grid[i+4][j-4]);
                   testFlag=true;
                }
                if(i-1>=0 && j+1<ySize &&this->grid[i-1][j+1]==FiveChessType_None){
                    *left=new FiveChessElement(i-1,j+1,this->grid[i-1][j+1]);
                    testFlag=true;
                }
                if(testFlag){
                    type=1;
                    length=4;
                    return;
                }
            }


        }
    }





    //下斜线  x+1,y+1 水平优先
    for(int j=0;j<ySize-4;j++){
        for(int i=0;i<xSize-4;i++){


            if(enemyType==this->grid[i][j] &&enemyType==this->grid[i+1][j+1] && enemyType==this->grid[i+2][j+2] && enemyType==this->grid[i+3][j+3]
                   ){
                bool testFlag=false;
                if(i+4<xSize && j+4<ySize &&this->grid[i+4][j+4]==FiveChessType_None){
                    *right=new FiveChessElement(i+4,j+4,this->grid[i+4][j+4]);
                   testFlag=true;
                }
                if(i-1>=0 && j-1>=0 &&this->grid[i-1][j-1]==FiveChessType_None){
                    *left=new FiveChessElement(i-1,j-1,this->grid[i-1][j-1]);
                    testFlag=true;
                }
                if(testFlag){
                    type=1;
                    length=4;
                    return;
                }
            }



        }
    }
    //atack 4
    //垂直
    for(int i=0;i<xSize;i++){
        for(int j=0;j<ySize-4;j++){
                if(selfType==this->grid[i][j] &&selfType==this->grid[i][j+1] && selfType==this->grid[i][j+2] && selfType==this->grid[i][j+3]
                       ){
                    bool testFlag=false;
                    if(j+4<ySize &&this->grid[i][j+4]==FiveChessType_None){
                        *right=new FiveChessElement(i,j+4,this->grid[i][j+4]);
                       testFlag=true;
                    }
                    if(j-1>=0 &&this->grid[i][j-1]==FiveChessType_None){
                        *left=new FiveChessElement(i,j-1,this->grid[i][j-1]);
                        testFlag=true;
                    }
                    if(testFlag){
                        type=0;
                        length=4;
                        return;
                    }
                }

        }
    }
    //水平
    for(int j=0;j<ySize;j++){
        for(int i=0;i<xSize-4;i++){


            if(selfType==this->grid[i][j] &&selfType==this->grid[i+1][j] && selfType==this->grid[i+2][j] && selfType==this->grid[i+3][j]
                   ){
                bool testFlag=false;
                if(i+4<xSize &&this->grid[i+4][j]==FiveChessType_None){
                    *right=new FiveChessElement(i+4,j,this->grid[i+4][j]);
                   testFlag=true;
                }
                if(i-1>=0 &&this->grid[i-1][j]==FiveChessType_None){
                    *left=new FiveChessElement(i-1,j,this->grid[i-1][j]);
                    testFlag=true;
                }
                if(testFlag){
                    type=0;
                    length=4;
                    return;
                }
            }

        }
    }

    //上斜线  x+1,y-1   水平优先

    for(int j=4;j<ySize;j++){
        for(int i=0;i<xSize-4;i++){
            if(selfType==this->grid[i][j] &&selfType==this->grid[i+1][j-1] && selfType==this->grid[i+2][j-2] && selfType==this->grid[i+3][j-3]
                   ){
                bool testFlag=false;
                if(i+4<xSize && j-4>=0 &&this->grid[i+4][j-4]==FiveChessType_None){
                    *right=new FiveChessElement(i+4,j-4,this->grid[i+4][j-4]);
                   testFlag=true;
                }
                if(i-1>=0 && j+1<ySize &&this->grid[i-1][j+1]==FiveChessType_None){
                    *left=new FiveChessElement(i-1,j+1,this->grid[i-1][j+1]);
                    testFlag=true;
                }
                if(testFlag){
                    type=0;
                    length=4;
                    return;
                }
            }


        }
    }





    //下斜线  x+1,y+1 水平优先
    for(int j=0;j<ySize-4;j++){
        for(int i=0;i<xSize-4;i++){


            if(selfType==this->grid[i][j] &&selfType==this->grid[i+1][j+1] && selfType==this->grid[i+2][j+2] && selfType==this->grid[i+3][j+3]
                   ){
                bool testFlag=false;
                if(i+4<xSize && j+4<ySize &&this->grid[i+4][j+4]==FiveChessType_None){
                    *right=new FiveChessElement(i+4,j+4,this->grid[i+4][j+4]);
                   testFlag=true;
                }
                if(i-1>=0 && j-1>=0 &&this->grid[i-1][j-1]==FiveChessType_None){
                    *left=new FiveChessElement(i-1,j-1,this->grid[i-1][j-1]);
                    testFlag=true;
                }
                if(testFlag){
                    type=0;
                    length=4;
                    return;
                }
            }



        }
    }
/////////////////////////////////////////////////
    //defend live 3

    //attack live 3


    //attack dead 3

    //attack 2

    //defend 1




}





bool FiveChess::setChess(int xPos,int yPos,FiveChessType type){
    if(xPos<0 ||xPos >=this->xSize ||yPos<0 ||yPos >=this->ySize ){
        return false;
    }
    if(this->grid[xPos][yPos]==FiveChessType_None){
        this->grid[xPos][yPos]=type;
    }
    return true;

}
