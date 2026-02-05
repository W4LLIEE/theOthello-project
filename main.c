#include "board.h"
#include "logic.h"
#include <stdio.h>

int main()
{

    //Game Variables
    int boardSize = 8; game board [boardSize][boardSize];      //Board Dimensions
    game curPlayer = BLACK, winner;
    int blkPts=2, whtPts=2;
    bool firstSkip = true;
    
    boardInit(boardSize, board);
    
    while (1) {

        scanValid(boardSize, board, curPlayer);
        printf("\nSCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
        boardPrint(boardSize, board, curPlayer);

        if (gameOver(boardSize, board)){
                if (firstSkip) {
                    curPlayer = curPlayer == BLACK ? WHITE : BLACK;
                    printf("\nTurn Skipped.\n");
                    firstSkip = false;
                    continue;
                }
                if (winner==EMPTY) {
                    printf("\n\nTIE GAME\n\n");
                    break;
                }
                printf("\n\nGAME OVER\n\nWINNER : %s\n     %d - %d\n", 
                    winner==BLACK ? "Black" : "White", blkPts, whtPts);
                break;
            }
        
        Play(boardSize, board, &curPlayer, &firstSkip);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);
        
        
        
    }

    return 0;
}