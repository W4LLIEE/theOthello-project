#include "board.h"
#include "logic.h"
#include "menu.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


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
            if (board[dx][dy] == VALID)
                break;
        
            if (board[dx][dy] == curPlayer)
                return true;

            dx+=dirx[i];
            dy+=diry[i]; 
                      
        }

    } return false;
}

void Play(int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip, bool *invalid, bool *quit) {
    
    // Player moves
    int pos_x, pos_y;
    bool isValid;
    char ex[] = "ex", EX[] = "EX"; 
    *invalid = false;
    *quit = false;

    char input[3];

    printf("\n  %s's turn. Make your move (Enter 'EX' to quit): ", 
            *curPlayer == BLACK ? "Black" : "White");

    // Take and Check input
    fgets(input, sizeof(input), stdin);
    char c;
    while ((c = getchar()) != '\n' && c != EOF);

    if (strcmp(input, EX)==0 || strcmp(input, ex)==0) {
        *quit=true;
        return;
    }
    pos_x = input[0]-65;
    pos_y = input[1]-49;


    // Play move if valid
    if (board[pos_x][pos_y] == VALID) {
        if (*curPlayer == BLACK) {
            board[pos_x][pos_y] = BLACK;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = WHITE; 
        } else if (*curPlayer == WHITE) {
            board[pos_x][pos_y] = WHITE;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = BLACK;
        }
    } else {
                *invalid = true;
    }

    // Reset turn skipping
    *firstSkip = true;
}

void scanValid(int boardSize, game board[boardSize][boardSize], game curPlayer) {

    int pos_x, pos_y;

    // Reset all VALID positions
    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            
            if (board[pos_x][pos_y]==VALID)
                board[pos_x][pos_y]=EMPTY;
        }

    }

    // Check all positions
    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            
            bool isValid=checkValid(boardSize, board, pos_x, pos_y, curPlayer);
        
            if (isValid)
                board[pos_x][pos_y] = VALID;
        }
    }

    return;
}

void flip(int boardSize, game board[boardSize][boardSize],
    int pos_x, int pos_y, game curPlayer)
{
    int dirx[]={1, 1, 1, 0, -1, -1, -1, 0};
    int diry[]={-1, 0, 1, 1, 1, 0, -1, -1};
    game opp = curPlayer == BLACK ? WHITE : BLACK;

    // Scan all directions

    for (int i = 0; i < 8; i++) {   

        int dx = pos_x+dirx[i];
        int dy = pos_y+diry[i];
        bool valid=false;


        if ((dx>=boardSize) || (dy>=boardSize) || (dx<0) || (dy<0) || board[dx][dy] != opp)
            continue;

        while ((dx < boardSize) && (dx >= 0) && (dy < boardSize) && (dy >= 0)) {   
            
            for (int j = dx, k = dy; 
                (j < boardSize) && (j >= 0) && (k < boardSize) && (k >= 0); 
                j += dirx[i], k += diry[i]) 
            {
                if (board[j][k] == EMPTY)
                    break;
                if (board[j][k] == VALID)
                    break;
                
                if (board[j][k] == curPlayer) {
                    valid=true;
                    break;
                }
            }

            if (!valid)
                break;
            
            if (board[dx][dy] == opp)
                board[dx][dy] = curPlayer;

            dx+=dirx[i];
            dy+=diry[i];

            if (board[dx][dy] == curPlayer)
                break;

        }

    }
    return;
}

void countScore(int boardSize, game board[boardSize][boardSize], int *blkPts, int *whtPts, game *winner) {

    int pos_y, pos_x;
    *blkPts=0;
    *whtPts=0;
    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            if (board[pos_x][pos_y]==BLACK)
                (*blkPts)++;
            if (board[pos_x][pos_y]==WHITE)
                (*whtPts)++;
        }

    }

    if ((*blkPts)>(*whtPts)) {*winner=BLACK;} 
    else if ((*blkPts)<(*whtPts)){*winner=WHITE;}
    else {*winner=EMPTY;}
}

bool gameOver(int boardSize, game board[boardSize][boardSize]) {

    int pos_y, pos_x;

    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            if (board[pos_x][pos_y]==VALID)
                return false;
        }

    }
    return true;
}

void autoPlay(int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip) {


    // Player moves
    int pos_x, pos_y, cnt=0, random;
    bool isValid;
    int val_x[60], val_y[60];

    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            
            if (board[pos_x][pos_y]==VALID) {
                val_x[cnt] = pos_x;
                val_y[cnt] = pos_y;
                cnt++;
            }
        }

    }

    random = rand() % cnt;

    pos_x = val_x[random];
    pos_y = val_y[random];

    printf("\n  %s's turn. Make your move (posX posY): %d %d", 
            *curPlayer == BLACK ? "Black" : "White", pos_x, pos_y);

    // Play move if valid
    if (board[pos_x][pos_y] == VALID) {
        if (*curPlayer == BLACK) {
            board[pos_x][pos_y] = BLACK;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = WHITE;
        } else if (*curPlayer == WHITE) {
            board[pos_x][pos_y] = WHITE;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = BLACK;
        }
    }

    // Reset turn skipping
    *firstSkip = true;


}

