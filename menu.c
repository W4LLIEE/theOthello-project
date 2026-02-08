#include "menu.h"
#include <stdio.h>
#include <string.h>

struct termios oldt, newt;

void enableRawMode() {
    tcgetattr(STDIN_FILENO, &oldt);   // save current terminal state
    newt = oldt;

    newt.c_lflag &= ~(ICANON | ECHO); // disable line buffering + echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
}

void disableRawMode() {
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
}

void clrScr() {
    printf("\033[2J\033[H");
}

void menuPrt1() {
    
    clrScr();
    
    printf("\n  ──────────────────────────────\n");
    printf("          O T H E L L O\n");
    printf("  ──────────────────────────────\n\n");
    printf("          [ Play Game ]\n");
    printf("            Play vs AI - In Development\n");
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
    printf("          [ Play vs AI ] - In Development\n");
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
    printf("            Play vs AI - In Development\n");
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
    printf("            Play vs AI - In Development\n");
    printf("            Rules\n");
    printf("           [ Exit ]\n\n");
    printf("  ──────────────────────────────\n");
    printf("        Black ●   White ○\n");
    printf("  ──────────────────────────────\n\n");
    
    //printf("\n\n  Select an Option (1-4) : ");

    return;

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