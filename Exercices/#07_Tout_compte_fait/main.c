#include <stdio.h>
#include <stdlib.h>
#define afficher printf

/*
    [Révisions  : jusqu' à la séance 13 - chaînes de caractères]
    1> Écrire une fonction qui compte le nombre de caractères d' une chaîne (comme strlen de <string.h>)
    2> Écrire une fonction qui compte le nombre d' occurences d'un caractère dans une chaîne

    Indications :
    - pour la partie n°2, vous utiliserez la fonction écrite en partie n°1.
    - pensez à mettre vos variables en lecture seule constantes (ex : const int myData = 10).
*/

/*Fonctions*/
int str_length(const char *chaine)
{
    int i = 0;

    while(chaine[i] != '\0')
    {
        i++;
    }


    return i;
}
int count_occurences_of(const char e, const char *chaine)
{
    int occurrences = 0;

    for (int i = 0; i < str_length(chaine); ++i) {
        if(chaine[i] == e)
            occurrences++;
    }

    return occurrences;
}

int main(void)
{
    char chaine[] = "Bonjour tout le monde, je suis en train de faire des exercice pour reviser les chaines de caracteres";
    char e = 'e';
    /*Taille de chaine*/
    afficher("Taille de chaine : %d\n",str_length(chaine));
    afficher("Nombre occurences : %d", count_occurences_of(e, chaine));
    return 0;
}