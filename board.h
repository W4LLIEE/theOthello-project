// board.h


#ifndef BOARD_H
#define BOARD_H

typedef enum game {EMPTY, BLACK, WHITE, VALID} game;

char * tochar(game b);

void boardInit(int boardSize, game board[boardSize][boardSize]);

void boardPrint(int boardSize, game board[boardSize][boardSize], game curPlayer);


#endif