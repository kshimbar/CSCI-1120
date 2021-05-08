#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    if (argc != 3) { 
		fprintf(stderr, "usage:  %s need more arguments\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE * infile = fopen(argv[1], "r");
	if (infile == NULL) { 
		fprintf(stderr, "cannot open file %s\n", argv[1]);
		return EXIT_FAILURE; 
	}
	FILE * outfile = fopen(argv[2], "w");
	if (outfile == NULL) { 
		fprintf(stderr, "cannot open file %s\n", argv[2]);
		return EXIT_FAILURE; 
	}
    int length = 10;
    int seq[length];
    int i = 0;
    int n;
    while (fscanf(infile, "%d", &n) == 1) {
        if(i > length){
            fprintf(stderr,"Out of bounds\n");
        }
        seq[i] = n;
        i = i + 1;
	}
    if (!feof(infile)) {
		fprintf(stderr, "bad input\n");
		fclose(infile);
		fclose(outfile);
		return EXIT_FAILURE;
	}
    for(int i = 0; i < length; ++i){
        for(int j = i + 1; j < length; ++j){
            if(seq[i] > seq[j]){
                int tmp = seq[i];
                seq[i] = seq[j];
                seq[j] = tmp;
            }
        }
    }
    for(int b = 0; b < length; ++b){
        fprintf(outfile,"%d is %d\n", b, seq[b]);
    }
    for(int b = 0; b < length; ++b){
        printf("%d is %d\n", b, seq[b]);
    }
    fclose(infile);
	fclose(outfile);
	return EXIT_SUCCESS;
}
