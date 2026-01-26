#include "board.h"

int main()
{

    //Board Info Variables
    int boardSize = 8; board board [boardSize][boardSize];      //Board Dimensions

    boardInit(boardSize, board);
    boardPrint(boardSize, board);
    

    return 0;
}