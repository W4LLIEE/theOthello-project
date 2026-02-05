// logic.h

#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"
#include <stdbool.h>

bool checkValid(int boardSize, game board[boardSize][boardSize],
    int pos_x, int pos_y, game curPlayer);

void Play(int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip);

void scanValid(int boardSize, game board[boardSize][boardSize], game curPlayer);

void flip(int boardSize, game board[boardSize][boardSize],
    int pos_x, int pos_y, game curPlayer);          

void countScore(int boardSize, game board[boardSize][boardSize], int *blkPts, int *whtPts, game *winner);

bool gameOver(int boardSize, game board[boardSize][boardSize]);



#endif