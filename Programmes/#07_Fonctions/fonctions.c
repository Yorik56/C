#include <stdio.h>

//Prototype de fonction -> Attention un fonction "init_ball" existe !
int init_ball(int posX);
int bonjour(void);

int main(void)
{
    /*
        Exemples de fonctions :
            - printf() #Affiche des informations
            - scanf()  #Demande une information
    */
    int balleX;

    balleX = init_ball(balleX);
    printf("Avant la partie: %d.\n", balleX);

    balleX = 54;
    printf("Pendant la partie: %d.\n", balleX);
    int retour_bonjour = bonjour();
    printf("Retour : %d\n", retour_bonjour);

    // Déroulement de la partie...
    balleX = init_ball(balleX);
    printf("Après la partie: %d.\n", balleX);

    return 0;
}

int init_ball(int posX)
{
    posX = 150;
    return posX;
}

int bonjour(void)
{
    printf("Bonjour :)!\n");
    return 1;
}