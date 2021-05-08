/*
 * C program for Conway's ``game of life''.
 *
 * Command-line arguments specify input file and number of steps.
 *
 * Input file contains a representation of an initial board configuration:
 * N (size of board) and N*N values (each 0 or 1).
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#include "game-of-life-util.h"

/* 
 * reads initial board configuration from file.
 * builds 2D array in form of an array of pointers into one big 1D array.
 * parameters:
 *   infile is an already-opened file.
 *   (out) *size_p is board size 
 * return value is array of pointers, or NULL if there was a problem
 *   (in which case the function prints a suitable error message).
 */
// bool **read_board(FILE* infile, long *size_p);

/* 
 * main program
 */
int main(int argc, char* argv[]) {

	/* process command-line arguments */
	if (argc < 5) {
		printf("Need more prameters.\n");
		return EXIT_FAILURE;
	}
	if (argc > 6) {
		printf("too many prameters.\n");
		return EXIT_FAILURE;
	}

	char* end_ptr_for_strtol;
	long steps = strtol(argv[4], &end_ptr_for_strtol, 10);
	char* ptr_for_size;
	long size = strtol(argv[1], &ptr_for_size, 10);
	char* ptr_for_seed; 
	long seed = strtol(argv[2], &ptr_for_seed, 10);
	double fraction = atof(argv[3]);
	char* printcheck = "print";
	char* print = argv[5];

	if ((*end_ptr_for_strtol != '\0') || (steps < 0)) {
		fprintf(stderr, "invalid num_steps\n");
		return EXIT_FAILURE;
	}
	if(fraction > 1.0){
		printf("The fraction has to be smaller than 1.");
		return EXIT_FAILURE;
	}
	srand(seed);
	long howcell = 0;
	/* create board from input file */
	bool **board = build2D(size);
	for(int row = 0; row < size; row = row + 1){
		for(int col = 0; col < size; col = col + 1){
			double ran =rand();
			double quotient = ran / RAND_MAX;
			if(quotient < fraction){
				board[row][col] = true;
				howcell = howcell + 1;
			} else board[row][col] = false;
		}
	}
	if(board == NULL){
		free2D(size, board);
		return EXIT_FAILURE;
	}
	

	/* create second board to use for updates */
	bool **new_board = build2D(size);
	if (new_board == NULL) {
		free2D(size, board);
		return EXIT_FAILURE;
	}

	/* print initial configuration */
	bool pornot = (argc == 6 && strcmp(print, printcheck) == 0);
	if(pornot){
		printf("Initial board:\n");
		print_board(size, board);
		putchar('\n');
	}
	double howcelldouble = howcell;
	double fr = howcelldouble / (size * size);
	printf("%ld live cells at start. (Fraction: %lf)\n", howcell, fr);
	

	/* loop to update board and print */
	for (long step = 1; step <= steps; ++step) {
		/* update (results in new_board) */
		update_board(size, board, new_board);
		int cells = 0;
		for(int row = 0; row < size; row = row + 1){
			for(int col = 0; col < size; col = col + 1){
				if(new_board[row][col]){
					cells = cells + 1;
				}
			}
		}
		double cellsdouble = cells;
		double frac = cellsdouble / (size * size);
		printf("%d live cells after step %ld. (Fraction: %lf)\n", cells, step,frac);
		if(pornot){
			printf("Board after step %ld:\n", step);
			print_board(size, new_board);
			putchar('\n');
		}
		
		/* swap old and new boards by exchanging pointers(!) */
		bool **temp = board;
		board = new_board;
		new_board = temp;
	}

	/* tidy up and return */
	free2D(size, board);
	free2D(size, new_board);
	return EXIT_SUCCESS;
}

/*
 * functions (described above)
 */

bool **read_board(FILE* infile, long *size_p) {

	/* read size from input file */
	long size;
	if ((fscanf(infile, "%ld", &size) != 1) || (size <= 0)) {
		fprintf(stderr, "invalid size in input file\n");
		return NULL;
	}
	*size_p = size;

	/* build 2D array */
	bool **board = build2D(size);
	if (board == NULL) {
		return NULL;
	}

	/* fill with data from file */
	int inchar;
	for (long i = 0; i < size; ++i) {
		for (long j = 0; j < size; ++j) {
			/* get next nonspace character from input file */
			while (isspace(inchar = fgetc(infile))) { }
			if (inchar == '1') {
				board[i][j] = true;
			}
			else if (inchar == '.') {
				board[i][j] = false;
			}
			else {
				fprintf(stderr, 
					"unable to read values for board\n");
				free2D(size, board);
				return NULL;
			}
		}
	}
	/* check for anything else in input file */
	while (isspace(inchar = fgetc(infile))) { }
	if (!feof(infile)) {
		fprintf(stderr, "unable to read values for board\n");
		free2D(size, board);
		return NULL;
	}

	return board;
}
