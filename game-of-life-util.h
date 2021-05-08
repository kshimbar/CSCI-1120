/*
 * Common code for two versions of game-of-life program:
 *
 * Function declarations
 */
#ifndef GOL_H_
#define GOL_H_

#include <stdbool.h>

/* 
 * builds 2D array in form of an array of pointers into one big 1D array.
 * return value is array of pointers, or NULL if there was a problem
 *   (in which case the function prints a suitable error message).
 */
bool **build2D(long size);

/*
 * frees 2D array, built as in build2D().
 */
void free2D(long size, bool **array2D);

/*
 * generates new board configuration from old.
 */
void update_board(long size, bool **old_board, bool **new_board);

/*
 * prints board.
 */
void print_board(long size, bool **board);

#endif // GOL_H_