#include "int-bst.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* YOUR CODE GOES HERE */
/*
 * functions
 *
 * notice that functions that might change the head of a list take as a
 * parameter a int_bst_node_t ** (pointer to pointer to node).
 * so that if called with the address of a variable they can change it.
 */


int_bst_node_t * createNode(int n) 
{
    int_bst_node_t *localNode = malloc(sizeof(int_bst_node_t));
    if(localNode != NULL){
        localNode->data = n;
        localNode->left = NULL;
        localNode->right = NULL;
    }
    return localNode;
}

static void helper_remove_all(int_bst_node_t * lst);

/*
 * insert n into *t_p
 * does nothing if n is already in the tree
 * returns true if insertion succeeded (including the case where n is already
 * in the tree), false otherwise (e.g., malloc error)
 */

bool int_bst_insert(int_bst_node_t ** n, int data){
    if (*n == NULL) {
        *n = createNode(data);
        return true;
    } else {
        if ((*n)->data > data) {
            return int_bst_insert(&((*n)->left), data);
        } else if((*n)->data < data){
            return int_bst_insert(&((*n)->right), data);
        }else return true;
    }
}

void freeNode(int_bst_node_t*pNode){
    if(pNode != NULL){
        freeNode(pNode->left);
        freeNode(pNode->right);
        free(pNode);
    }
}

void freeNodeInTree(int_bst_node_t*pNode){
    if(pNode != NULL){
        freeNode(pNode -> right);
        freeNode(pNode->left);
        free(pNode);
    }
}

/* 
 * find n in t
 */
bool int_bst_find(int_bst_node_t * t, int n){
    if(t == NULL){
        return false;
    }

    if(n == t->data){
        return true;
    }else if(n < t->data){
        return int_bst_find(t->left,n);
    }else{
        return int_bst_find(t->right,n);
    }
}

/* 
 * remove n from *t_p
 * OPTIONAL operation -- your code can just print an error message
 * and otherwise do nothing
 */
void int_bst_remove(int_bst_node_t ** n, int data){
    int_bst_node_t *temp, *iter_node, *parent_iter_node;

    if (*n == NULL) {
    } else {
        if ((*n)->data > data) {
            int_bst_remove(&((*n)->left), data);
        } else if ((*n)->data < data) {
            int_bst_remove(&((*n)->right), data);
        } else {
            if ((*n)->left == NULL && (*n)->right == NULL) {
                free(*n);
                *n = NULL;
            } else if ((*n)->left != NULL && (*n)->right == NULL) {
                temp = *n;
                *n = (*n)->left;

                free(temp);
                temp = NULL;
            } else if ((*n)->left == NULL && (*n)->right != NULL) {
                temp = *n;
                *n = (*n)->right;

                free(temp);
                temp = NULL;
            } else {
                temp = *n;

                parent_iter_node = *n;
                iter_node = (*n)->right;

                while (iter_node->left != NULL) {
                    parent_iter_node = iter_node;
                    iter_node = iter_node->left;
                }

                iter_node->left = (*n)->left;

                if (*n != parent_iter_node) {
                    iter_node->right = (*n)->right;
                    parent_iter_node->left = NULL;
                } else {
                    iter_node->right = NULL;
                }

                *n = iter_node;

                free(temp);
                temp = NULL;
            }
        }
    }
}

/*
 * remove all nodes from *t_p and set (*t_p) to NULL
 */

void helper_remove_all(int_bst_node_t * lst) {
	if (lst != NULL) {
		helper_remove_all(lst->right);
        helper_remove_all(lst->left);
		free(lst);
	}
}
void int_bst_remove_all(int_bst_node_t ** t_p){
    helper_remove_all(*t_p);
	*t_p = NULL;
}

/*
 * print all elements of t to output stream f using format fmt
 * ("fmt" is the kind of string expected by fprintf, e.g., "%d " or "%d\n")
 *
 * the FILE * parameter lets the caller decide whether to print
 *   to stdout or a file (already open) or what
 * the fmt parameter lets the caller decide whether to print all on 
 *   one line or each on a separate line or what
 */
void int_bst_print_elements(int_bst_node_t * n, FILE * f, char * fmt){
        if (n != NULL) {
        int_bst_print_elements(n->left,f,fmt);
        fprintf(f,"%d ", n->data);
        int_bst_print_elements(n->right,f,fmt);
    }
}

/*
 * print all elements of t to output stream f in tree form
 * (see sample output for one way to do this -- or you may have
 * a better idea)
 */

int space = 0;

void int_bst_print_as_tree(int_bst_node_t * n, FILE * f){
    int i = 0;
    if (n != NULL) {
        int_bst_print_as_tree(n->left, f);
        space = space  +1;
        while (i++ < space) {
            fprintf(f,"\t");
        }
        fprintf(f,"%d\n", n->data);
        int_bst_print_as_tree(n->right,f);
        space = space + 1;
    }
}




