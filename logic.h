// logic.h

#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"
#include <stdbool.h>

bool checkValid(int boardSize, game board[boardSize][boardSize],
    int pos_x, int pos_y, game curPlayer);

void Play(int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip, bool *invalid, bool *quit);

void scanValid(int boardSize, game board[boardSize][boardSize], game curPlayer);

void flip(int boardSize, game board[boardSize][boardSize],
    int pos_x, int pos_y, game curPlayer);          

void countScore(int boardSize, game board[boardSize][boardSize], int *blkPts, int *whtPts, game *winner);

bool gameOver(int boardSize, game board[boardSize][boardSize]);

void autoPlay(int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip);

void vsComp (int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip, bool *invalid, bool *quit, char *cmpInp);

void vsMedComp (int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip, bool *invalid, bool *quit, char *cmpInp, int blkPts, int whtPts);

void simGame (int boardSize, game board[boardSize][boardSize],
            int whtPts, int blkPts, int *pos_x, int *pos_y, 
            int cnt, int val_x[cnt], int val_y[cnt]);
#endif