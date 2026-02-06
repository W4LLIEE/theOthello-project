#include "board.h"
#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main() {

    //Game Variables
    int boardSize = 8; game board [boardSize][boardSize];      //Board Dimensions
    game curPlayer = BLACK, winner;
    int blkPts=2, whtPts=2, old_blkPts, old_whtPts;
    bool firstSkip = true;
    
    srand(time(NULL));
    
    boardInit(boardSize, board);
    
    while (1) {

        scanValid(boardSize, board, curPlayer);
        old_blkPts = blkPts;
        old_whtPts = whtPts;
        printf("\n\nSCORE\nBLACK : %d\t|\tWHITE : %d\n\n", blkPts, whtPts);
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
        
        autoPlay(boardSize, board, &curPlayer, &firstSkip);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);

        if ((old_blkPts == blkPts) || (old_whtPts == whtPts)) {
            printf("\nSCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
            boardPrint(boardSize, board, curPlayer);
            printf("ERROR - NO PIECES FLIPPED");
            break;
        }

        if (!((old_blkPts+old_whtPts+1)==(blkPts+whtPts))) {
            printf("\nSCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
            boardPrint(boardSize, board, curPlayer);
            printf("ERROR - PIECES DONT ADD UP");
            break;
        }
        
    }

    return 0;
}