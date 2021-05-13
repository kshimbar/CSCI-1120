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

/*
 * insert n into *t_p
 * does nothing if n is already in the tree
 * returns true if insertion succeeded (including the case where n is already
 * in the tree), false otherwise (e.g., malloc error)
 */
bool int_bst_insert(int_bst_node_t ** t_p, int n){
    int_bst_node_t*parent = NULL;
    if(*t_p == NULL && parent == NULL){
        *t_p = createNode(n);
        parent = *t_p;
        return true;
    }else if(*t_p == NULL){
        if(parent->right == *t_p){
            parent->right = createNode(n);   
        }else{
            parent->left = createNode(n);
        }
        return true;
    }else if((*t_p)->data > n){
        parent = *t_p;
        return int_bst_insert(&((*t_p)->left),n);
    }else if((*t_p)->data < n){
        parent = *t_p;
       return int_bst_insert(&((*t_p)->right),n);
    }else{
        return false;
    }
}

void freeNode(int_bst_node_t*pNode){
    if(pNode != NULL){
        freeNode(pNode->left);
        freeNode(pNode->right);
        free(pNode);
    }
}

void freeNodeInTree(tree_t*pTree){
    if(pTree != NULL){
        freeNode(pTree ->pRootNode);
        pTree->pRootNode =NULL;
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
void int_bst_remove(int_bst_node_t ** t_p, int n){
    int_bst_node_t*parent=NULL;
    int_bst_node_t*node = *t_p;
    while(node != NULL){
        if(n < node->data){
            parent = node;
            node = node->left;
        }else if(n > node->data){
            parent = node;
            node= node->right;
        }else break;
    }
    if(node->right == NULL && node->left == NULL){
        if(parent != NULL){
            if(parent->left == node){
                parent ->left = NULL;
            }else{
                parent->right = NULL;
            }
            free(node);
        }else{
            free(node);
            *t_p = NULL;
        }
    }else if(node->left == NULL || node->right == NULL){
        int_bst_node_t*child;
        if(node->right == NULL){
            child = node->left;
            node->data = child ->data;
            node->left = child->left;
            node->right = child->right;
            free(child);
        }else{
            child = node->right;
            node->data = child->data;
            node->right = child->right;
            node->left = child->left;
            free(child);
        }
    }else{
        int_bst_node_t*max;
        int_bst_node_t*maxparent;
        max = node->left;
        maxparent = node;
        while(max->right != NULL){
            maxparent = max;
            max = max->right;
        }
        node->data = max->data;
        if(max->left == NULL){
            maxparent -> right = NULL;
            free(max);
        }else{
            int_bst_node_t*child2;
            child2 = max->left;
            max->data = child2->data;
            max->right = child2->right;
            max->left = child2->left;
            free(child2);
        }
    }
}

/*
 * remove all nodes from *t_p and set (*t_p) to NULL
 */
void int_bst_remove_all(int_bst_node_t ** t_p){
    if((*t_p) == NULL){
        return;
    }
    int_bst_remove_all(&((*t_p)->left));
    int_bst_remove_all(&((*t_p)->right));
    free(*t_p);
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
        fprintf(f,"%d",t->data);
        if(t->right != NULL){
            t = t->right;
            int_bst_print_elements(t,f,fmt);
        }
        if(t->left != NULL){
            t = t-> left;
            int_bst_print_elements(t,f,fmt);
        }
}

/*
 * print all elements of t to output stream f in tree form
 * (see sample output for one way to do this -- or you may have
 * a better idea)
 */
int noneelemC = 0;
int newnoneelem = 0;
int depth = 0;
int elem = 0;
void int_bst_print_as_tree(int_bst_node_t * t, FILE * f){
    int ideal;
    if(depth == 0){
        ideal = 1;
    }else{
        ideal = 1;
        for(int a = 0; a < depth; a = a + 1){
            ideal = ideal * 2;
        }
    }
    if(t == NULL && elem+noneelemC + newnoneelem == ideal - 1){
        fprintf(f,"\n");
        newnoneelem = newnoneelem + 1;
    }else if(t == NULL){
        newnoneelem = newnoneelem + 1;
    }else if(elem+noneelemC + newnoneelem == ideal - 1){
        fprintf(f,"%d\n",t->data);
        elem = elem + 1;
    }else if(t != NULL){
        fprintf(f,"%d ", t->data);
        elem = elem  + 1;
    }
    if(ideal == noneelemC + newnoneelem){
        return ;
    }
    if(elem+noneelemC + newnoneelem == ideal){
        depth = depth + 1;
        noneelemC = (noneelemC + newnoneelem)*2;
        newnoneelem = 0;
    }
    int_bst_print_as_tree(t->left,f);
    int_bst_print_as_tree(t->right,f);
}




