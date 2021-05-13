/*******************************************************************************
 

 *
 * "tree" is represented by pointer to root node
 */

/*
 * the next two directives (and the last line) make the .h file "idempotent" -- 
 * if you inadvertently #include it twice, no harm done,
 * since the second #include finds SORTED_INT_LIST_H defined
 * and ignores the rest of the file.
 * this is (usually?) considered to be good style.
 */
#ifndef INT_BST_H
#define INT_BST_H

#include <stdio.h>
#include <stdlib.h>

#include <stdbool.h>

/* 
 * data structure for tree node
 *
 * type to use in declaring nodes, and pointers to nodes, 
 * is int_bst_node_t
 */
typedef struct int_bst_node {
	int data;
	struct int_bst_node * left;
	struct int_bst_node * right;
} int_bst_node_t;

typedef struct tree{
    int_bst_node_t* pRootNode;
}tree_t;

/*
 * functions
 *
 * notice that functions that might change the head of a list take as a
 * parameter a int_bst_node_t ** (pointer to pointer to node).
 * so that if called with the address of a variable they can change it.
 */

/* 
 * insert n into *t_p
 * does nothing if n is already in the tree
 * returns true if insertion succeeded (including the case where n is already
 * in the tree), false otherwise (e.g., malloc error)
 */
bool int_bst_insert(int_bst_node_t ** t_p, int n);

/* 
 * find n in t
 */
bool int_bst_find(int_bst_node_t * t, int n);

/* 
 * remove n from *t_p
 * OPTIONAL operation -- your code can just print an error message
 * and otherwise do nothing
 */
void int_bst_remove(int_bst_node_t ** t_p, int n);

/*
 * remove all nodes from *t_p and set (*t_p) to NULL
 */
void int_bst_remove_all(int_bst_node_t ** t_p);

/*
 * print all elements of t to output stream f using format fmt
 * ("fmt" is the kind of string expected by fprintf, e.g., "%d " or "%d\n")
 *
 * the FILE * parameter lets the caller decide whether to print
 *   to stdout or a file (already open) or what
 * the fmt parameter lets the caller decide whether to print all on 
 *   one line or each on a separate line or what
 */
void int_bst_print_elements(int_bst_node_t * t, FILE * f, char * fmt);

/*
 * print all elements of t to output stream f in tree form
 * (see sample output for one way to do this -- or you may have
 * a better idea)
 */
void int_bst_print_as_tree(int_bst_node_t * t, FILE * f);

#endif /* end of ifndef INT_BST_H */
