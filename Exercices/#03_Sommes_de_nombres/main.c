#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*
    [Révisions boucles]
    > écrire un programme qui calcule la somme des entiers d' un
    nombre à un autre (maximum : entre 1 et 1000)

    > Indications :
        - prévoir le cas où "min" serait plus grand que "max" et quitter
        le programme si cela arrive.

        - prévoir le cas où "min" serait plus petit que 1 et "max" plus grand
        que 1000.

*/

int calcul_somme(int min, int max);

int main(void)
{
    unsigned int min = 0;
    unsigned int max = 0;
    unsigned int somme;

    afficher("Entrez un nombre minimum compris entre 1 et 1000\n");
    scanf("%d", &min);

    afficher("Entrez un nombre maximum compris entre 1 et 1000\n");
    scanf("%d", &max);

    somme = calcul_somme(min, max);

    afficher("La somme des nombres compris entre : %d et %d, \nest de: %d\n", min, max, somme);


    return 0;
}

int calcul_somme(int min, int max)
{

    int result = 0;
    int compteur;
    int tmp;

    if(min > max || min < 1 ||  max > 1000){
        fprintf(stderr, "Erreur: valeurs entrees incorrectes.\n");
        exit(EXIT_FAILURE);
    }

    for (compteur = min; compteur < max + 1 ; ++compteur) {
        if (compteur == min)
        {
            tmp = min;
        }
        else
        {
            afficher("-> %d + %d = ", tmp, compteur);
            result = tmp + compteur;
            tmp = result;
            afficher("%d\n", result);
        }

    }

    return result;
}


