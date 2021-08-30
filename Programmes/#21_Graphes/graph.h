#ifndef __GRAPH__H__
#define __GRAPH__H__

	/* Définition d'un Booléen */
	typedef enum
	{
		false, 
		true
	}Bool;


	/* Définition d' une liste de Noeuds (sommet) */
	typedef struct NodeListElement
    {
	    int value;
	    struct NodeListElement *next;
    }NodeListElement, *NodeListe;


	/* Définition d' une liste d'ajdacence (tableau) */
    typedef struct AdjacencyListElement
    {
        NodeListElement *begin;
    }AdjacencyListElement, *AdjacencyList;

	/* Définition d' un Graphe */
    typedef struct GraphElement
    {
        Bool is_oriented;
        int nb_vertices;
        AdjacencyList tab_neighbours;
        FILE *graph_file;
    }GraphElement, *Graph;

	/* Prototypes */
    Graph new_graph(int vertices, Bool is_oriented);
    Bool is_empty_graph(Graph g);
    NodeListe add_node(int x);
    void add_edge(Graph g, int src, int dest);
    void print_graph(Graph g);
    void display_graph(Graph g);
    void erase_graph(Graph g);

#endif