#include <stdio.h>

int main(void)
{
    /*
        == : égal à
        != : différent de
        <  : plus petit que
        >  : plus grand que
        <= : plus petit ou égal à
        >= : plus grand ou égal à

        && : Et
        || : OU
        !  : NOT
    */
    int age = 15;

    switch(age)
    {
        case 0:
            printf("Tu as 0 an\n");
            break;
        case 15:
            printf("Tu as 15 ans\n");
            break;
        default:
            printf("Ton age n'est pas prévu dans notre système");
            break;
    }


    return 0;
}