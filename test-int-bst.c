/*
 * test program for sorted list of ints
 * no inputs
 */
#include <stdio.h>
#include <stdlib.h>

#include "int-bst.h"
#include "test-helper.h"

/*******************************************************************************
 *
 * declarations (prototypes) of helper functions 
 * "static" so not visible outside this file
 */

/* convenience functions to print tree */
static void print_tree_elements(int_bst_node_t * t);
static void print_tree_as_tree(int_bst_node_t * t);

/* functions to test BST functions verbosely */
static void test_insert(int_bst_node_t ** t_p, int n);
static void test_remove(int_bst_node_t ** t_p, int n);
static void test_find(int_bst_node_t * t, int n);

/*******************************************************************************
 *
 * main program 
 */

int main(void) {
	int_bst_node_t * tree_p = NULL;
	int insert_data[] = 
		{ 40, 30, 50, 20, 60, 16, 14, 18, 24, 56, 64, 30, 50 };
	int find_data[] = 
		{ 0, 100, 10, 40, 14, 64 };
	int remove_data[] = 
		{ 0, 16, 60, 30, 50 };
	for (int i = 0; i < sizeof(insert_data)/sizeof(insert_data[0]); ++i) {
		test_insert(&tree_p, insert_data[i]);
	}
	print_test_data(insert_data, sizeof(insert_data)/sizeof(insert_data[0]));
	print_tree_as_tree(tree_p);
	for (int i = 0; i < sizeof(find_data)/sizeof(find_data[0]); ++i) {
		test_find(tree_p, find_data[i]);
	}
	for (int i = 0; i < sizeof(remove_data)/sizeof(remove_data[0]); ++i) {
		test_remove(&tree_p, remove_data[i]);
	}
	print_tree_as_tree(tree_p);
	test_insert(&tree_p, 0);
	test_insert(&tree_p, 100);
	test_insert(&tree_p, 0);
	test_insert(&tree_p, 100);
	int_bst_remove_all(&tree_p); 
	printf("after removing all elements ");
	print_tree_elements(tree_p);
	printf("\n");
	return EXIT_SUCCESS;
}

/*******************************************************************************
 *
 * definitions (implementation) of helper functions 
 */

static void print_tree_elements(int_bst_node_t * t) {
	printf("[");
	int_bst_print_elements(t, stdout, " %d");
	printf(" ]");
}

static void print_tree_as_tree(int_bst_node_t * t) {
	int_bst_print_as_tree(t, stdout);
}

static void test_insert(int_bst_node_t ** t_p, int n) {
	printf("inserting %d into tree ", n);
	print_tree_elements(*t_p);
	printf("\n");
	if (int_bst_insert(t_p, n)) {
		printf("result ");
		print_tree_elements(*t_p);
		printf("\n");
	}
	else {
		printf("insert failed\n");
	}
}

static void test_remove(int_bst_node_t ** t_p, int n) {
	printf("removing %d from tree ", n);
	print_tree_elements(*t_p);
	printf("\n");
	int_bst_remove(t_p, n);
	printf("result ");
	print_tree_elements(*t_p);
	printf("\n");
}

static void test_find(int_bst_node_t * t, int n) {
	printf("finding %d in tree ", n);
	print_tree_elements(t);
	printf("\n");
	printf("result %s\n", (int_bst_find(t, n) ? "true" : "false"));
}
