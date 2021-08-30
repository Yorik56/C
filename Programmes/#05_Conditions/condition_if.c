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
    int age = 375;
    int il_a_375_ans = -1;

    if(age < 1){
        printf("Tu n'es pas né.\n");
    } else if(age >= 1 && age <= 100 || age == 375) {
        printf("Tu as un age compris entre 1 et 100 ans ou 375 ans \n");
    } else {
        printf("Wah, tu as plus de 100 ans !!! \n");
    }

    // TERNAIRE
    (age == 375) ? printf("Tu as 375 ans.\n") : printf("Tu n'as pas 375 ans.\n");

    il_a_375_ans = (age == 375) ? 1 : 0;

    printf("Il a 375 ans = %d\n", il_a_375_ans);
    return 0;
}