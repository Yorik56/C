#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*
    [Révision : jusqu' à la séance 15 - Allocation dynamique mémoire]

    Votre programme doit permettre de créer une matrice d' entiers ( de X lignes et Y colonnes )

    <> Le programme s' exécutera en plusieurs étapes :
        - Création de la matrice
        - Remplissage des valeurs
        - Affichage
        - Destruction

    Indications :
        - la taille voulue pour la matrice est saisie par l' utilisateur
        - la matrice est remplie de valeurs par ce dernier

*/

int main(void)
{
    int **matrix = NULL;
    int rows;
    int columns;
    int i, j;

    afficher("Taille de la matrice (format : <rows> <columns>)\n");
    scanf("%1d %1d", &rows, &columns);

    afficher("Lignes %d - Colonnes %d\n", rows, columns);

    matrix = malloc( rows * sizeof (int*));

    if(matrix == NULL)
        exit(1);

    /*Allocation de la matrice*/
    for (int i = 0; i < rows; ++i) {
        matrix[i] = malloc(columns * sizeof(int));

        if(matrix[i] == NULL)
            exit(1);
    }


    /*Remplissage de la matrice*/
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            afficher("Valeur pour [%d][%d] ?", i, j);
            scanf("%2d", &matrix[i][j]);
        }
    }

    /*Affichage de la matrice*/
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            afficher("[%d][%d] = %d\n", i, j, matrix[i][j]);
        }
    }

    /*Libération de la matrice*/
    for (int i = 0; i < rows; ++i) {
        free(matrix[i]);
        matrix[i] = NULL;
    }

    free(matrix);

    return 0;
}