#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
/* Variable -> errno */
/* strerror -> (<code>>) */
#define afficher printf

/*

*/

int main(void)
{
    /* Rappel */
    int *ptr_entier;

    /* Retour de fonction */
    int nb1, nb2;
    int ret = 0;

    /* Utilisation de errno */
    errno = 0;
    FILE *fic;


    /*----------------------------------*/
    /* Rappel */
    if((ptr_entier = malloc(sizeof(int))) == NULL)
    {
        afficher("Erreur allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    free(ptr_entier);

    /*----------------------------------*/

    afficher("Entrez deux nombres: \n");
    ret = scanf("%d %d", &nb1, &nb2);

    if(ret == 2)
    {
        afficher("Nb1 = %d - Nb2 = %d\n", nb1, nb2);
        afficher("RET = %d\n", ret);
    }
    else
    {
        afficher("Erreur de saisie ! \n");
    }

    /*----------------------------------*/

    fic = fopen("truc.txt", "r");

    if(fic == NULL)
    {
        perror("Erreur");
        fprintf(stderr, "Probleme ouverture de fichier: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    fclose(fic);

    return 0;
}