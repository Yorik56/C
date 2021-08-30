#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*
    sizeof(<donnee>)                      : retourne la taille en octets d' une donnée
    malloc(<Taille en Octets>)            : allouer dynamiquement une zone mémoire
    free(<donnee_allouée>                 : libérer la mémoire allouée dynamiquement
    calloc(<donnee>, <taille_en_octets>)  : alloue et initialise tout à zéro
    realloc(<donnee, <nouvelle_taille>)   : réalloue un espace mémoire
*/

int main(void)
{
    //***********************************************************************************************//
    //malloc
    afficher("[malloc]\n");

    int nombreJoueurs = 0;
    int *liste_joueurs = NULL;
    int compteur;

    afficher("Combien de joueurs ?\n");
    scanf("%d", &nombreJoueurs);

    liste_joueurs = malloc(sizeof(int) * nombreJoueurs);

    if(liste_joueurs == NULL)
        exit(1);

    for (compteur = 0; compteur < nombreJoueurs; ++compteur) {
        afficher("Joueur %d -> numero %d\n", compteur + 1, compteur * 3);
        liste_joueurs[compteur] = compteur * 3;
    }

    for (int compteur = 0; compteur < nombreJoueurs; ++compteur) {
        afficher("[%d] ", liste_joueurs[compteur]);
    }

    afficher("\n");
    afficher("Adresse de la liste de joueurs : %p", liste_joueurs);
    afficher("\n");
    afficher("\n");

    free(liste_joueurs);

    //***********************************************************************************************//
    //calloc
    afficher("[calloc]\n");
    int nombreJoueurs2 = 0;
    int *liste_joueurs2 = NULL;
    int compteur2;

    afficher("Combien de joueurs ?\n");
    scanf("%d", &nombreJoueurs2);

    liste_joueurs2 = calloc(nombreJoueurs2, sizeof(int));

    if(liste_joueurs2 == NULL)
        exit(1);

    for (compteur2 = 0; compteur2 < nombreJoueurs2; ++compteur2) {
        afficher("[%d] ", liste_joueurs2[compteur2]);
    }

    afficher("\n");
    afficher("Adresse de la liste de joueurs : %p", liste_joueurs2);
    afficher("\n");
    afficher("\n");

    /*-----------------------*/
    //realloc
    afficher("[ralloc]\n");
    nombreJoueurs2 = 7;

    liste_joueurs2 = realloc(liste_joueurs2, nombreJoueurs2 * sizeof(int));

    if(liste_joueurs2 == NULL)
        exit(1);

    for (compteur2 = 0; compteur2 < nombreJoueurs2; ++compteur2) {
        afficher("Joueur %d -> numero %d\n", compteur2 + 1, compteur2 * 3);
        liste_joueurs2[compteur2] = compteur2 * 3;
    }

    for (int compteur2 = 0; compteur2 < nombreJoueurs2; ++compteur2) {
        afficher("[%d] ", liste_joueurs2[compteur2]);
    }

    afficher("\n");
    afficher("Adresse de la liste de joueurs : %p", liste_joueurs2);
    afficher("\n");
    afficher("\n");

    free(liste_joueurs2);

    return 0;
}