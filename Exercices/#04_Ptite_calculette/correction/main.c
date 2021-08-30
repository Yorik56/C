#include <stdio.h>
#include "calculette.h"
#include <string.h>

#define afficher printf

/*
    [Révisions jusqu' a la programmation modulaire]
    > Écrire un programme de calculatrice simple pour deux nombres :
        - afficher un menu principal proposant les 4 types de calcul (+, -, * et /) ou de quitter.
        - une fois le calcul choisi, demander la saisie des 2 nombres et afficher le résultat.
        - rediriger sur le menu principal

    > Indications :
        - utiliser un maximum des fonctions (pour optimiser le code et éviter les répétitions).
        - vérifier que la saisie au menu est correct, sinon redemander une saisie.
        - vérifier que les nombres saisis sont compris entre 1000 et -1000.
        - compiler avec la commande -> gcc *.c -o programme (donnera un  exécutable programme ou programme.exe)
*/



int main(void)
{
    app_calc();

    return 0;
}