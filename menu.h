// menu.h


#ifndef MENU_H
#define MENU_H

#include <termios.h>
#include <unistd.h>

typedef enum menu {PLAY=1, AI, RULES, EXIT,}menu;

void enableRawMode();
void disableRawMode();
void clrScr();
void menuPrt1();
void menuPrt2();
void menuPrt3();
void menuPrt4();
int menuRun(int optNum);

#endif