#ifndef FIVECHESSTYPE_H
#define FIVECHESSTYPE_H
#define CMDS_LENGTH  1024
#define STR_LEN 256
#define ARRAY_LEN  256
#define MAX_HORIZONTAL  100
#define MAX_VERTICAL  100
//FiveChess( int xSize,int ySize,int elementSize);
#define FiveChess_XSize 19
#define FiveChess_YSize 19
#define FiveChess_ElementSize 20
enum FiveChessType{
    FiveChessType_None,
    FiveChessType_Black,
    FiveChessType_White
};
enum FiveChessEnemyType{
    FiveChessEnemyType_Robot,
    FiveChessEnemyType_LocalUser,
    FiveChessEnemyType_RemoteUser
};
extern const char * g_FiveChessTypeCStr[ARRAY_LEN];

#endif // FIVECHESSTYPE_H
