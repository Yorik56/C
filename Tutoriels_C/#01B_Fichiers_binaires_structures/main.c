#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*

*/

typedef struct
{
    int posX;
    int posY;
}Position;

int main(void)
{
    FILE *fic;
    Position po;

    po.posX = 100;
    po.posY = 25;

    fic = fopen("save.bin", "wba");

    if(fic == NULL)
    {
        fprintf(stderr, "Erreur ouveture fichier;\n");
        exit(EXIT_FAILURE);
    }

    fwrite(&po, sizeof(po), 1, fic);

    rewind(fic);

    fread(&po, sizeof(po), 1, fic);

    afficher("X = %d | Y = %d\n", po.posX, po.posY);

    fclose(fic);

    return 0;
}