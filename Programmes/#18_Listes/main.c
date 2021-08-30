#include <stdio.h>
#include "list.h"
#define afficher printf

/*

*/

int main(void)
{
    List mylist = new_list();

    if(is_empty_list(mylist))
        afficher("Liste vide.\n");
    else
        afficher("Liste a des elements.\n");

    afficher("Taille de la liste: %d\n", list_length(mylist));
    print_list(mylist);

    mylist = push_back_list(mylist, 36);
    print_list(mylist);

    mylist = push_front_list(mylist, 87);
    mylist = push_back_list(mylist, -4);
    print_list(mylist);
    afficher("Nombre d' elements: %d\n", list_length(mylist));

    mylist = list_clear(mylist);
    print_list(mylist);




    return 0;
}