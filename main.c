#include "board.h"
#include "logic.h"
#include <stdio.h>

int main()
{

    //Board Info Variables
    int boardSize = 8; game board [boardSize][boardSize];      //Board Dimensions
    game curPlayer = BLACK;
    
    boardInit(boardSize, board);
    boardPrint(boardSize, board, curPlayer);
    
    while (1) {
    
        Pmove(boardSize, board, &curPlayer);
        boardPrint(boardSize, board, curPlayer);
    
    }

    return 0;
}