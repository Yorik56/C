#include <stdio.h>
#include <stdlib.h>
#include "graph.h"
#define afficher printf

/**
* Créée un Graphe
* @param vertices Le nombre de sommets
* @param is_oriented Est-ce un graphe orienté ou non-orienté ?
* @return Le graphe créé
*/
Graph new_graph(int vertices, Bool is_oriented)
{
    int compteur;
    GraphElement *element;

    element = malloc(sizeof(*element));

    if(element == NULL)
    {
        fprintf(stderr, "Erreur : Probleme creation graphique.\n");
        exit(EXIT_FAILURE);
    }

    element->is_oriented = is_oriented;
    element->nb_vertices = vertices;
    element->tab_neighbours = malloc(vertices * sizeof(AdjacencyListElement));

    if(element->tab_neighbours == NULL)
    {
        fprintf(stderr, "Erreur : Probleme creation graphique.\n");
        exit(EXIT_FAILURE);
    }

    for(compteur = 0; compteur < element->nb_vertices; compteur++)
        element->tab_neighbours[compteur].begin = NULL;

    if(element->is_oriented)
        element->graph_file = fopen("digraph.out","w");
    else
        element->graph_file = fopen("graph.out","w");

    if(element->graph_file == NULL)
    {
        fprintf(stderr, "Erreur : Probleme creation du fichier.\n");
        exit(EXIT_FAILURE);
    }

    if(element->is_oriented)
        fprintf(element->graph_file, "digraph my_graph\n{\n");
    else
        fprintf(element->graph_file, "graph my_graph\n{\n");

    return element;
}

/*----------------------------------------------------------------------------------------------*/

/**
* Teste si un Graphe existe
* @param g Le Graphe à vérifier
* @return true Si le Graphe n'existe pas, false sinon
*/
Bool is_empty_graph(Graph g)
{
    if(g == NULL)
        return true;

    return false;
}

/*----------------------------------------------------------------------------------------------*/

/**
* Retourne un Noeud
* @param x La valeur du Noeud
* @param Le Noeud créé
*/
NodeListe add_node(int x)
{
    NodeListe n = malloc(sizeof(NodeListElement));

    if(n == NULL)
    {
        fprintf(stderr, "Erreur : Probleme creation de Node.\n");
        exit(EXIT_FAILURE);
    }

    n->value = x;
    n->next  = NULL;

    return n;
}

/*----------------------------------------------------------------------------------------------*/

/**
* Ajoute une arête à un Graphe
* @param g Le Graphe
* @param src Le premier sommet (ou source)
* @param dest Le second sommet (ou destination)
*/
void add_edge(Graph g, int src, int dest)
{
    NodeListe n = add_node(dest);
    n->next = g->tab_neighbours[src].begin;
    g->tab_neighbours[src].begin = n;

    if(!g->is_oriented)
    {
        n = add_node(src);
        n->next = g->tab_neighbours[dest].begin;
        g->tab_neighbours[dest].begin = n;
    }

    //Ajout d' un lien dans le fichier Graphviz
    if(g->is_oriented)
        fprintf(g->graph_file, "\t%d -> %d;\n", src, dest);
    else
        fprintf(g->graph_file, "\t%d -- %d;\n", src, dest);

}

/*----------------------------------------------------------------------------------------------*/

/**
* Affiche un Graphe en mode console
* @param g Le Graphe
*/
void print_graph(Graph g)
{
    int compteur;

    for(compteur = 0; compteur < g->nb_vertices; compteur++)
    {
        NodeListe n = g->tab_neighbours[compteur].begin;
        afficher("(%d) : ", compteur);

        while(n != NULL)
        {
            afficher("%d, ", n->value);
            n = n->next;
        }

        afficher("NULL\n");
    }


}

/*----------------------------------------------------------------------------------------------*/

/**
* Affiche un Graphe en 2D (avec Graphviz sous WINDOWS)
* @param g Le Graphe
*/
void display_graph(Graph g)
{
    if(g->is_oriented)
        system("dot -Tsvg digraph.out -o output.svg");
    else
        system("dot -Tsvg  graph.out -o output.svg");

}

/*----------------------------------------------------------------------------------------------*/

/**
* Supprime un Graphe
* @param g Le Graphe
*/
void erase_graph(Graph g)
{
    if(is_empty_graph(g))
    {
        afficher("Rien a effacer, le Graphe n\' existe pas");
        return;
    }

    //Si sommets adjacents
    if(g->tab_neighbours)
    {
        int compteur;

        for (compteur = 0; compteur < g->nb_vertices; compteur++ )
        {
            NodeListe n = g->tab_neighbours[compteur].begin;

            while(n != NULL)
            {
                NodeListe tmp = n;
                n = n->next;
                free(tmp);
            }
        }

        //Libération de la liste des adjacences
        free(g->tab_neighbours);
    }
    //Fin et fermeture du fichier Graphviz
    fprintf(g->graph_file, "}\n");
    fclose(g->graph_file);

    //Libération du Graph
    free(g);
}