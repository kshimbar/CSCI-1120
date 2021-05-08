#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rotate(int inchar, int positions_to_rotate) {
	/* or put these declarations outside all functions to make them "global" */
	char * lc_alphabet = "abcdefghijklmnopqrstuvwxyz";
	char * uc_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	/* look for input character in list of lowercase chars */
	char * in_lc_alphabet = strchr(lc_alphabet, inchar);
	if (in_lc_alphabet != NULL) {
		/* lower-case character:  find rotated char in lc_alphabet */
		int position_in_alphabet = in_lc_alphabet - lc_alphabet;
        int  point = position_in_alphabet + positions_to_rotate;
        char * encrypt = lc_alphabet;
        encrypt = lc_alphabet + point;

        printf("rotated character is %c\n", *encrypt);
        return 1;
		/* 
		 * YOUR CODE GOES HERE:
		 * use lc_alphabet and positions_to_rotate to find new character
		 *   and return it
		 * strlen(lc_alphabet) may be helpful
		 */
	}
    return 1;
	/*
	 * YOUR CODE GOES HERE:
	 * do something similar to the above for uppercase characters
	 * if input character not found in either "alphabet" just return it
	 */
}
int main(void) {
    rotate('b',2);
    return 1;
}
