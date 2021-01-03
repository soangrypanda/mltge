#include "win_mod.h"

static void init_curses(void);
void init_win_mod()
{
    init_curses();
}

static void init_curses(void)
{   
    initscr();
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, 1);
    timeout(0);
}
