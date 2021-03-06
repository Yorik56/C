#ifndef __TREE__H__
#define __TREE__H__

/* Fichiers d'en-tête */
#include <stdio.h>
#include <stdlib.h>
#define afficher printf


/* Structure d' un Arbre */
typedef struct Tree
{
    int value;
    struct Tree *tleft;
    struct Tree *tright;
    struct Tree *tparent;
}Tree;

/* Prototypes des fonctions */
Tree *new_tree(int x);
void clean_tree(Tree *tr);
Tree *join_tree(Tree *left,Tree *right, int node);
void print_prefix(Tree *tr);
int count_tree_nodes(Tree *tree);

#endif