#include <stdio.h>

int main(void)
{
    int aireDuCarre = 0;
    float prixReservation = 125.99;
    int prixReservation_entier = (int)prixReservation;
    signed char numéroASCII = 65;
    signed char lettre = 'A';
    const float PI = 3.14;
    //    CPU
    register int nombre = 5;
    //    RAM, Périphériques
    volatile int autreNombre = 8;

    /*
        %d : nombre entier        (int)
        %f : nombre flottant      (float)
        %c : caractère            (char)
        %s : chaîne de caractères (texte)
     */
    printf("Le prix de réservation est: %d ou %.2f\n", prixReservation_entier, prixReservation);
    printf("PI = %.2f", PI);
    return 0;
}