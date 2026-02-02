#include "board.h"
#include "logic.h"
#include <stdio.h>

int main()
{

    //Board Info Variables
    int boardSize = 8; game board [boardSize][boardSize];      //Board Dimensions
    game curPlayer = BLACK, winner;
    int blkPts=2, whtPts=2;
    
    boardInit(boardSize, board);
    printf("\nSCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
    boardPrint(boardSize, board, curPlayer);
    
    while (1) {
    
        Play(boardSize, board, &curPlayer);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);
        printf("\nSCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
        boardPrint(boardSize, board, curPlayer);
        
        if (gameOver(boardSize, board)){
            if (winner==EMPTY) {
                printf("\n\nTIE GAME\n\n");
                break;
            }
            printf("\n\nGAME OVER\n\nWINNER : %s\n     %d - %d\n", 
                winner==BLACK ? "Black" : "White", blkPts, whtPts);
            break;
        }
    
    }

    return 0;
}