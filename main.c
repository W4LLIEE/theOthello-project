#include "board.h"
#include "logic.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

void computer(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner) {

    while (1) {

        scanValid(boardSize, board, curPlayer);
        old_blkPts = blkPts;
        old_whtPts = whtPts;
        printf("\n\n  SCORE\n  BLACK : %d\t|\tWHITE : %d\n\n", blkPts, whtPts);
        boardPrint(boardSize, board, curPlayer);

        if (gameOver(boardSize, board)){
                if (firstSkip) {
                    curPlayer = curPlayer == BLACK ? WHITE : BLACK;
                    printf("\n  Turn Skipped.\n");
                    firstSkip = false;
                    continue;
                }
                if (winner==EMPTY) {
                    printf("\n\n  TIE GAME\n\n");
                    break;
                }
                printf("\n\n  GAME OVER\n\n  WINNER : %s\n     %d - %d\n", 
                    winner==BLACK ? "Black" : "White", blkPts, whtPts);
                break;
            }
        
        autoPlay(boardSize, board, &curPlayer, &firstSkip);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);

        if ((old_blkPts == blkPts) || (old_whtPts == whtPts)) {
            printf("\n  SCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
            boardPrint(boardSize, board, curPlayer);
            printf("  ERROR - NO PIECES FLIPPED");
            break;
        }

        if (!((old_blkPts+old_whtPts+1)==(blkPts+whtPts))) {
            printf("\n  SCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
            boardPrint(boardSize, board, curPlayer);
            printf("  ERROR - PIECES DONT ADD UP");
            break;
        }
        
    }


    return;
}

void human(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner) {

    bool invalid;

    while (1) {

        clrScr();
        scanValid(boardSize, board, curPlayer);
        old_blkPts = blkPts;
        old_whtPts = whtPts;
        printf("\n\n  SCORE\n  BLACK : %d\t|\tWHITE : %d\n\n", blkPts, whtPts);
        boardPrint(boardSize, board, curPlayer);

        if (gameOver(boardSize, board)){
                if (firstSkip) {
                    curPlayer = curPlayer == BLACK ? WHITE : BLACK;
                    printf("\n  Turn Skipped.\n");
                    firstSkip = false;
                    continue;
                }
                if (winner==EMPTY) {
                    printf("\n\n  TIE GAME\n\n");
                    break;
                }
                printf("\n\n  GAME OVER\n\nWINNER : %s\n     %d - %d\n", 
                    winner==BLACK ? "Black" : "White", blkPts, whtPts);
                break;
            }
        
        Play(boardSize, board, &curPlayer, &firstSkip, &invalid);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);

        if (invalid)
            continue;

        if ((old_blkPts == blkPts) || (old_whtPts == whtPts)) {
            printf("\n  SCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
            boardPrint(boardSize, board, curPlayer);
            printf("  ERROR - NO PIECES FLIPPED");
            break;
        }

        if (!((old_blkPts+old_whtPts+1)==(blkPts+whtPts))) {
            printf("\n  SCORE\nBLACK : %d\t|\tWHITE : %d\n", blkPts, whtPts);
            boardPrint(boardSize, board, curPlayer);
            printf("  ERROR - PIECES DONT ADD UP");
            break;
        }
        
    }


    return;
}

void rules() {

    printf("\n  ──────── Rules ────────\n\n");
    printf("  • Players take turns placing pieces\n");
    printf("  • Pieces must trap opponent pieces\n");
    printf("  • Trapped pieces flip color\n");
    printf("  • Game ends when no moves remain\n\n");

    return;
}

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

        // scanf("%d", &optNum);
        // while ((trash = getchar()) != '\n' && trash != EOF);
        OPT = optNum;
        
        switch(OPT) {
            case PLAY:
                boardInit(boardSize, board);
                human(boardSize, board, curPlayer, old_blkPts, blkPts, old_whtPts, whtPts, firstSkip, winner);
                printf("\n\n  RETURN TO MENU\n  Enter anything to confirm: ");
                getchar();
                while ((trash = getchar()) && trash != EOF);
                disableRawMode();
                break;
            case AI:
                boardInit(boardSize, board);
                computer(boardSize, board, curPlayer, old_blkPts, blkPts, old_whtPts, whtPts, firstSkip, winner);
                printf("\n\n  RETURN TO MENU\n  Enter anything to confirm: ");
                enableRawMode();
                getchar();
                disableRawMode();
                break;
            case RULES:
                rules();
                printf("\n\n  RETURN TO MENU\n  Enter anything to confirm: ");
                enableRawMode();
                getchar();
                disableRawMode();
                break;
            case EXIT:
                printf("  Exitting Game...  \n");
                return 0;
            default:
                printf("  That's not an option.\n");
                printf("\n\n  RETURN TO MENU\n  Enter anything to confirm: ");
                enableRawMode();
                getchar();
                disableRawMode();
                break;
        }
    }

    return 0;
}