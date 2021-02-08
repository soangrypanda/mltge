#ifndef ERR_MOD_H_SENTRY
#define ERR_MOD_H_SENTRY

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#define handle_error_en(en, msg)        \
        do { errno = en; perror(msg); exit(EXIT_FAILURE); } while (0)
#define handle_error(msg)               \
        do { perror(msg); exit(EXIT_FAILURE); } while (0)

void exit_error(int errn, char *err_mes);
void check_alloc(void *ret, int errn, char *err_mes);


#endif
