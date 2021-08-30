#include <stdio.h>
#include <string.h>
#define afficher printf
#define demander scanf_s

/*
    ['J']
    ['a']
    ['s']
    ['o']
    ['n']
    ['\0'] // Caractère de fin de chaîne

    [Fonction des chaînes]
        strcpy()  : copie une chaîne dans une autre
        strlen()  : renvoie la longueur d' une chaîne (sans le caractère de fin de chaîne: \0)
        strcmp()  : comparer deux chaînes (lexicographiquement)
        strcat()  : concaténer deux chaînes
        strstr()  : chercher une chaîne dans une autre
        strchr()  : chercher la 1ère occurence d' un caractère
        sprintf()  : écrire dans une chaîne
*/
int main(void)
{

    signed char mot[] = "Patate";                   // Tableau de caractères avec un nombre de caractères variable
    //signed char mot[] = "Bonjour tout le monde !!!!"; /!\ interdit on à déjà définit l' allocation mémoire du  tableau de caractère
    signed char mot2[6] = "Jason";                  // Tableau de caractères avec un nombre de caractères défini
    //signed char mot2[6] = {"J","a,","s","o","n"}; //même résultat
    signed char mot3[] = "John et ";                // Tableau de caractères avec un nombre de caractères variable
    char n = 'n';
    char prenom[6] = "Jason";
    char stockage[256];


    afficher("mot: %s\n", mot);
    afficher("mot2: %s\n", mot2);
    afficher("Prénom recherché: %s\n", mot2);
    afficher("Ton prénom: %s\n", prenom);
    afficher("Changer ton prénom ?");

    demander("%s", stockage);
    strcpy(prenom, stockage);

    afficher("Ton nouveau prénom: %s\n", prenom);
    afficher("Taille de la chaîne :%d\n", strlen(prenom));

    int test = strcmp(mot, prenom);
    afficher("Comparaison lexicographique: ");
    if(test == 0)
        afficher("Les deux chaines sont identiques.\n");
    else if (test < 0)
        afficher("%s < %s\n", mot, prenom);
    else if (test > 0)
        afficher("%s > %s\n", mot, prenom);

    afficher("Concatenation: %s\n", strcat(mot3,prenom)); // Le contenu de la chaîne prénom est ajouté à la chaîne mot3

    afficher("Recherche d\'une occurence: ");
    if(strstr(prenom, mot2))
        afficher("On a trouvé Jason !\n");
    else
        afficher("Jason n' est pas ici ...\n");

    char *resultat = strchr(mot3, n); //On stock la localisation de l'occurence dans un pointeur
    afficher("Recherche de la position d\'une chaine : %s\n", resultat);

    afficher("Affichage d\'une chaine stockée dans une variable: ");
    sprintf(stockage, " un test ", 9);
    afficher("%s\n", stockage);

    return 0;
}