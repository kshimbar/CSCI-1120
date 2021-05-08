/*
 * Version of whilesum.c that reads from file and writes partial sums
 * to output file.
 *
 * Command-line arguments:
 * input file
 * output file
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_COUNT 100

/* function declarations -- see definitions (at end) for more comments */
void sort(int a[], int size);
int find_out_of_order(int a[], int size);


int main(int argc, char* argv[]) {
	int arr[MAX_COUNT];
	if (argc != 3) { 
		fprintf(stderr, "usage:  %s infile outfile\n", argv[0]);
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

	int n;
	/* slightly cryptic but C-idiomatic .... */
	int count = 1;
	while (fscanf(infile, "%d", &n) == 1) {
		arr[count] = n;
		printf("%d\n", arr[count]);
		count++;
        /* uncomment to see feof() return value 
        printf("eof on infile?  %c\n", feof(infile) ? 'y' : 'n');
        */
	}


	/* check whether loop stopped because of EOF or error */
	if (!feof(infile)) {
		fprintf(stderr, "bad input\n");
		fclose(infile);
		fclose(outfile);
		return EXIT_FAILURE;
	}

	sort(arr, count + 1);
	
	for (int i = 0; i < count; ++i) {
		printf("%d\n", arr[i]);
		fprintf(outfile, "%d\n", arr[i]);
	}

	fclose(infile);
	fclose(outfile);
	int out_of_order = find_out_of_order(arr, count + 1);
		if (out_of_order < 0) {
			printf("sorted\n");
		}
		else {
			printf("not sorted\n");
			printf("first out-of-order element at index %d\n", out_of_order);
		}
	return EXIT_SUCCESS;
}

/* 
 * check whether array is sorted:
 * returns index of first out-of-order element, or -1 if all are in order
 */

int find_out_of_order(int a[], int size) {	
	for (int i = 0; i < size-1; ++i) {
		if (a[i] > a[i+1]) { 
			return i;
		}
	}
	return -1;
}

/* sort array */
void sort(int a[], int size) {
	// for(int i = 0; i < size; ++i){
    //     for(int j = i + 1; j < size; ++j){
    //         if(a[i] > a[j]){
    //             int tmp = a[i];
    //             a[i] = a[j];
    //             a[j] = tmp;
    //         }
    //     }
    // }
   int i, j, tmp, swapped;
   for (i = 0; i < size - 1; i++){
	   swapped = 0;
       for (j = 0; j < size - 1; j++){ 
           if (a[j] > a[j+1]){
				tmp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = tmp;
				swapped = 1;
			}
		}
		if (swapped == 0) {
		   break;
		}
	}

}

