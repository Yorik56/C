#ifndef CALCULETTE_H
#define CALCULETTE_H

/* Prototypes */

void show_menu(void);
void do_operation(int choix);
void app_calc(void);

/* Fonctions de calcul */
int addition(int nombreA, int nombreB);
int soustraction(int nombreA, int nombreB);
int multiplication(int nombreA, int nombreB);
int division(int nombreA, int nombreB);


#endif