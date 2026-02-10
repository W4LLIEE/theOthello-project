#include "board.h"
#include "logic.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct termios oldt, newt;

void computer_easy(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner) {

    bool invalid, exit;
    char cmpInp[3];

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
                printf("\n\n  GAME OVER\n\n  WINNER : %s\n     %d - %d\n", 
                    winner==BLACK ? "Black" : "White", blkPts, whtPts);
                break;
            }

        if (blkPts+whtPts>4)
            printf("\n  White played %s.\n", cmpInp);
        vsComp (boardSize, board, &curPlayer, &firstSkip, &invalid, &exit, cmpInp);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);

        if (exit)
            break;

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

void computer_med(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner) {

    bool invalid, exit;
    char cmpInp[3];

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
                printf("\n\n  GAME OVER\n\n  WINNER : %s\n     %d - %d\n", 
                    winner==BLACK ? "Black" : "White", blkPts, whtPts);
                break;
            }

        if (blkPts+whtPts>4)
            printf("\n  White played %s.\n", cmpInp);
        vsMedComp (boardSize, board, &curPlayer, &firstSkip, &invalid, &exit, cmpInp, blkPts, whtPts);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);

        if (exit)
            break;

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

void human(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner) {

    bool invalid, exit;

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
        
        Play(boardSize, board, &curPlayer, &firstSkip, &invalid, &exit);
        countScore(boardSize, board, &blkPts, &whtPts, &winner);

        
        if (exit)
            break;

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

    clrScr();

    printf("\n  ──────── Rules ────────\n\n");
    printf("  • Players take turns placing pieces\n");
    printf("  • Pieces must trap opponent pieces\n");
    printf("  • Trapped pieces flip color\n");
    printf("  • Game ends when no moves remain\n\n");

    return;
}


void enableRawMode() {
    tcgetattr(STDIN_FILENO, &oldt);   // save current terminal state
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO); // disable line buffering + echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    return;
}

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return;
}

void clrScr() {

    printf("\033[2J\033[H");

    //system("@cls||clear");

    return;
}

void menuPrt1() {
    
    clrScr();
    
    printf("\n  ──────────────────────────────\n");
    printf("          O T H E L L O\n");
    printf("  ──────────────────────────────\n\n");
    printf("          [ Play Game ]\n");
    printf("            Play vs AI\n");
    printf("            Rules\n");
    printf("            Exit\n\n");
    printf("  ──────────────────────────────\n");
    printf("        Black ●   White ○\n");
    printf("  ──────────────────────────────\n\n");
    
    //printf("\n\n  Select an Option (1-4) : ");

    return;

}

void menuPrt2() {
    
    clrScr();
    
    printf("\n  ──────────────────────────────\n");
    printf("          O T H E L L O\n");
    printf("  ──────────────────────────────\n\n");
    printf("            Play Game\n");
    printf("          [ Play vs AI ]\n");
    printf("            Rules\n");
    printf("            Exit\n\n");
    printf("  ──────────────────────────────\n");
    printf("        Black ●   White ○\n");
    printf("  ──────────────────────────────\n\n");
    
    //printf("\n\n  Select an Option (1-4) : ");

    return;

}

void menuPrt3() {
    
    clrScr();
    
    printf("\n  ──────────────────────────────\n");
    printf("          O T H E L L O\n");
    printf("  ──────────────────────────────\n\n");
    printf("            Play Game\n");
    printf("            Play vs AI\n");
    printf("          [ Rules ]\n");
    printf("            Exit\n\n");
    printf("  ──────────────────────────────\n");
    printf("        Black ●   White ○\n");
    printf("  ──────────────────────────────\n\n");
    
    //printf("\n\n  Select an Option (1-4) : ");

    return;

}

void menuPrt4() {
    
    clrScr();
    
    printf("\n  ──────────────────────────────\n");
    printf("          O T H E L L O\n");
    printf("  ──────────────────────────────\n\n");
    printf("            Play Game\n");
    printf("            Play vs AI\n");
    printf("            Rules\n");
    printf("          [ Exit ]\n\n");
    printf("  ──────────────────────────────\n");
    printf("        Black ●   White ○\n");
    printf("  ──────────────────────────────\n\n");
    
    //printf("\n\n  Select an Option (1-4) : ");

    return;

}

