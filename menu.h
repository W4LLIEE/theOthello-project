// menu.h


#ifndef MENU_H
#define MENU_H

#include <termios.h>
#include <unistd.h>
#include <stdbool.h>

typedef enum menu {PLAY=1, AI, RULES, EXIT,}menu;
typedef enum sub {EASY=1, MEDIUM, HARD, MAIN}sub;

void computer(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner);

void human(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner);

void computer_easy(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
int old_whtPts, int whtPts, bool firstSkip, game winner);

void computer_med(int boardSize, game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
int old_whtPts, int whtPts, bool firstSkip, game winner);

void rules();

void enableRawMode();
void disableRawMode();
void clrScr();
void menuPrt1();
void menuPrt2();
void menuPrt3();
void menuPrt4();
void SubMenuPrt1();
void SubMenuPrt2();
void SubMenuPrt3();
void SubMenuPrt4();
void subMenu(int boardSize,  game board[boardSize][boardSize], game curPlayer, int old_blkPts, int blkPts,
        int old_whtPts, int whtPts, bool firstSkip, game winner);

int menuRun(int optNum);

#endif