/*******************************************************************************
 *
 * definitions (implementation) of functions declared in .h file
 * (plus helper functions)
 *
 */
#include <stdio.h>
#include <stdlib.h>

/*
 * helper functions (static so not visible outside this file)
 */
static int int_compare(const void * e1, const void * e2) {
	int * i1 = (int *) e1;
	int * i2 = (int *) e2;
	if (*i1 < *i2) return -1;
	else if (*i1 > *i2) return 1;
	else return 0;
} 

/*
 * functions declared in .h file
 */
void print_test_data(int data[], size_t sz) {
	int sorted[sz];
	for (int i = 0; i < sz; ++i) sorted[i] = data[i];
	qsort(sorted, sz, sizeof(data[0]), &int_compare);
	printf("test data in order [");
	for (int i = 0; i < sz; ++i) printf(" %d", sorted[i]);
	printf(" ]\n");
}
