#ifndef CMD_SNK_CELL_MOD_H_CENTRY
#define CMD_SNK_CELL_MOD_H_CENTRY


#include <string.h>
#include "win_mod.h"
#include "err_mod.h"


void draw_cell(struct win_s *win, int x, int y, char cell);
int in_scope(int x, int y, struct win_s *win);

int find_better_cell(int *px, int *py, int x, int y, struct win_s *scrn, int cell_needed);
int already_seen(int x, int y, int *xa, int *ya, int len);
void cell_mod_cleanup(void);


#endif
