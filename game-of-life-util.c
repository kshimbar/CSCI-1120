/*
 * Common code for two versions of game-of-life program:
 *
 * Function definitions
 * 
 * See game-of-life-util.h for comments explaining what these 
 * functions are supposed to do.
 */
#include <stdio.h>
#include <stdlib.h>

#include "game-of-life-util.h"

bool **build2D(long size) {
	bool *data = malloc(size * size * sizeof(data[0]));
	if (data == NULL) {
		fprintf(stderr, 
			"unable to allocate space for board of size %ld\n",
			size);
		return NULL;
	}
	bool **array2D = malloc(size * sizeof(array2D[0]));
	if (array2D == NULL) {
		fprintf(stderr, 
			"unable to allocate space for board of size %ld\n",
			size);
		return NULL;
	}
	for (long r = 0; r < size; ++r) {
		array2D[r] = &data[r*size];
	}
	return array2D;
}

void free2D(long size, bool **array2D) {
	bool *data = array2D[0];
	free(data);
	free(array2D);
}

void update_board(long size, bool **old_board, bool **new_board) {
	/* FIXME your code goes here */
    for(int row = 0; row < size; row = row + 1){
        for(int col = 0; col < size; col = col + 1){
            if(row == 0 && col == 0){
                int p00 = 0;
                if(old_board[row][col + 1]) p00 = p00 + 1;
                if(old_board[row + 1][col]) p00 = p00 + 1;
                if(old_board[row + 1][col + 1]) p00 = p00 + 1;
                if(p00 < 2){
                    new_board[row][col] = false;
                }else if(p00 == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(p00 == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else if(row == 0 && col == size - 1){
                int p0s = 0;
                if(old_board[row][col - 1]) p0s = p0s + 1;
                if(old_board[row + 1][col]) p0s = p0s + 1;
                if(old_board[row + 1][col - 1]) p0s = p0s + 1;
                if(p0s < 2){
                    new_board[row][col] = false;
                }else if(p0s == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(p0s == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else if(row == size - 1 && col == 0){
                int ps0 = 0;
                if(old_board[row][col + 1]) ps0 = ps0 + 1;
                if(old_board[row - 1][col]) ps0 = ps0 + 1;
                if(old_board[row - 1][col + 1]) ps0 = ps0 + 1;
                if(ps0 < 2){
                    new_board[row][col] = false;
                }else if(ps0 == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(ps0 == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else if(row == size - 1 && col == size - 1){
                int pss = 0;
                if(old_board[row][col - 1]) pss = pss + 1;
                if(old_board[row - 1][col - 1]) pss = pss + 1;
                if(old_board[row - 1][col]) pss = pss + 1;
                if(pss < 2){
                    new_board[row][col] = false;
                }else if(pss == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(pss == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else if(row == 0){
                int p0x = 0;
                if(old_board[row][col - 1]) p0x = p0x + 1;
                if(old_board[row][col + 1]) p0x = p0x + 1;
                if(old_board[row + 1][col]) p0x = p0x + 1;
                if(old_board[row + 1][col - 1]) p0x = p0x + 1;
                if(old_board[row + 1][col + 1]) p0x = p0x + 1;
                if(p0x < 2){
                    new_board[row][col] = false;
                }else if(p0x == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(p0x == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else if(row == size - 1){
                int psx = 0;
                if(old_board[row][col - 1]) psx = psx + 1;
                if(old_board[row][col + 1]) psx = psx + 1;
                if(old_board[row - 1][col]) psx = psx + 1;
                if(old_board[row - 1][col - 1]) psx = psx + 1;
                if(old_board[row - 1][col + 1]) psx = psx + 1;
                if(psx < 2){
                    new_board[row][col] = false;
                }else if(psx == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(psx == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else if(col == 0){
                int px0 = 0;
                if(old_board[row][col + 1]) px0 = px0 + 1;
                if(old_board[row + 1][col]) px0 = px0 + 1;
                if(old_board[row - 1][col]) px0 = px0 + 1;
                if(old_board[row + 1][col + 1]) px0 = px0 + 1;
                if(old_board[row - 1][col + 1]) px0 = px0 + 1;
                if(px0 < 2){
                    new_board[row][col] = false;
                }else if(px0 == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(px0 == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else if(col == size - 1){
                int pxs = 0;
                if(old_board[row][col - 1]) pxs = pxs + 1;
                if(old_board[row + 1][col]) pxs = pxs + 1;
                if(old_board[row - 1][col]) pxs = pxs + 1;
                if(old_board[row + 1][col - 1]) pxs = pxs + 1;
                if(old_board[row - 1][col - 1]) pxs = pxs + 1;
                if(pxs < 2){
                    new_board[row][col] = false;
                }else if(pxs == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(pxs == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            } else{
                int px = 0;
                if(old_board[row][col - 1]) px = px + 1;
                if(old_board[row][col + 1]) px = px + 1;
                if(old_board[row - 1][col]) px = px + 1;
                if(old_board[row + 1][col]) px = px + 1;
                if(old_board[row - 1][col - 1]) px = px + 1;
                if(old_board[row - 1][col + 1]) px = px + 1;
                if(old_board[row + 1][col - 1]) px = px + 1;
                if(old_board[row + 1][col + 1]) px = px + 1;
                if(px < 2){
                    new_board[row][col] = false;
                }else if(px == 2 && old_board[row][col]){
                    new_board[row][col] = true;
                }else if(px == 3){
                    new_board[row][col] = true;
                } else new_board[row][col] = false;
            }
        }
    }
}

void print_board(long size, bool **board) {
	for (long i = 0; i < size; ++i) {
		for (long j = 0; j < size; ++j) {
			if (board[i][j]) 
				printf("1 ");
			else
				printf(". ");
		}
		putchar('\n');
	}
}