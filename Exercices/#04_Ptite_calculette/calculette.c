#include <stdio.h>
#include <string.h>
#include "calculette.h"

#define afficher printf

/*
   Validation nombre saisi
   (Doit être compris en 1000 et -1000)
 */
int validation_entree(int nombre)
{
    if(nombre > 1000 || nombre < -1000)
    {
        if(nombre > 1000)
        {
            afficher("Ce nombre est plus grand que 1000.\n");
            return -1;
        }

        if(nombre < -1000){
                afficher("Ce nombre est plus petit que -1000.\n");
            return -1;
        }
    }

    return 0;
}

/*
    Appel de la fonction demandee
 */
int appel_calcul(int choix, int nombreA, int nombreB)
{
    int result = 0;

    switch (choix) {
        case 1:
            result = addition(nombreA, nombreB);
            break;
        case 2:
            result = soustraction(nombreA, nombreB);
            break;
        case 3:
            result = multiplication(nombreA, nombreB);
            break;
        case 4:
            result = division(nombreA, nombreB);
            break;
    }

    return result;

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
    return nombreA / nombreB;
}

/*------------------------*/

char* affiche_nom_operation(int choix)
{
    char *result;

    switch (choix) {
        case 1:
            result = "Addition";
            break;
        case 2:
            result = "Soustraction";
            break;
        case 3:
            result = "Multiplication";
            break;
        case 4:
            result = "Division";
            break;
    }

    return result;

}