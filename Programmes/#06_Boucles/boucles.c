#include <stdio.h>

int main(void)
{
    int compteur_while = 0;
    int compteur_do_while = 0;
    int compteur_for;

    //WHILE
    while(compteur_while < 20)
    {
        printf("%d) Alerte, les zombies nous envahissent !\n",compteur_while + 1);
        compteur_while ++;
    }
    //DO WHILE
    do
    {
        printf("%d) Ayaa !!\n",compteur_do_while + 1);
        compteur_do_while++;
    }
    while (compteur_do_while < 5);
    //FOR
    for(compteur_for = 0;compteur_for < 5; compteur_for++)
    {
        printf("%d) Ayaa (for) !!\n",compteur_for + 1);
    }


    return 0;
}