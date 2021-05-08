#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

int string_compare(const void * e1, const void * e2) {
    const char ** pa, ** pb;
    pa =(const char **) e1;
    pb =(const char **)e2;
    return(strcmp(* pa,* pb));
}

int main(int argc, char* argv[]){
    if (argc != 2) { 
		fprintf(stderr, "usage:  %s need more arguments\n", argv[0]);
		return EXIT_FAILURE;
	}
	FILE * infile = fopen(argv[1], "r");
	if (infile == NULL) { 
		fprintf(stderr, "cannot open file %s\n", argv[1]);
		return EXIT_FAILURE; 
	}
    char * data;
    int nline = 1;
    int c;
    size_t filesize;
    struct stat stat_data;
    if(stat(argv[1], &stat_data) != 0){
        printf("Failure");
        return 0;
    }
    filesize = stat_data.st_size;    
    data = (char*)malloc(sizeof(char) * filesize);
    if(data == NULL){
        printf("cannot get space\n");
		return EXIT_FAILURE;
    }
    int i = 0;
    while((c = fgetc(infile)) != EOF){
        if(c == '\n'){
            nline++;
        }
        data[i] = c;
        i = i + 1;
    }
    i = 0;
    fclose(infile);
    char**lines = malloc(sizeof(lines[0]) * nline);
    lines[0] = &data[0];
    int n = 0;
    for(int i = 1; i < nline; i = i + 1){
        while(data[n] != '\n'){
            n = n + 1;
        }
        data[n] = '\0';
        n = n + 1;
        lines[i] = &data[n];
    }
    qsort((void*)lines,nline, sizeof(lines), &string_compare);
    for(int i = 0; i < nline; i = i + 1){
        printf("%s\n", lines[i]);
    }
    free(data);
    free(lines);
    return 0;
}

