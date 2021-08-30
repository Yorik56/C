#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define afficher printf

/*

*/

int main(void)
{
    Graph g1 = new_graph(5, true); //Non orienté

    add_edge(g1, 0, 1);
    add_edge(g1, 0, 4);
    add_edge(g1, 1, 3);
    add_edge(g1, 1, 2);
    add_edge(g1, 2, 3);
    add_edge(g1, 3, 4);

    print_graph(g1);
    display_graph(g1);
    erase_graph(g1);


    return 0;
}