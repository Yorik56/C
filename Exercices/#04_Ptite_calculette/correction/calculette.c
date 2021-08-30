#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "calculette.h"

#define afficher printf

void show_menu(void)
{
    afficher("<CALCULETTE>\n");
    afficher("Addition: 1\nSoustraction: 2\nMultiplication: 3\nDivision: 4\nQuitter: 5\nChoisissez une operation:\n");
    afficher("-----------------------------------------\n");
}

void app_calc()
{

    int choix = 0;

    do {
        show_menu();
        afficher(">");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                do_operation(choix);
                break;
            case 2:
                do_operation(choix);
                break;
            case 3:
                do_operation(choix);
                break;
            case 4:
                do_operation(choix);
                break;
            case 5:
                break;
            default :
                afficher("Option incorrecte !\n");
                break;
        }

    } while (choix != 5);

}

void do_operation(int choix)
{
    int nombreA = 0, nombreB = 0;
    int result = 0;

    do {
        afficher("Entrez un premier nombre: ");
        scanf("%d", &nombreA);

        afficher("Entrez un deuxieme nombre: ");
        scanf("%d", &nombreB);

        if(nombreA > 1000 || nombreA < -1000 || nombreB < -1000 || nombreB > 1000 )
            afficher("Saisie incorrecte, choisir un nombre entre -1000 et 1000.\n");
        else
        {
            if(choix == 1)  result = addition(nombreA, nombreB);
            else if(choix == 2) result = soustraction(nombreA, nombreB);
            else if(choix == 3) result = multiplication(nombreA, nombreB);
            else if(choix == 4) result = division(nombreA, nombreB);
            system("cls");
            afficher("Resultat du calcul = %d\n", result);
        }
    } while (nombreA > 1000 || nombreA < -1000 || nombreB < -1000 || nombreB > 1000);

}

/*-----------OPERATIONS-------------*/

/*
    Fonction: Addition
 */
int addition(int nombreA, int nombreB)
{
    return nombreA + nombreB;
}

/*
    Fonction: soustraction
 */
int soustraction(int nombreA, int nombreB)
{
    return nombreA - nombreB;
}

/*
    Fonction: multiplication
 */
int multiplication(int nombreA, int nombreB)
{
    return nombreA * nombreB;
}

/*
    Fonction: division
 */
int division(int nombreA, int nombreB)
{
    if(nombreB == 0)
    {
        afficher("Division par 0 impossible...");
        exit(-1);
    }

    return nombreA / nombreB;
}