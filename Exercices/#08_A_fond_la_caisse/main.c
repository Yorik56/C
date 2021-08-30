#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define afficher printf

/*
    [Révision : jusqu' à la séance 14 - structure et types]
    1> Créer un type de voiture qui possède les informations suivantes :
        - Son nom de marque
        - Son nom de modèle
        - Sa réserve de gazole/essence (en pourcentage)
        - Sa vitesse de déplacement max
        - Son état (fonctionnel ou en panne)
    2> Définir une fonction pour créer un Véhicule, qui nécessite d' indiquer :
        - Sa marque, son modèle et sa vitesse max.
        - Pour la réserve, vous choisirez une valeur arbitraire (par défaut)
        - pour l' état, le Véhicule sera par défaut "fonctionnel".
    3> Définir une fonction afficher les informations du Véhicule

    Indications :
        - l' état du véhicule sera à définir via une énumération.
        - les données textuelles seront stockées par défaut dans une chaîne,
        de taille max de 256 caractères.

*/

typedef enum{
    FONCTIONNEL,
    EN_PANNE
}Etat;

typedef struct  Vehicle
{
    char marque[256];
    char modele[256];
    int reserve;
    int vitesse_max;
    Etat sante;
}Vehicle;


Vehicle vehicle_create(char *marque, char *modele, int vitesse_max);
void vehicle_info(Vehicle v);

int main(void)
{
    Vehicle v1;

    v1 = vehicle_create("Peugeot", "206", 140);

    vehicle_info(v1);

    return 0;
}

Vehicle vehicle_create(char *marque, char *modele, int vitesse_max)
{
    Vehicle v;
    strcpy(v.marque, marque);
    strcpy(v.modele, modele);
    v.reserve = 100;
    v.vitesse_max = vitesse_max;
    v.sante = FONCTIONNEL;

    return v;
}

void vehicle_info(Vehicle v)
{
    afficher("Marque      : %s\n", v.marque);
    afficher("Modele      : %s\n", v.modele);
    afficher("Reserve     : %d%%\n", v.reserve);
    afficher("Vitesse Max : %dKm/h\n", v.vitesse_max);
    if(v.sante == FONCTIONNEL)
        afficher("Vehicule neuf !\n");
    else
        afficher("Vehicule en panne...\n");
}