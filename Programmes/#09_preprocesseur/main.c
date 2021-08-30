#include <stdio.h>
#include "bibliotheque.h"

#define afficher printf

/*
    Constantes prédéfinies du language C :
        __FILE__ (nom du fichier source)
        __LINE__ (Ligne du fichier)
        __DATE__ (Date de compilation)
        __TIME__ (Heure de compilation)
*/
int main(void)
{
    int prixHT = 15;
    int prixTTC = get_prix_ttc(prixHT);

    afficher("Bonjour !\n");
    afficher("Nom du fichier : %s\n", __FILE__);
    afficher("Ligne du fichier : %d\n", __LINE__);
    afficher("Date de compilation : %s\n", __DATE__);
    afficher("Heure de compilation : %s\n", __TIME__);
    afficher("PrixHT = %d\n", prixHT);
    afficher("PrixTTC = %d\n", prixTTC);

    return 0;
}