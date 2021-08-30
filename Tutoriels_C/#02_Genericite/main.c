#include <stdio.h>
#define afficher printf

/*
    Généricité : Manipuler des données de tout type possible

    pour utiliser un pointeur de fonction la signature de la fonction doit être la même que celle du pointeur
*/

typedef int (*pointeurDeFonction3)(int,int);

int addition(int nb1, int nb2)
{
    return nb1 + nb2;
}

int soustraction(int nb1, int nb2)
{
    return nb1 - nb2;
}

int calculer(int nombre1, int nombre2, int (*pointeurFontcion)(int, int))
{
    pointeurFontcion(nombre1, nombre2);
}

int main(void)
{
    int a = 14;
    int b = 28;
    int res2 = 0;
    int res3 = 0;

    /* Utiliser une fonction intermédiaire */
    afficher("Utiliser une fonction intermediaire:\n");

    int res = calculer(a,b,&addition);

    afficher("addition : %d\n", res);

    res = calculer(a,b,&soustraction);

    afficher("soustraction : %d\n", res);

    /* Créer directement un poiteur de fonction */
    afficher("Creer directement un pointeur de fonction:\n");

    int (*pointeurDeFonction2)(int, int);

    pointeurDeFonction2 = addition;

    res2 = pointeurDeFonction2(5,10);

    afficher("addition : %d\n", res2);

    /* Définition d' un type de donnée utilisant un pointeur de fonction */
    afficher("Definition d' un type de donnee utilisant un pointeur de fonction:\n");

    pointeurDeFonction3 tableauFonctionsCalcul[2];

    tableauFonctionsCalcul[0] = &addition;
    tableauFonctionsCalcul[1] = &soustraction;

    res3 = tableauFonctionsCalcul[1](126, 34);

    afficher("soustraction : %d\n", res3);

    return 0;
}