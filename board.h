// board.h


#ifndef BOARD_H
#define BOARD_H

typedef enum board {EMPTY, BLACK, WHITE} board;

char tochar(board b);

void boardInit(int boardSize, board board[boardSize][boardSize]);

void boardPrint(int boardSize, board board[boardSize][boardSize]);


#endif