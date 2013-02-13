#ifndef FIVECHESS_H
#define FIVECHESS_H

#include "fivechesselement.h"


class FiveChess
{
public:
    FiveChess();
    FiveChess( int xSize,int ySize,int elementSize);
    virtual ~FiveChess();
    ////Robert will use this method to play chess.
    void recommendSteps(enum FiveChessType selfType,FiveChessElement **left,FiveChessElement **right,int &length,int &type);
    enum FiveChessType winner(void);
    bool setChess(int xPos,int yPos,enum FiveChessType type);
    //////////////////////////////////
    int getXSize();
    void setXSize(int xSize);
    int getYSize();
    void setYSize(int ySize);
    int getElementSize(void);
    void setElementSize(int elementSize);
    int getCurrentIndex(void);
    bool pushCmd( FiveChessElement * cmd);
     FiveChessElement * popCmd(void);
     void reset(void);
private:
    int xSize;
    int ySize;
    int elementSize;
    enum FiveChessType grid[MAX_HORIZONTAL][MAX_VERTICAL];
    int currentIndex;
    FiveChessElement *cmds[CMDS_LENGTH];


};

#endif // FIVECHESS_H
