#include "board.h"
#include "logic.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char tochar(game b) {
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
    case VALID:
        return '*';
        break;
    default:
        return '?';
        break;
}
}

void boardInit(int boardSize, game board[boardSize][boardSize]) {

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

void boardPrint(int boardSize, game board[boardSize][boardSize], game curPlayer) {
    
    int pos_y, pos_x;

    printf("\n     A B C D E F G H\n\n");
    
    //Loop to output current board status
    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        printf("  %d  ", pos_y+1);
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            printf("%c ", tochar(board [pos_x][pos_y]));
        }
        
        printf("\n");

    }

    return;
}
