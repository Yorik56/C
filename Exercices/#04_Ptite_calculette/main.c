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
    unsigned int choix = 0;
    int nombreA, nombreB, state = 0;

    do
    {
        afficher("<CALCULETTE>\n");
        afficher("Addition: 1\nSoustraction: 2\nMultiplication: 3\nDivision: 4\nQuitter: 5\nChoisissez une operation:\n");

        if(choix < 1 || choix > 5)
        {
            do
            {
                afficher("Merci de saisir un nombre compris entre 1 et 5: ");
                scanf("%d", &choix);
            } while (choix < 1 || choix > 5);
        }

        else if(choix >=1 && choix <=4){

            int result;

            do
            {
                afficher("Saisissez un nombre A compris entre 1000 et -1000: ");
                scanf("%d", &nombreA);
            } while (validation_entree(nombreA) != 0);

            do
            {
                afficher("Saisissez un nombre B compris entre 1000 et -1000: ");
                scanf("%d", &nombreB);
            } while (validation_entree(nombreB) != 0);

            char *nom_operation;
            nom_operation = affiche_nom_operation(choix);

            afficher("%s des nombre %d et %d.\n",nom_operation,  nombreA, nombreB);

            result = appel_calcul(choix, nombreA, nombreB);

            afficher("Le resultat est: %d\n\n\n", result);

            choix = 0;
        }
        else if (choix == 5)
        {
            state = 1;
        }
    } while (state == 0);




    return 0;
}