#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*
    [Révision : jusqu'à la séance 16 - Fichiers ]
    > Un fichier texte contient des séquences de caractères alphabétiques (ex: AAAABBDDDDDDDDFEEEXXXXXP)
    > Chaque séquence de ce fichier devra être transformée et écrite dans un nouveau fichier :
        - Par exemple, les séquences "AAAABBXXXXXXX" deviendront "A4B2X7"
    > Testez ensuite votre programme avec les deux fichiers de données fournis (small_data + big_data)
        - Que remarquez-vous concernant les fichiers produits avec votre code ?
*/

int main(void)
{
    FILE *fichier     = fopen("big_data.txt","r");
    FILE *fichier2     = fopen("small_data.poti","w");

    if(fichier == NULL || fichier2 == NULL)
        exit(1);

    //-----------------------------------------------------------/

    char lettre, lettre_courante;
    int nbr_lettre_courante = 0;


    if((lettre_courante = fgetc(fichier)) != EOF){

        nbr_lettre_courante++;

        while((lettre = fgetc(fichier)) != EOF)
        {
            if(lettre_courante == lettre)
                nbr_lettre_courante++;
            else
            {
                afficher("%c%d", lettre_courante, nbr_lettre_courante);
                fprintf(fichier2, "%c%d", lettre_courante, nbr_lettre_courante);
                lettre_courante = lettre;
                nbr_lettre_courante = 1;
            }
        }
        afficher("%c%d", lettre_courante, nbr_lettre_courante);
        fprintf(fichier2, "%c%d", lettre_courante, nbr_lettre_courante);
        fclose(fichier);
        fclose(fichier2);
    }

    return 0;
}