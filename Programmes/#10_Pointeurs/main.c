#include <stdio.h>
#define afficher printf

/*
    Pointeur : variable contenant l'adresse d'une autre variable
    %p -> affiche une adresse de variable ou de pointeur
    %d -> affiche une valeur d'entier d'une variable ou d'un pointeur

    [VARIABLES]
        maVariable  : valeur de la variable
        &maVariable : adresse de la variable

    [POINTEURS]
        // déclaration et initialisation d'un pointeur
        *monPointeur = NULL ou *monPointeur = &maVariable

        // Utilisation du pointeur
        *monPointeur : valeur de la variable pointée
        monPointeur  : adresse de la variable pointée
        &monPointeur : adresse du pointeur
*/

void inverser_nombres(int *pointeur_nombreA, int *pointeur_nombreB)
{
    int temporaire = 0; //B

    temporaire = *pointeur_nombreB;
    *pointeur_nombreB = *pointeur_nombreA;
    *pointeur_nombreA = temporaire;
}

void change_nombre(int *nombre)
{
    *nombre = 15;
}

int main(void)
{
    // Déclaration et initialisation de variables
    int nombreA = 15;
    int nombreB = 28;
    int nombre = 0;

    // Création et initialisation de pointeurs
    int *pointeurSurNombreA = &nombreA;
    int *pointeurSurNombreB = &nombreB;
    int *pointeur_nombre = &nombre;

    //DEBUG
    afficher("1) VALEUR DE 'nombreA' : %d\n", nombreA);
    afficher("2) ADRESSE DE 'nombreA' : %p\n", &nombreA);
    afficher("3) VALEUR DE LA VARIABLE 'nombreA' POINTEE PAR 'pointeurSurNombreA' : %d\n", *pointeurSurNombreA);
    afficher("4) ADRESSE DE LA VARIABLE 'nombreA' POINTEE PAR 'pointeurSurNombreA' : %p\n", pointeurSurNombreA);
    afficher("5) ADRESSE DU POINTEUR 'pointeurSurNombreA' : %p\n", &pointeurSurNombreA);

    //On passe les adresses des variables pointées à la fonction
    afficher("6) AVANT : A = %d et B = %d\n", nombreA, nombreB);
    inverser_nombres(pointeurSurNombreA,pointeurSurNombreB);  //Equivalent -> inverser_nombres(&nombreA,&nombreB);
    afficher("7) APRES : A = %d et B = %d\n", nombreA, nombreB);
    afficher("8) nombre avant : %d\n", nombre);
    change_nombre(pointeur_nombre);
    afficher("9) nombre apres : %d\n", nombre);

    return 0;
}
