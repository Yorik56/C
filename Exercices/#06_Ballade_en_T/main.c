#include <stdio.h>
#include <stdlib.h>
#include "game.h"
#define afficher printf

/*

    01234567890123456789
    x  x  x  x  x  x  x  x
      [ ][ ][ ][ ][ ][ ]

 ////////////////////////////
  [] -> 2,4,5,7,8,10,11,13,14,16,17,19



    O  O  O  O
    O [T][ ] O
    O [ ][ ] O
    O  O  O  O

    O  O  O  O
    O [ ][T] O
    O [ ][ ] O
    O  O  O  O

    [ ÉNONCÉ ]
        Un menu demande largeurs X et Longueurs Y d' une map
        On génère la map
        Le joueur "T" est placé en haut à gauche de la map
        On affiche l' espace de jeux
        On affiche un menu dans le terminal qui permet :
            - de simuler un système de déplacement:
                - haut   : U
                - droite : R
                - bas    : D
                - gauche : L

                On déplace le joueur sur la map puis on la ré-affiche

            - de modifier la taille de la map:
                - On génère la map
                - Le joueur "T" est placé en haut à gauche de la map

    [ INDICATIONS ]
        "T" ne peut pas accéder aux limites "O"
        "T" peut se déplacer de cases en cases "[]"
        espace de jeu de X x Y cases
        tableau [Xx2][Yx2]

    [ "CLEAR SCREEN" ]
        system("clear") pour Linux
        system("cls") pour Windows -> Compiler en Admin

*/



int main(void)
{
    app_start();
    return 0;
}

