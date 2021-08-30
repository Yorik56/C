#include <stdio.h>
#define afficher printf

/*
    EXERCICE C #1
    [Révision : affichage/saisie, variables]
    > Écrire un programme qui demande un nombre entier à l' utilisateur
    et affiche la valeur de la saisie en octal ou en hexadécimal

    > Indications :
     - Formater en octal        -> %o
     - Formater en hexadécimale -> %x ou %X
*/

/*

   ->OCTAL:
   174 | 8
   --------
     6 | 21 | 8
         -------
         5  | 16 | 8
              -------
              0  | 2

    ->HEXADECIMAL:
    174 | 16
    ------
     14 | 10 | 16
          ------
          10 | 0

*/

void convertionEntier(int n)
{
    afficher("octal : %o | hexadecimal : %x\n", n , n);
}

int main(void)
{
    int number = 0;
    afficher("Entrez un nombre entier : ");
    scanf("%d", &number);
    convertionEntier(number);

    return 0;
}