void SubMenuPrt1() {

    clrScr();

    printf("\n  ────── AI Difficulty ──────\n\n");
    printf("          [ Easy ]\n");
    printf("            Medium\n");
    printf("            Hard (Coming Soon)\n");
    printf("            Main Menu  \n");
    return;
}

void SubMenuPrt2() {

    clrScr();

    printf("\n  ────── AI Difficulty ──────\n\n");
    printf("            Easy\n");
    printf("          [ Medium ]\n");
    printf("            Hard (Coming Soon)\n");
    printf("            Main Menu  \n");
    return;
}

void SubMenuPrt3() {

    clrScr();
    
    printf("\n  ────── AI Difficulty ──────\n\n");
    printf("            Easy\n");
    printf("            Medium\n");
    printf("          [ Hard ] (Coming Soon)\n");
    printf("            Main Menu  \n");
    return;
}

void SubMenuPrt4() {

    clrScr();

    printf("\n  ────── AI Difficulty ──────\n\n");
    printf("            Easy\n");
    printf("            Medium\n");
    printf("            Hard (Coming Soon)\n");
    printf("          [ Main Menu ] \n");
    return;
}

void subMenu(int boardSize,  game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner) {

    char c, arrow, arrowUp[] = "\033[A", arrowDown[]="\033[B";
    int optNum=1;
    char trash;
    sub sub;

    while (1) {
        
        enableRawMode();

        switch(optNum) {
            case 1:
                SubMenuPrt1();
                break;
            case 2:
                SubMenuPrt2();
                break;
            case 3:
                SubMenuPrt3();
                break;
            case 4:
                SubMenuPrt4();
            default:
                break;
        }

        printf("\n\n\n  Navigate with UP/DOWN arrow keys\n  Enter to confirm option.");
        c = getchar();

        if (c == '\033') {

            getchar();
            arrow = getchar();

            if (arrow=='A') {
                if (optNum==1) {
                    optNum=4;
                } else {optNum--;}
            }

            if (arrow=='B') {
                if (optNum==4) {
                    optNum=1;
                } else {optNum++;}
            }

        } else if (c == '\n') {
            disableRawMode();
            break;
        }
        
        disableRawMode();

    }

    sub=optNum;
    
    switch(sub) {
        case EASY:
            boardInit(boardSize, board);
            computer_easy(boardSize, board, curPlayer, old_blkPts, blkPts, old_whtPts, whtPts, firstSkip, winner);
            printf("\n\n  RETURN TO MENU");
            enableRawMode();
            getchar();
            disableRawMode();
            return;
            break;
        case MEDIUM:
            boardInit(boardSize, board);
            computer_med(boardSize, board, curPlayer, old_blkPts, blkPts, old_whtPts, whtPts, firstSkip, winner);
            printf("\n\n  RETURN TO MENU");
            enableRawMode();
            getchar();
            disableRawMode();
            return;
            break;
        case HARD:
            printf("\n\n  COMING SOON  \n");
            printf("\n\n  RETURN TO MENU");
            enableRawMode();
            getchar();
            disableRawMode();
            return;
        case MAIN:
            return;
            break;
        default:
            break;
    }

    
}

int menuRun(int optNum) {

    char c, arrow, arrowUp[] = "\033[A", arrowDown[]="\033[B";
    optNum=1;
    char trash;
    

    while (1) {
        
        enableRawMode();

        switch(optNum) {
            case 1:
                menuPrt1();
                break;
            case 2:
                menuPrt2();
                break;
            case 3:
                menuPrt3();
                break;
            case 4:
                menuPrt4();
                break;
            default:
                break;
        }

        printf("\n\n\n  Navigate with UP/DOWN arrow keys\n  Enter to confirm option.");
        c = getchar();

        if (c == '\033') {

            getchar();
            arrow = getchar();

            if (arrow=='A') {
                if (optNum==1) {
                    optNum=4;
                } else {optNum--;}
            }

            if (arrow=='B') {
                if (optNum==4) {
                    optNum=1;
                } else {optNum++;}
            }

        } else if (c == '\n') {
            disableRawMode();
            return optNum;
        }
        
        disableRawMode();

    }

}
