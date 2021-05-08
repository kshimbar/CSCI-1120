#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



int main(int argc, char* argv[]) {
    if (argc != 4) { 
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
    char*endptr;
    int n = strtol(argv[3], &endptr, 10);
    if(*endptr != '\0'){
        fprintf(stderr,"Please enter integer.\n");
        return 0;
    }
    int ch;
    while((ch = fgetc(infile)) != EOF){
        char * lc_alphabet = "abcdefghijklmnopqrstuvwxyz";
        char * uc_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char * in_lc_alphabet = strchr(lc_alphabet, ch);
        char * in_uc_alphabet = strchr(uc_alphabet, ch);
        if (in_lc_alphabet != NULL) {
            int position_in_alphabet = in_lc_alphabet - lc_alphabet;
            int  point = (position_in_alphabet + n)%strlen(lc_alphabet);
            char * encrypt = lc_alphabet;
            encrypt = lc_alphabet + point;
            fputc(*encrypt,outfile);
        }
        if(in_uc_alphabet != NULL){
            int position_in_alphabet = in_uc_alphabet - uc_alphabet;
            int  point = (position_in_alphabet + n)%strlen(uc_alphabet);
            char * encrypt = uc_alphabet;
            encrypt = uc_alphabet + point;
            fputc(*encrypt,outfile);
        }
        if(in_uc_alphabet == NULL && in_lc_alphabet == NULL){
            fputc(ch,outfile);
        }
    
    }

    fclose(infile);
    fclose(outfile);
    return EXIT_SUCCESS;
}
