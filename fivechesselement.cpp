#include "fivechesselement.h"

FiveChessElement::FiveChessElement()
{
}
FiveChessElement::~FiveChessElement()
{
}
FiveChessElement::FiveChessElement(int newX,int newY,enum FiveChessType type):
    x(newX),
    y(newY),
    type(type)
{

}
void FiveChessElement::setX(int x){
    this->x=x;
}
int FiveChessElement::getX(void){
    return this->x;
}
void FiveChessElement::setY(int y){
    this->y=y;
}
int FiveChessElement::getY(void){
    return this->y;
}
void FiveChessElement::setType(enum FiveChessType type){
    this->type=type;
}
enum FiveChessType FiveChessElement::getType(void){
    return this->type;
}
