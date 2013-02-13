#ifndef FIVECHESSELEMENT_H
#define FIVECHESSELEMENT_H
#include "fiveChessType.h"
class FiveChessElement
{
public:
    FiveChessElement();
    FiveChessElement(int x,int y,enum FiveChessType type);
    virtual ~FiveChessElement();
    ///////////////////////
    void setX(int x);
    int getX(void);
    void setY(int y);
    int getY(void);
    void setType(enum FiveChessType type);
    enum FiveChessType getType(void);
private:
    enum FiveChessType type;
    int x;
    int y;

};

#endif // FIVECHESSELEMENT_H
