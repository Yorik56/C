
#include "tree.h"

#define afficher printf

/*

*/

int main(void)
{
    Tree *arbre = join_tree(
            join_tree(new_tree(8), new_tree(3), 2),
            new_tree(4),
            6
            );

    print_prefix(arbre);

    afficher("Nombre de noeuds: %d\n", count_tree_nodes(arbre));

    clean_tree(arbre);

    return 0;
}