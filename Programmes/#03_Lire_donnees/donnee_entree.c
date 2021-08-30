#include <stdio.h>

int main(void)
{
    /*
        maVariable  : contenu de la variable (ex: maVariable = 15)
        &maVariable : adresse où est stockée la variable
    */
    int ageUtilisateur = 0;
    signed char lettre = 'A';

//    printf("Quel âge avez vous ? ");
    // Saisie Utilisateur scanf n'est pas sécurisé, possible injections de code
//    scanf("%d", &ageUtilisateur);
//    printf("Vous avez %d ans.\n", ageUtilisateur);
    printf("Entrez une lettre : ");
    // Saisie Utilisateur scanf n'est pas sécurisé, possible injections de code
    scanf("%c", &lettre);
    printf("Vous avez tapé %c \n", lettre);

    return 0;
}