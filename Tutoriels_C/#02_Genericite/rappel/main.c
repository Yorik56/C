#include <stdio.h>
#define afficher printf

/*
    Généricité : Manipuler des données de tout type possible
*/

int main(void)
{
    void *pointeurGenerique = NULL;
    int nombreA = 5;
    double autreNombre = 3.14;

     /* RAPPEL */

    int *pointeurSurEntier = NULL;
    int nombreB = 5;

    pointeurSurEntier = &nombreB;

    afficher("%d\n", *pointeurSurEntier);

    /* -------------------------- */

    pointeurGenerique = &nombreA;

    afficher("%p\n", pointeurGenerique);

    return 0;
}