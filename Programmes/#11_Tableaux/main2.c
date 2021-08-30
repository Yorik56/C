#include <stdio.h>
#define afficher printf

/*

    CREER UNE TABLEAU A DEUX DIMENSIONS

*/

#define NOMBRE_COLONNES 5
#define NOMBRE_LIGNES   5

int main(void)
{
    int damier[NOMBRE_COLONNES][NOMBRE_LIGNES] = {
            {1,2,3,4,5},
            {6,7,8,9,10},
            {11,12,13,14,15},
            {16,17,18,19,20},
            {21,22,23,24,25}
    };

    for (int i = 0; i < NOMBRE_COLONNES; ++i) {
        for (int j = 0; j < NOMBRE_LIGNES; ++j) {
            afficher("[%d]",damier[i][j]);
        }
        afficher("\n");
    }
    return 0;
}