#include <stdio.h>
#include "stack.h"
#include <string.h>
#define afficher printf

/*

*/

int main(void)
{
    Player p1 = {"Luffy", 51};
    Player p2 = {"Zorro", 49};
    Player p3 = {"Sanji", 47};
    Player p4 = {"Nami", 35};

    Stack sta = new_stack();

    print_stack(sta);

    afficher("\n--------------------------\n\n");

    sta = push_stack(sta,p1);
    sta = push_stack(sta,p2);
    sta = push_stack(sta,p3);
    sta = push_stack(sta,p4);

    print_stack(sta);
    Player dernier_joueur = top_stack(sta);
    afficher("Dernier joueur : %s (%d)\n", dernier_joueur.name, dernier_joueur.niveau);
    afficher("Nombre de joueurs : %d\n", stack_length(sta));

    afficher("\n--------------------------\n\n");

    sta = pop_stack(sta);
    print_stack(sta);
    dernier_joueur = top_stack(sta);
    afficher("Dernier joueur : %s (%d)\n", dernier_joueur.name, dernier_joueur.niveau);
    afficher("Nombre de joueurs : %d\n", stack_length(sta));

    afficher("\n--------------------------\n\n");

    sta = clear_stack(sta);
    print_stack(sta);

    return 0;
}