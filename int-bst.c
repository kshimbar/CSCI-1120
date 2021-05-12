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
    if(localNode != NULL)
    {
        localNode->data = n;
        localNode->left = NULL;
        localNode->right = NULL;
    }
    return localNode;
}

/* 
 * insert n into *t_p
 * does nothing if n is already in the tree
 * returns true if insertion succeeded (including the case where n is already
 * in the tree), false otherwise (e.g., malloc error)
 */
bool int_bst_insert(int_bst_node_t ** t_p, int n){
    if(*t_p == NULL){
        createNode(n);
        return true;
    }else if((*t_p)->data > n){
        if((*t_p)-> left != NULL){
            return int_bst_insert(&((*t_p)->left),n);
        } else{
            (*t_p)->left = createNode(n);
            return true;
        }
    }else if((*t_p)->data < n){
        if((*t_p)-> right != NULL){
            return int_bst_insert(&((*t_p)->right),n);
        }else{
            (*t_p)->right = createNode(n);
            return true;
        }
    }else{
        return false;
    }
}

/* 
 * find n in t
 */
bool int_bst_find(int_bst_node_t * t, int n){
    if(t-> data > n){
        if(t -> left == NULL){
            return false;
        }else{
            return int_bst_find(t -> left,n);
        }
    } else if(t-> data < n){
        if(t->right == NULL){
            return false;
        } else{
            return int_bst_find(t->right,n);
        }
    } else if(t-> data == n){
        return true;
    }else return false;
}

/* 
 * remove n from *t_p
 * OPTIONAL operation -- your code can just print an error message
 * and otherwise do nothing
 */
void int_bst_remove(int_bst_node_t ** t_p, int n){
    int_bst_node_t*parent = NULL;
    while(*t_p != NULL && (*t_p) -> data != n){
        if((*t_p) -> data > n){
            parent = (*t_p);
            *t_p = (*t_p)->left;
        }else if((*t_p) -> data < n){
            parent = (*t_p);
            *t_p = (*t_p)->right;
        }
    }
    if((*t_p)-> data == n){
        if((*t_p)-> right==NULL && (*t_p)->left == NULL){
            if(parent->data > n){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
        }else if((*t_p)-> right == NULL){
            if(parent -> data > n){
                parent -> left = (*t_p) -> left;
            }else{
                parent -> right = (*t_p) -> left;
            }
        } else if((*t_p)-> left == NULL){
            if(parent -> data > n){
                parent -> left = (*t_p) -> right;
            }else{
                parent -> right = (*t_p) -> right;
            }
        }else{
            int_bst_node_t*search;
            search = (*t_p)->right;
            while(search ->left == NULL){
                search = search->left;
            }
            if(parent->data > n){
                parent->left = search;
            }else if(parent->data < n){
                parent->right = search;
            }
        }
    }else{
        printf("Not found");
    }
}

/*
 * remove all nodes from *t_p and set (*t_p) to NULL
 */
void int_bst_remove_all(int_bst_node_t ** t_p){
    (*t_p) ->left = NULL;
    (*t_p)->right = NULL;
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
void int_bst_print_elements(int_bst_node_t * t, FILE * f, char * fmt){
        if(t->right != NULL){
            fprintf(f,t->data);
            t = t->right;
            int_bst_print_elements(t,f,fmt);
        }
        if(t->left != NULL){
            fprintf(f,t->data);
            t = t-> left;
            int_bst_print_elements(t,f,fmt);
        }
}

/*
 * print all elements of t to output stream f in tree form
 * (see sample output for one way to do this -- or you may have
 * a better idea)
 */
void int_bst_print_as_tree(int_bst_node_t * t, FILE * f);