void vsComp (int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip, bool *invalid, bool *quit, char *cmpInp) {


    // Player moves
    int pos_x, pos_y, cnt=0, random;
    bool isValid;
    int val_x[60], val_y[60];
    char input[3], ex[] = "ex", EX[] = "EX";
    *invalid = false;
    *quit = false;

    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            
            if (board[pos_x][pos_y]==VALID) {
                val_x[cnt] = pos_x;
                val_y[cnt] = pos_y;
                cnt++;
            }
        }

    }

    if (*curPlayer == WHITE) {

        random = rand() % cnt;

        pos_x = val_x[random];
        pos_y = val_y[random];

        cmpInp[0] = pos_x + 65;
        cmpInp[1] = pos_y + 49;
        
    } else if (*curPlayer == BLACK) {

        printf("\n  %s's turn. Make your move (Enter 'EX' to quit): ", 
                *curPlayer == BLACK ? "Black" : "White");

        // Take and Check input
        fgets(input, sizeof(input), stdin);
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (strcmp(input, EX)==0 || strcmp(input, ex)==0) {
            *quit=true;
            return;
        }
        pos_x = input[0]-65;
        pos_y = input[1]-49;
        
    }

    // Play move if valid
    if (board[pos_x][pos_y] == VALID) {
        if (*curPlayer == BLACK) {
            board[pos_x][pos_y] = BLACK;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = WHITE; 
        } else if (*curPlayer == WHITE) {
            board[pos_x][pos_y] = WHITE;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = BLACK;
        }
    } else {
                *invalid = true;
    }

    // Reset turn skipping
    *firstSkip = true;


}

void vsMedComp (int boardSize, game board[boardSize][boardSize], game *curPlayer, bool *firstSkip, bool *invalid, bool *quit, char *cmpInp, int blkPts, int whtPts) {


    // Player moves
    int pos_x, pos_y, cnt=0, random;
    bool isValid;
    int val_x[60], val_y[60];
    char input[3], ex[] = "ex", EX[] = "EX";
    *invalid = false;
    *quit = false;

    for (pos_y = 0; pos_y < boardSize; pos_y++) {
        
        for (pos_x = 0; pos_x < boardSize; pos_x++) {
            
            if (board[pos_x][pos_y]==VALID) {
                val_x[cnt] = pos_x;
                val_y[cnt] = pos_y;
                cnt++;
            }
        }

    }

    if (*curPlayer == WHITE) {

        simGame(boardSize, board, whtPts, blkPts, &pos_x, &pos_y, cnt, val_x, val_y);

        cmpInp[0] = pos_x + 65;
        cmpInp[1] = pos_y + 49;
        
    } else if (*curPlayer == BLACK) {

        printf("\n  %s's turn. Make your move (Enter 'EX' to quit): ", 
                *curPlayer == BLACK ? "Black" : "White");

        // Take and Check input
        fgets(input, sizeof(input), stdin);
        char c;
        while ((c = getchar()) != '\n' && c != EOF);

        if (strcmp(input, EX)==0 || strcmp(input, ex)==0) {
            *quit=true;
            return;
        }
        pos_x = input[0]-65;
        pos_y = input[1]-49;
        
    }

    // Play move if valid
    if (board[pos_x][pos_y] == VALID) {
        if (*curPlayer == BLACK) {
            board[pos_x][pos_y] = BLACK;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = WHITE; 
        } else if (*curPlayer == WHITE) {
            board[pos_x][pos_y] = WHITE;
            flip(boardSize, board, pos_x, pos_y, *curPlayer);
            *curPlayer = BLACK;
        }
    } else {
                *invalid = true;
    }

    // Reset turn skipping
    *firstSkip = true;


}

void simGame (int boardSize, game board[boardSize][boardSize],
            int whtPts, int blkPts, int *pos_x, int *pos_y, 
            int cnt, int val_x[cnt], int val_y[cnt]) {
            
    game sim_Board[boardSize][boardSize], sim_curPlayer, sim_winner;
    int sim_blkPts, sim_whtPts;
    int old_whtPts, gain=0, maxGain=0;

    for (int i = 0; i < cnt; i++) {

        for (int y = 0; y < boardSize; y++) {

            for (int x = 0; x < boardSize; x++) {
                sim_Board[x][y] = board[x][y];
            }

        }

        sim_curPlayer = WHITE;
        sim_blkPts = blkPts;
        sim_whtPts = whtPts;
        sim_winner = EMPTY;

        old_whtPts = sim_whtPts;

        int sim_pos_x = val_x[i];
        int sim_pos_y = val_y[i];

        sim_Board[sim_pos_x][sim_pos_y] = WHITE;
        flip(boardSize, sim_Board, sim_pos_x, sim_pos_y, sim_curPlayer);
        countScore(boardSize, sim_Board, &sim_blkPts, &sim_whtPts, &sim_winner);
        
        gain = sim_whtPts - old_whtPts;

        if (gain > maxGain) {
            maxGain = gain;
            *pos_x = sim_pos_x;
            *pos_y = sim_pos_y;
        }
    
    }

    return;
    
}
