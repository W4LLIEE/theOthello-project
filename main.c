#include "board.h"
#include "logic.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int main() {

    //Game Variables
    int boardSize = 8; game board [boardSize][boardSize];      //Board Dimensions
    game curPlayer = BLACK, winner;
    int blkPts=2, whtPts=2, old_blkPts, old_whtPts;
    bool firstSkip = true;
    int optNum; menu OPT;
    bool BTM; char trash;
    struct termios oldt, newt;

    
    srand(time(NULL));
    
    boardInit(boardSize, board);

    while (1) {

        optNum=menuRun(optNum);
        OPT = optNum;
        
        switch(OPT) {
            case PLAY:
                boardInit(boardSize, board);
                human(boardSize, board, curPlayer, old_blkPts, blkPts, old_whtPts, whtPts, firstSkip, winner);
                printf("\n\n  RETURN TO MENU");       
                enableRawMode();
                getchar();
                disableRawMode();
                break;
            case AI:
                subMenu(boardSize, board, curPlayer, old_blkPts, blkPts, old_whtPts, whtPts, firstSkip, winner);
                break;
            case RULES:
                rules();
                printf("\n\n  RETURN TO MENU");
                enableRawMode();
                getchar();
                disableRawMode();
                break;
            case EXIT:
                printf("\n\n  Exitting Game...  \n\n  ");
                return 0;
            default:
                printf("  That's not an option.\n");
                printf("\n\n  RETURN TO MENU");
                enableRawMode();
                getchar();
                disableRawMode();
                break;
        }
    }

    return 0;
}