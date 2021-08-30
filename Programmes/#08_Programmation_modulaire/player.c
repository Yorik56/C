#include <stdio.h>
#include "player.h"

void bonjour(void)
{
    printf("Bonjour :) !\n ");
}

int reset_niveau(void)
{
    int niveau;
    niveau = 0;
    return niveau;
}

int augmente_niveau(void)
{
    int niveau = 0;

    niveau += 2;
     return niveau;
}

int augmente_niveau_static(void)
{
    static int niveau = 0;

    niveau += 2;
     return niveau;
}