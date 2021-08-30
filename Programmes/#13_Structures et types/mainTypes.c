#include <stdio.h>
#define afficher printf

/*

*/


//ENUMERATION
typedef enum Boolean {
    false,//0
    true //1
} Boolean;

typedef enum MarqueVoiture {
    PEUGEOT = 10,
    RENAULT = 20,
    TOYOTA = 30,
    MAZDA = 40
} Marque;
//UNION

union Nombre{
    int entier;
    float decimal;
};


/*--------------------------------------------*/

int main(void)
{
    Boolean jeu_lance = false;
    Marque voiture1 = TOYOTA;

    afficher("enum \"jeu_lance\":  %d\n", jeu_lance);
    afficher("enum \"voiture1\":  %d\n", voiture1);

    //*********************************************************************************

    union Nombre nb1;

    nb1.entier = 3;
    nb1.decimal = 3.14;

    afficher("union \"nb1.entier\":  %d\n", nb1.entier);
    afficher("union \"nb1.decimal\":  %f\n", nb1.decimal);

    return 0;
}