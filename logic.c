#include "board.h"
#include "logic.h"
#include <stdio.h>
#include <stdbool.h>


bool checkValid(int boardSize, game board[boardSize][boardSize], 
                    int pos_x, int pos_y, game curPlayer) 
{ 
    int dirx[]={1, 1, 1, 0, -1, -1, -1, 0};
    int diry[]={-1, 0, 1, 1, 1, 0, -1, -1};
    game opp = curPlayer == BLACK ? WHITE : BLACK;

    // Check In Bounds
    if (pos_x<0 || pos_x>=boardSize || pos_y<0 || pos_y>=boardSize)
        return false;

    // Check Empty
    if (board[pos_x][pos_y] != EMPTY)
        return false;

    // Scan all directions
    for (int i = 0; i < 8; i++) {

        int dx = pos_x+dirx[i];
        int dy = pos_y+diry[i];

        if ((dx>=boardSize) || (dy>=boardSize) || (dx<0) || (dy<0) || board[dx][dy] != opp)
            continue;  
            
        while ((dx < boardSize) && (dx >= 0) && (dy < boardSize) && (dy >= 0))
        {
            if (board[dx][dy] == EMPTY)
                    break;
        
            if (board[dx][dy] == curPlayer)
                return true;

            dx+=dirx[i];
            dy+=diry[i]; 
                      
        }

    } return false;
}

void Pmove(int boardSize, game board[boardSize][boardSize], game *curPlayer) {
    
    // Player moves
    int pos_x, pos_y;
    bool isValid;

    printf("%s's turn. Make your move (posX posY): ", 
            *curPlayer == BLACK ? "Black" : "White");

    scanf("%d %d", &pos_x, &pos_y);
    
    
    if (board[pos_x][pos_y] == VALID) {
        if (*curPlayer == BLACK) {
            board[pos_x][pos_y] = BLACK;
            *curPlayer = WHITE;
        } else if (*curPlayer == WHITE) {
            board[pos_x][pos_y] = WHITE;
            *curPlayer = BLACK;
        }
    } else {
        printf("Invalid move.\n%s's turn. Make your move (posX posY): ", 
                *curPlayer == BLACK ? "Black" : "White");
    }

    return;
}

