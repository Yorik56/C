#include <stdio.h>
#include "queue.h"

#define afficher printf

/*

*/

int main(void)
{
    /*if(is_empty_queue())
        afficher("File vide.\n");
    else
        afficher("File non vide.\n");*/

    afficher("Taille de la file: %d\n", queue_length());
    print_queue();

    push_queue(14);
    push_queue(-26);
    push_queue(173);
    afficher("Taille de la file: %d\n", queue_length());
    print_queue();

    pop_queue();
    afficher("Taille de la file: %d\n", queue_length());
    print_queue();

    clear_queue();
    print_queue();

    return 0;
}