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
    FILE *fichier = fopen("lecture.txt","r");
    int lettre = 0;
    int age = 0;
    int nbr_abonnes = 0;
    signed char texte[256];

    if(fichier == NULL)
        exit(1);
    // POSITION CURSEUR
    afficher("Position curseur : %d\n", ftell(fichier));
    /*-----------------------------*/ /*FGETC*/
    afficher("-->fgetc() \n");
    while (1){
        lettre = fgetc(fichier); //EOF (end of file)
        if(feof(fichier))
            break;
        afficher("%c", lettre);
    }
    /*
        MÊME RÉSULTAT
        while ((lettre = fgetc(fichier)) != EOF){
            afficher("%c", lettre);
        }
    */
    afficher("\nPosition curseur : %d\n", ftell(fichier));

    /*-----------------------------*/ /*FGETS*/
    rewind(fichier);
    afficher("-->fgets() \n");
    while (fgets((char *)texte,255,fichier) != NULL)
        afficher("%s", texte);
    afficher("\nPosition curseur : %d\n", ftell(fichier));

    /*-----------------------------*/ /*FSCANF*/
    rewind(fichier);
    afficher("-->fscanf() \n");
    afficher("Position curseur : %d\n", ftell(fichier));
    fscanf(fichier,"%s %d %d", texte,  &age, &nbr_abonnes);
    afficher("Nom     : %s\n", texte);
    afficher("Age     : %d\n", age);
    afficher("Abonnes : %d\n", nbr_abonnes);
    afficher("Position curseur : %d\n", ftell(fichier));
    fscanf(fichier,"%s %d %d", texte,  &age, &nbr_abonnes);
    afficher("Nom     : %s\n", texte);
    afficher("Age     : %d\n", age);
    afficher("Abonnes : %d\n", nbr_abonnes);

    /*-----------------------------*/ /*POSITION CURSEUR*/
    afficher("-->position curseur \n");
    // POSITION CURSEUR
    afficher("Position curseur : %d\n", ftell(fichier));

    //DEPLACER CURSEUR
    fseek(fichier,5,SEEK_SET);
    afficher("Position curseur : %d\n", ftell(fichier));

    //RAZ
    rewind(fichier);
    afficher("Position curseur : %d\n", ftell(fichier));

    fclose(fichier);

    return 0;
}