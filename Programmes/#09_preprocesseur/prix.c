#include <stdio.h>
#include "bibliotheque.h"
#define TVA 20

void bonjour(void)
{
    printf("Bonjour !!!\n");
}

int get_prix_ttc(int ht)
{
    int prixTTC = ht + (ht * TVA / 100);
}