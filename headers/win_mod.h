#ifndef CMDTTRS_TEST_WIN_H_SENTRY
#define CMDTTRS_TEST_WIN_H_SENTRY


#include <curses.h>
#include <inttypes.h>
#include <string.h>
#include <pthread.h>
#include <err_mod.h>
#include <math.h>

enum win_pix    { bdw_f = '@', bdw_uf = 'x', bgw_bl = ',' };
enum scr_pix    { scrbg_bl = '.' };
enum keys       { LEFT = 'h', UP = 'k', DOWN = 'j', RIGHT = 'l', TOGL_F = 'q', TOGL_B = 'Q' };     

struct win_s {
    char            **map;
    char            *win_buf;
    struct win_s    *scr;
    int32_t         x, y, w, h, no;
};

#define WIN_ARR_MAX 20 
/* --- SHOULD THINK ABOUT AN OPTIMAL NUMBER OF INIT MAX NUMBER OF WINS --- */
struct win_arr_s {
    struct win_s    **arr;
    u_int32_t       max, len, i;
};

extern struct win_arr_s *win_arr;
extern pthread_mutex_t win_arr_mut;

extern pthread_mutex_t main_scr_mut; 

//TEMP VARS!!!
//extern struct win_s *msp;

void init_win_mod(void);

struct win_s * init_mainscreen(void);
void init_win(struct win_s *win, int x, int y, int w, int h, struct win_s *scrn);
void map_winbuf_to_scr(struct win_s *win, struct win_s *scrn);
void add_win_to_arr(struct win_s *win);
void put_scr_to_winbuf(struct win_s *win);
void put_winbuf_to_scr(struct win_s *win);

void fill_win(struct win_s * win, char what);
void make_win_brdr(struct win_s *win, char hb, char vb);

void handle_mv_win(struct win_s *win, char key);
int  mv_win(struct win_s *win, int dx, int dy );
int  can_mv_win(struct win_s *win, int dx, int dy);
void toggle_win_foc(char key);

void render_all_wins(void);
void render_win(struct win_s *win);
void render_screen(struct win_s *win);

void test_test(void);


#endif
