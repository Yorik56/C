#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*

*/

int main(void)
{

    /*Écriture*/
    afficher("Ecriture\n");
    FILE *fic;
    int positionX = 145;
    int positionY = 86;

    fic = fopen("save.bin", "wba");

    if(fic == NULL)
    {
        fprintf(stderr, "Erreur ouveture fichier;\n");
        exit(EXIT_FAILURE);
    }

    fwrite(&positionX, sizeof(int), 1, fic);
    afficher("Position curseur : %d\n", ftell(fic));
    fwrite(&positionY, sizeof(int), 1, fic);
    afficher("Position curseur : %d\n", ftell(fic));

    /*Lecture*/
    afficher("Lecture\n");
    afficher("Position curseur : %d\n", ftell(fic));
    rewind(fic); /* rewind(<fichier>) : réinitialisation de la position du curseur */
    afficher("Position curseur : %d\n", ftell(fic));
    int posX;
    int posY;

    fic = fopen("save.bin", "rb");

    if(fic == NULL)
    {
        fprintf(stderr, "Erreur ouveture fichier;\n");
        exit(EXIT_FAILURE);
    }

    fread(&posX, sizeof(int), 1, fic);
    afficher("Position curseur : %d\n", ftell(fic));
    fread(&posY, sizeof(int), 1, fic);
    afficher("Position curseur : %d\n", ftell(fic));

    afficher("Position du joueur (x/y) = (%d/%d)\n", posX, posY);

    fclose(fic);

    return 0;
}