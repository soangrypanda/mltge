#ifndef CMDSNK_WIN_MOD_H_SENTRY
#define CMDSNK_WIN_MOD_H_SENTRY


#include <curses.h>
#include <string.h>
#include <stdlib.h>

/* --- NEED TO THINK ABOUT POSSIBILITY OF DRAWING WINS SEPARATELLY --- */

#include "err_mod.h"

struct win_s {
    char *win;
    int w, h, x, y;
};

#define init_win_m(wind, wx, wy, ww, wh, scrn)            \
    struct win_s *wind = calloc(1, sizeof(*wind));      \
    check_alloc(wind, errno, "init_win");               \
    wind->x = wx;                                       \
    wind->y = wy;                                       \
    wind->w = ww;                                       \
    wind->h = wh;                                       \
    wind->win = &((scrn)->win[wy*((scrn)->w)+wx])

#define draw_win_brdr(wind, bv, bh)                     \
    for(int h = 0; h < wind->h; ++h) {                  \
        wind->win[h * wind->w] = bv;                    \
        wind->win[h * wind->w + wind->w - 1] = bv;      \
    }                                                   \
    for(int w = 0; w < wind->w; ++w) {                  \
        wind->win[w] = bh;                              \
        wind->win[wind->w * wind->h - wind->w + w] = bh;\
    }                                                   \
    int xew
    //wind->win[wind->w*wind->h] = '\0'
 
#define fill_win_with(what, where)                      \
    memset((where)->win, what, (where)->h * (where)->w);\
    (where)->win[(where)->h*(where)->w] = '\0'

#define init_mainscreen(screen)                         \
    struct win_s *screen = calloc(1, sizeof(*screen));  \
    check_alloc(screen, errno, "init_mainscreen");      \
    screen->x = screen->y = 0;                          \
    getmaxyx(stdscr, screen->h, screen->w);             \
    screen->win= calloc((screen->h)*(screen->w)+1, sizeof(*(screen->win))); \
    check_alloc(screen->win, errno, "init_mainscreen")

void init_win_mod(void);
void update_win(struct win_s *win);
void destroy_win(struct win_s *win); 

#endif
