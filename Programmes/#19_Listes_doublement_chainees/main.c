#include <stdio.h>
#include "dlist.h"

#define afficher printf


int main(void)
{
    DList mylist = new_dlist();
    print_dlist(mylist);
    afficher("Taille de la liste: %d\n", dlist_length(mylist));
    afficher("\n---------------------\n");

    mylist = push_front_dlist(mylist,14);
    print_dlist(mylist);
    afficher("Taille de la liste: %d\n", dlist_length(mylist));
    afficher("\n---------------------\n");

    mylist = push_front_dlist(mylist,6);
    mylist = push_back_dlist(mylist,23);
    print_dlist(mylist);
    afficher("Taille de la liste: %d\n", dlist_length(mylist));
    afficher("\n---------------------\n");
    mylist = clear_dlist(mylist);
    print_dlist(mylist);
    afficher("Taille de la liste: %d\n", dlist_length(mylist));

    return 0;
}