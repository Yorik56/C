#include <stdio.h>
#include "player.h"

int main(void)
{
    int level = 15;
    printf("Niveau actuel : %d\n", level);

    level = reset_niveau();
    printf("Niveau après reset : %d\n", level);

    printf("Niveau augmenté : %d\n", augmente_niveau());
    printf("Niveau augmenté : %d\n", augmente_niveau());
    printf("Niveau augmenté : %d\n", augmente_niveau());

    printf("Niveau augmenté static : %d\n", augmente_niveau_static());
    printf("Niveau augmenté static : %d\n", augmente_niveau_static());
    printf("Niveau augmenté static : %d\n", augmente_niveau_static());

    return 0;
}


