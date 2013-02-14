#ifndef FIVECHESS_H
#define FIVECHESS_H

#include "fivechesselement.h"


class FiveChess
{
public:
    FiveChess(void);
    FiveChess( int xSize,int ySize,int elementSize);

    virtual ~FiveChess();
    static FiveChess *getInstance(void);
    ////Robert will use this method to play chess.
    virtual void recommendSteps(enum FiveChessType selfType,FiveChessElement **left,FiveChessElement **right,int &length,int &type);
    virtual enum FiveChessType winner(void);
    virtual bool setChess(int xPos,int yPos,enum FiveChessType type);
    //////////////////////////////////
    virtual int getXSize() const;
    virtual void setXSize(int xSize) ;
    virtual int getYSize() const;
    virtual void setYSize(int ySize);
    virtual int getElementSize(void) const;
    virtual void setElementSize(int elementSize);
    virtual int getCurrentIndex(void) const;
    virtual bool pushCmd( FiveChessElement * cmd);
    virtual FiveChessElement * popCmd(void);
    virtual void reset(void);
    virtual bool isGameRunning(void) const;
    virtual  void setGameRunning(bool gameRunning);
    //virtual int getStep(void) const;
   // virtual void setStep(int step);
   // virtual int incrementStep(void);
    virtual int getBlackWinRecord(void) const;
    virtual void  setBlackWinRecord(int blackWinRecord);

    virtual int getBlackLoseRecord(void) const;
    virtual void  setBlackLoseRecord(int blackLoseRecord);

    virtual int getWhiteWinRecord(void) const;
     virtual void setWhiteWinRecord(int whiteWinRecord);

    virtual int getWhiteLoseRecord(void) const;
    virtual void setWhiteLoseRecord(int whiteLoseRecord);
    ///////
    virtual bool recordWin(enum FiveChessType winType,int &blackWinRecord,int &blackLoseRecord,int &whiteWinRecord,int &whiteLoseRecord);
    virtual enum FiveChessEnemyType getEnemyType(void) const;
    virtual void setEnemyType(enum FiveChessEnemyType enemyType);
private:
    static FiveChess *instance;
    int xSize;
    int ySize;
    int elementSize;
    enum FiveChessType grid[MAX_HORIZONTAL][MAX_VERTICAL];
    int currentIndex;
    FiveChessElement *cmds[CMDS_LENGTH];
    bool gameRunning;
   // int step;
    //0  robot. 1  user
    enum FiveChessEnemyType  enemyType;
    int blackWinRecord;
    int blackLoseRecord;
    int whiteWinRecord;
    int whiteLoseRecord;

};

#endif // FIVECHESS_H
