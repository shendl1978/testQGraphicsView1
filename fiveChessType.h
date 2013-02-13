#ifndef FIVECHESSTYPE_H
#define FIVECHESSTYPE_H
#define CMDS_LENGTH  1024
#define STR_LEN 256
#define ARRAY_LEN  256
#define MAX_HORIZONTAL  100
#define MAX_VERTICAL  100
enum FiveChessType{
    FiveChessTypeNone,
    FiveChessTypeBlack,
    FiveChessTypeWhite
};
extern const char * g_FiveChessTypeCStr[ARRAY_LEN];

#endif // FIVECHESSTYPE_H
