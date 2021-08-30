#include <stdio.h>

int main(void)
{
    /*
        + (addition)
        - (soustraction)
        * (multiplication)
        / (division)
        % (modulo)
    */

    int niveau_joueur = -1;
    printf("Choisir le niveau de départ : ");
    scanf("%d",&niveau_joueur);
    printf("Niveau de départ : %d\n", niveau_joueur);

    // Le personnage fait des quêtes ...
    niveau_joueur++   ;
    printf("Niveau actuel: %d\n", niveau_joueur);
    return 0;
}