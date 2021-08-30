#include <stdio.h>
#define afficher printf

/*

    [Déclaration tableau]
        <type> <nom_tableau>[X]; //Déclare avec valeurs aléatoires
    [Déclaration tableau]
        tableau[5] = {valeur1, valeur2, valeur3, valeur4, valeur5}
        tableau[5] = {0}; //Toutes les cases valent 0
        tableau[5] = {4}; //Première case vaut 4, les autres valent 0
    [Accès au tableau]
        tableau[X] : élément d' indice X (X+1ème élément du tableau)

        tableau          : adresse du tableau
        *tableau         : premier élément du tableau
        *(tableau + X)   : élément d' indice X

        (NOTE)
            tableau[5] revient au même que d' écrire *(tableau + 5)
 */

#define TAILLE_TAB 5

void afficher_tableau(int tab[], int taille);
int *creer_tableau();

/*---------------------------------------------------------------*/

int main(void)
{
    //VARIABLE? TABLEAUX
    int *tableau = creer_tableau();

    //AFFICHAGE
    afficher_tableau(tableau, TAILLE_TAB);
    afficher("\n\n");

    //NOUVELLES VALEURS
    tableau[2] = -5;

    //AFFICHAGE
    afficher_tableau(tableau, TAILLE_TAB);
    afficher("\n Adresse du tableau => [%p] ", tableau);


    return 0;
}

/*---------------------------------------------------------------*/

int *creer_tableau(){
    static int tableau_entiers[TAILLE_TAB];
    int compteur;

    for (int compteur = 0; compteur < TAILLE_TAB; ++compteur) {
        tableau_entiers[compteur] = compteur * 3;
    }

    return tableau_entiers;
}

/*---------------------------------------------------------------*/

void afficher_tableau(int tab[], int taille){
    for (int compteur = 0; compteur < taille ; compteur++)
        afficher("%d => [%d] ", compteur, tab[compteur]);
}

