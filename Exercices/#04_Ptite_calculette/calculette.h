#ifndef CALCULETTE_H
#define CALCULETTE_H

/* Fonction de vérification */
int validation_entree(int nombre);
char* affiche_nom_operation(int choix);

/* Fonctions de calcul */
int addition(int nombreA, int nombreB);
int soustraction(int nombreA, int nombreB);
int multiplication(int nombreA, int nombreB);
int division(int nombreA, int nombreB);

/* Autre */
int appel_calcul(int choix, int nombreA, int nombreB);


#endif