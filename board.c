#include <stdio.h>
#include "board.h"

char tochar(board b) {
    switch (b)
    {
    case EMPTY:
        return '.';
        break;
    case BLACK:
        return 'X';
        break;
    case WHITE:
        return 'O';
        break;
    default:
        return '?';
        break;
}
}

void boardInit(int boardSize, board board[boardSize][boardSize]) {

    int pos_y, pos_x;

    //Loop to store board status - INITIALIZE
    //Outer Loop for x-axis
    for (pos_y = 0; pos_y < boardSize; pos_y++) {

        //Inner loop for y-axis
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            

                //Initial Pieces Placement - Black
                if ((pos_y == ((boardSize/2)-1) && pos_x == (boardSize/2))
                    || pos_y == ((boardSize/2)) && pos_x == ((boardSize/2)-1)) 
                {
                    board[pos_x][pos_y] = BLACK;
                    continue;
                }

                //Initial Pieces Placement - White
                if ((pos_y == (boardSize/2) && pos_x == (boardSize/2))
                    || pos_y == ((boardSize/2)-1) && pos_x == ((boardSize/2)-1)) 
                {
                    board[pos_x][pos_y] = WHITE;
                    continue;
                }
            
            board [pos_x][pos_y] = EMPTY;
        }

    }
    
    return;
}

void boardPrint(int boardSize, board board[boardSize][boardSize]) {
    
    int pos_y, pos_x;
    
    //Loop to output current board status
    for (pos_y = 0; pos_y < boardSize; pos_y++) {

        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            printf("%c ", tochar(board [pos_x][pos_y]));
        }

        printf("\n");

    }

    return;
}