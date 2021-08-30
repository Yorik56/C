#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*
    fopen(<fichier>,<mode_lecture>) :
        r  (lecture seule, doit exister)
        w  (écriture seule)
        a  (ajout, fin de fichier)
        r+  (lecture/écriture, doit exister)
        w+  (lecture/écriture, supprime contenu)
        a+  (ajout lecture/écriture, fin de fichier)

    fclose(<fichier>) : fermer un fichier ouvert
    feof(<fichier>)   : tester la fin d' un fichier

    [LECTURE]
        fgetc (<fichier>)                          : lire un caractère
        fgets (<chaine>,<taille_chaine>,<fichier>) : lit une ligne
        fscanf(<fichier>,<format>, ...)            : lit du texte formaté

    [ECRITURE]
        fputc(<caractère>, <fichier>)              : écrit un caractère
        fputq(<chaine>, <fichier>)                 : écrit une chaine
        fprintf(<fichier>,<format>, ...)           : écrit du texte formaté

    [POSITIONNEMENT]
        ftell(<fichier>) : retourne position curseur dans le fichier

        fseek(<fichier>,<deplacement>,<origine>) : déplace le curseur
            -> <origine> :
                SEEK_SET (début du fichier)
                SEEK_CUR (position du curseur)
                SEEK_SET (fin de fichier)

        rewind(<fichier>) : réinitialisation de la position du curseur

    [DIVERS]
        rename(<ancien_nom>,<nouveau_nom>) //NE FONCTIONNE PAS SUR UN FICHIER OUVERT
        remove(<fichier>) //FICHIER IRRÉCUPÉRABLE PAR LA CORBEILLE

*/

int main(void)
{

    char mot[] = "Bonjour\n";
    char pseudo[] = "Naoki";
    int age = 28;
    int abonnes = 1000;


    FILE *fichier = fopen("ecriture.txt","w");
    if(fichier == NULL)
        exit(1);

    /*-----------------------------*/ /*FPUTC*/
    fputs("-->fputc()\n", fichier);
    fputc('J', fichier);
    fputc('\n', fichier);

    /*-----------------------------*/ /*FPUTS*/
    fputs("-->fputs()\n", fichier);
    fputs(mot, fichier);

    /*-----------------------------*/ /*FPRINTF*/
    fputs("-->fprintf()\n", fichier);
    fprintf(fichier, "%d %s %d", age, pseudo, abonnes);


    fclose(fichier);

    return 0;
}